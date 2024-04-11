#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<int> d(n, -1);
    vector<long long> dp1(n, 0), dp2(n, 0);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push(make_tuple(0, s, 0));
    pq.push(make_tuple(1, s, 1));
    d[s] = 0;
    dp1[s] = 1;
    while (!pq.empty()){
      int dd = get<0>(pq.top());
      int v = get<1>(pq.top());
      int x = get<2>(pq.top());
      pq.pop();
      if (x == 0){
        for (int w : E[v]){
          if (d[w] == -1){
            d[w] = d[v] + 1;
            dp1[w] += dp1[v];
            dp1[w] %= MOD;
            pq.push(make_tuple(d[w], w, 0));
            pq.push(make_tuple(d[w] + 1, w, 1));
          } else if (d[w] == d[v] + 1){
            dp1[w] += dp1[v];
            dp1[w] %= MOD;
          } else if (d[w] == d[v]){
            dp2[w] += dp1[v];
            dp2[w] %= MOD;
          }
        }
      }
      if (x == 1){
        for (int w : E[v]){
          if (d[w] == d[v] + 1){
            dp2[w] += dp2[v];
            dp2[w] %= MOD;
          }
        }
      }
    }
    long long ans = (dp1[t] + dp2[t]) % MOD;
    cout << ans << endl;
  }
}