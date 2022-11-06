#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, k, cnt, up[sz], dn[sz], lf[sz], rt[sz], cum[505][505];

int main() {
   cin >> n >> k;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         int x;
         scanf("%d", &x);
         cnt += !dn[x];
         dn[x] = i, rt[x] = max(rt[x], j);
         if(!up[x]) up[x] = i;
         if(!lf[x]) lf[x] = j;
         else lf[x] = min(lf[x], j);
      }
   }

   if(cnt <= k) {
      cout << k - cnt;
      return 0;
   }

   k = cnt - k;
   int d = n * n;
   for(int r=1; r<=n; r++) {
      for(int v=1; v<=d; v++) {
         if(!dn[v]) continue;
         int x = rt[v] - lf[v] + 1, y = dn[v] - up[v] + 1;
         if(r < max(x, y)) continue;
         int j = max(lf[v] - (r - x), 1);
         int i = max(up[v] - (r - y), 1);
         int ej = lf[v] + 1;
         int ei = up[v] + 1;
         cum[i][j]++;
         cum[i][ej]--, cum[ei][j]--;
         cum[ei][ej]++;
      }
      for(int i=1; i<=n-r+1; i++) {
         for(int j=1; j<=n-r+1; j++) {
            int x = cum[i][j];
            if(x == k or x == k + 1) {
               puts("1");
               return 0;
            }
            cum[i][j] = 0;
            cum[i + 1][j] += x, cum[i][j + 1] += x;
            cum[i + 1][j + 1] -= x;
         }
      }
   }
   puts("2");
}