#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<tuple<int, int, int>>> E(n); 
  for (int i = 0; i < m; i++){
    int u, v, x;
    cin >> u >> v >> x;
    u--;
    v--;
    E[u].push_back(make_tuple(x, 0, v));
    E[v].push_back(make_tuple(x, 0, u));
  }
  for (int i = 0; i < k; i++){
    int s, y;
    cin >> s >> y;
    s--;
    E[0].push_back(make_tuple(y, 1, s));
  }
  vector<long long> d(n, -1);
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
  pq.push(make_tuple(0, 0, 0));
  int ans = k;
  while (!pq.empty()){
    long long dd = get<0>(pq.top());
    int t = get<1>(pq.top());
    int v = get<2>(pq.top());
    pq.pop();
    if (d[v] == -1){
      d[v] = dd;
      if (t == 1){
        ans--;
      }
      for (auto e : E[v]){
        int w = get<2>(e);
        if (d[w] == -1){
          pq.push(make_tuple(dd + get<0>(e), get<1>(e), w));
        }
      }
    }
  }
  cout << ans << endl;
}