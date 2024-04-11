#include<bits/stdc++.h>
using namespace std;

#define N 100010

typedef long long LL;

int T, n;
LL xx, yy, zz, st, en, mid, x, y, z, w;
LL mnx, mny, mnz, mnw, mxx, mxy, mxz, mxw;
LL mnxx, mnyy, mnzz, mnww, mxxx, mxyy, mxzz, mxww;
const LL INF = 9e18;

bool calc(LL fg){
   if((1 & mnx) != fg && mnx == mxx) return 0;
   if((1 & mny) != fg && mny == mxy) return 0;
   if((1 & mnz) != fg && mnz == mxz) return 0;
   if((1 & mnw) != fg && mnw == mxw) return 0;
   x = mnx + ((mnx & 1) != fg);
   y = mny + ((mny & 1) != fg);
   z = mnz + ((mnz & 1) != fg);
   if(x + y + z > mxw) return 0;
   xx = mxx - ((mxx & 1) != fg);
   yy = mxy - ((mxy & 1) != fg);
   zz = mxz - ((mxz & 1) != fg);
   if(xx + yy + zz < mnw) return 0;

   if(x + y + z >= mnw) return 1;
   if(xx + y + z >= mnw){ x = mnw - y - z + ((mnw & 1) != fg); return 1; }  x = xx;
   if(x + yy + z >= mnw){ y = mnw - x - z + ((mnw & 1) != fg); return 1; }  y = yy;
   z = mnw - x - y + ((mnw & 1) != fg); return 1;
}

bool can(LL fg){
   if((1 & mnx) != fg && mnx == mxx) return 0;
   if((1 & mny) != fg && mny == mxy) return 0;
   if((1 & mnz) != fg && mnz == mxz) return 0;
   if((1 & mnw) != fg && mnw == mxw) return 0;
   x = mnx + ((mnx & 1) != fg);
   y = mny + ((mny & 1) != fg);
   z = mnz + ((mnz & 1) != fg);
   if(x + y + z > mxw) return 0;
   x = mxx - ((mxx & 1) != fg);
   y = mxy - ((mxy & 1) != fg);
   z = mxz - ((mxz & 1) != fg);
   if(x + y + z < mnw) return 0;
   return 1;
}

bool OK(){
   mnx = mnxx - mid, mxx = mxxx + mid; if(mnx > mxx) return 0;
   mny = mnyy - mid, mxy = mxyy + mid; if(mny > mxy) return 0;
   mnz = mnzz - mid, mxz = mxzz + mid; if(mnz > mxz) return 0;
   mnw = mnww - mid, mxw = mxww + mid; if(mnw > mxw) return 0;
   if(can(1)) return 1;
   return can(0);
}

int main(){
  // freopen("aaa.in", "r", stdin);

   for(scanf("%d", &T); T --; ){
      mxxx = mxyy = mxzz = mxww = INF;
      mnxx = mnyy = mnzz = mnww = -INF;
      scanf("%d", &n);
      for(int i = 0; i < n; i ++){
         scanf("%I64d %I64d %I64d", &xx, &yy, &zz);
         x = yy + zz - xx; mnxx = max(x, mnxx); mxxx = min(x, mxxx);
         y = xx - yy + zz; mnyy = max(y, mnyy); mxyy = min(y, mxyy);
         z = xx + yy - zz; mnzz = max(z, mnzz); mxzz = min(z, mxzz);
         w = xx + yy + zz; mnww = max(w, mnww); mxww = min(w, mxww);
      }
      st = -1, en = LL(3e18) + 1;
      while(st < en - 1){
         mid = (st + en) >> 1;
         if(OK()) en = mid;
         else st = mid;
      }
      mid = en;
      OK();
      if(!calc(0)) calc(1);
      printf("%I64d %I64d %I64d\n", (y + z) >> 1, (x + z) >> 1, (x + y) >> 1);
   }
}