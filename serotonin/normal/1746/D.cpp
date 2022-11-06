#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

ll a[sz];
vector <int> g[sz];
map <int,ll> dp[sz];

ll fnc(int u, int k) {
   int c = g[u].size();

   if(!c) return a[u] * k;

   if(dp[u].find(k) != dp[u].end()) return dp[u][k];

   if(k % c == 0) {
      ll res = a[u] * k;
      for(int v : g[u]) res += fnc(v, k / c);
      return dp[u][k] = res;
   }

   vector <ll> ara;
   ll &res = dp[u][k] = a[u] * k;
   for(int v : g[u]) {
      ll one = fnc(v, k / c);
      ll two = fnc(v, k / c + 1);
      res += one;
      ara.push_back(two - one);
   }
   sort(ara.rbegin(), ara.rend());

   k %= c;
   for(int i=0; i<k; i++) res += ara[i];
   return res;
}

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) g[i].clear(), dp[i].clear();
   for(int i=2, j; i<=n; i++) {
      scanf("%d", &j);
      g[j].push_back(i);
   }
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   printf("%lld\n", fnc(1, k));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}