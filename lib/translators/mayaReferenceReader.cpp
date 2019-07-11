//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//

//
// Copyright 2017 Animal Logic
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.//
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "pxr/pxr.h"

#include <../fileio/primReaderRegistry.h>
#include <../fileio/translators/translatorMayaReference.h>
#include <../schemas/MayaReference.h>

#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usdGeom/camera.h"

#include <maya/MObject.h>

PXR_NAMESPACE_OPEN_SCOPE



PXRUSDMAYA_DEFINE_READER(AL_usd_MayaReference, args, context)
{
    const UsdPrim& usdPrim = args.GetUsdPrim();
    MObject parentNode = context->GetMayaNode(usdPrim.GetPath().GetParentPath(), true);
    return UsdMayaTranslatorMayaReference::update(
        usdPrim,
        parentNode);
}

PXR_NAMESPACE_CLOSE_SCOPE
