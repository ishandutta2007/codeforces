#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long BASE1 = 123456789;
const long long BASE2 = 987654321;
const int MAX = 200000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> power1(MAX, 1);
  for (int i = 1; i < MAX; i++){
    power1[i] = power1[i - 1] * BASE1 % MOD;
  }
  vector<long long> power2(MAX, 1);
  for (int i = 1; i < MAX; i++){
    power2[i] = power2[i - 1] * BASE2 % MOD;
  }
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[u].push_back(make_pair(w, v));
  }
  for (int i = 0; i < n; i++){
    sort(E[i].begin(), E[i].end());
  }
  vector<vector<int>> vl(k);
  for (int i = 0; i < n; i++){
    vl[E[i].size() - 1].push_back(i);
    //cout << E[i].size() - 1 << endl;
  }
  vector<vector<pair<long long, long long>>> V(k);
  for (int i = 0; i < k; i++){
    V[i] = vector<pair<long long, long long>>(i + 1);
    for (int j = 0; j <= i; j++){
      long long h1 = 0, h2 = 0;
      for (int v : vl[i]){
        int w = E[v][j].second;
        h1 += power1[w];
        h1 %= MOD;
        h2 += power2[w];
        h2 %= MOD;
      }
      V[i][j] = make_pair(h1, h2);
      //cout << "i = " << i << ", j = " << j << ", h1 = " << h1 << ", h2 = " << h2 << endl;
    }
  }
  map<pair<long long, long long>, int> dp;
  dp[make_pair(0, 0)] = 1;
  for (int i = 0; i < k; i++){
    map<pair<long long, long long>, int> dp2;
    for (auto P : dp){
      long long h1 = P.first.first;
      long long h2 = P.first.second;
      int cnt = P.second;
      for (int j = 0; j <= i; j++){
        dp2[make_pair((h1 + V[i][j].first) % MOD, (h2 + V[i][j].second) % MOD)] += cnt;
      }
    }
    swap(dp, dp2);
  }
  long long c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++){
    c1 += power1[i];
    c1 %= MOD;
    c2 += power2[i];
    c2 %= MOD;
  }
  cout << dp[make_pair(c1, c2)] << endl;
}