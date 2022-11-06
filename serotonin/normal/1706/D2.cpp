#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int cur[sz];
bool done[sz];
vector <int> g[sz];

int nxt(int n, int d) {
   if(n == d) return d;
   if(d + 1 <= n / (d + 1)) return cur[n] = d + 1;
   while(n / cur[n] <= d) cur[n]--;
   return n / cur[n];
}

void solve() {
   int n, k, mxv = 0, ans = sz;
   scanf("%d %d", &n, &k);
   for(int i=0; i<sz; i++) done[i] = 0, vector<int>().swap(g[i]);
   for(int i=0, x; i<n; i++) {
      scanf("%d", &x);
      if(done[x]) continue;
      done[x] = 1;
      mxv = max(mxv, x);
      g[x / k].push_back(x);
      cur[x] = min(k, x / k);
   }

   for(int up = mxv / k, dn = 0; up <= mxv; up++) {
      while(dn < up) {
         while(!g[dn].empty()) {
            int x = g[dn].back(), y = nxt(x, dn);
            if(x == dn) break;
            if(y <= up) {
               g[dn].pop_back();
               g[y].push_back(x);
            }
            else break;
         }
         if(g[dn].empty()) vector<int>().swap(g[dn++]);
         else break;
      }
      ans = min(ans, up - dn);
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}