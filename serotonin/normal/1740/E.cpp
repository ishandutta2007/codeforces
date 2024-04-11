#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int dp[sz], dep[sz];
vector <int> g[sz];

void fnc(int u) {
   dp[u] = 0, dep[u] = 1;
   for(int v : g[u]) {
      fnc(v);
      dp[u] += dp[v];
      dep[u] = max(dep[u], 1 + dep[v]);
   }
   dp[u] = max(dp[u], dep[u]);
}

int main() {
   int n;
   cin >> n;
   for(int i=2; i<=n; i++) {
      int j;
      scanf("%d", &j);
      g[j].push_back(i);
   }
   fnc(1);
   cout << dp[1];
}