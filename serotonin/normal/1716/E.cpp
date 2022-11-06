#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+7;

int a[sz], ara[sz];

struct dtt {
   ll sum, pref, suff, res;
} d[512][512], idk[512];

int main() {
   int b;
   cin >> b;
   int n = 1 << b;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int h = b >> 1, sml = 1 << h;
   for(int m=0; m<sml; m++) {
      for(int i=0; i<n; i++) ara[i] = a[i ^ m];
      for(int i=0, k=0; i<n; i+=sml, k++) {
         auto &dd = d[m][k];
         ll cum = 0, mn = 0;
         for(int j=0; j<sml; j++) {
            cum += ara[i + j];
            dd.res = max(dd.res, cum - mn);
            dd.pref = max(dd.pref, cum);
            mn = min(mn, cum);
         }
         cum = 0;
         for(int j=sml-1; j>=0; j--) {
            cum += ara[i + j];
            dd.suff = max(dd.suff, cum);
         }
         dd.sum = cum;
      }
   }

   int q, msk = 0, rem = n >> h;
   cin >> q;
   while(q--) {
      int kk;
      scanf("%d", &kk);
      msk ^= 1 << kk;

      int m = msk & sml - 1;
      memcpy(idk, d[m], sizeof(idk));

      for(int j=h, k=0; j<b; j++, k++) {
         for(int i=0; i<rem; i+=2<<k) {
            int x = i, y = i + (1 << k);
            if(msk & 1 << j) swap(x, y);
            dtt &now = idk[i];
            now.res = max({idk[x].res, idk[y].res, idk[x].suff + idk[y].pref});
            now.pref = max(idk[x].pref, idk[x].sum + idk[y].pref);
            now.suff = max(idk[y].suff, idk[y].sum + idk[x].suff);
            now.sum = idk[x].sum + idk[y].sum;
         }
      }
      printf("%lld\n", idk[0].res);
   }
}