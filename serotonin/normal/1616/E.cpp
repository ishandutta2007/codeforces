#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

char a[sz], b[sz];
vector <int> g[26];

int n, bit[sz];

void add(int x) {
   while(x <= n) {
      bit[x]++;
      x += x & -x;
   }
}

int quer(int x) {
   int res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

void solve() {
   scanf("%d %s %s", &n, a, b);
   for(int j=0; j<26; j++) g[j].clear();
   for(int i=n-1; i>=0; i--) g[a[i] - 'a'].push_back(i);
   for(int i=0; i<=n; i++) bit[i] = 0;

   ll sum = 0, ans = LLONG_MAX;
   for(int i=0; i<n; i++) {
      int c = b[i] - 'a';
      for(int j=0; j<c; j++) if(!g[j].empty()) {
         int k = g[j].back();
         int more = quer(k + 1);
         ans = min(ans, sum + k - more);
      }
      if(g[c].empty()) break;
      int k = g[c].back(); g[c].pop_back();
      int more = quer(k + 1);
      add(k + 1);
      sum += k - more;
   }
   if(ans == LLONG_MAX) ans = -1;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}