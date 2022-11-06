#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7, mag = 1500;

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

int n, m, dx[sz], dy[sz], ans, res[sz];

int koi[sz], work[sz], dunno[sz+mag], cut[sz];
vector <int> st[sz];
unordered_map <int,int> cum[mag];

int main() {
   cin >> n >> m;
   for(int i=1; i<=n; i++) scanf("%d %d", &dx[i], &dy[i]);

   for(int t=1; t<=m; t++) {
      int op, k;
      scanf("%d %d", &op, &k);

      int z = dx[k] + dy[k];
      if(z < mag) {
         if(op == 1) {
            int beg = t + dx[k];
            cum[z][beg]++;
            cum[z][beg+dy[k]]--;
            koi[k] = beg;
         }
         else {
            int beg = koi[k];
            if(beg >= t) {
               cum[z][beg]--;
               cum[z][beg+dy[k]]++;
            }
            else {
               int upto = beg + dy[k] - 1;
               if(upto < t) {
                  int diff = t - upto;
                  int buff = 1 + (diff - 1) / z;
                  upto += buff * z;
               }

               int l = upto-dy[k]+1, r = upto+1;
               cum[z][l]--, cum[z][r]++;
               r = max(l, min(r, t));

               cut[l]++, cut[r]--;
            }
         }
      }
      else {
         if(op == 1) {
            koi[k] = t, work[k] = 1;
            int nxt = t + dx[k];
            if(nxt <= m) st[nxt].push_back(k);
         }
         else {
            if(work[k] < 0) ans--;
            work[k] = 0;
         }
      }

      for(int &k : st[t]) {
         if(work[k] > 0 and koi[k] == t - dx[k]) {
            koi[k] = t, work[k] = -1;
            int nxt = t + dy[k];
            if(nxt <= m) st[nxt].push_back(k);
            ans++;
         }
         if(work[k] < 0 and koi[k] == t - dy[k]) {
            koi[k] = t, work[k] = +1;
            int nxt = t + dx[k];
            if(nxt <= m) st[nxt].push_back(k);
            ans--;
         }
      }
      st[t].clear();

      res[t] += ans;
   }

   for(int t=1; t<=m; t++) cut[t] += cut[t-1], res[t] += cut[t];

   for(int d=1; d<mag; d++) {
      for(auto &[t, v] : cum[d]) dunno[t] += v;
      for(int t=1; t<=m; t++) dunno[t] += dunno[t-1];
      for(int t=1; t<=m; t++) {
         dunno[t + d] += dunno[t];
         res[t] += dunno[t];
         dunno[t] = 0;
      }
   }

   for(int t=1; t<=m; t++) printf("%d\n", res[t]);
}