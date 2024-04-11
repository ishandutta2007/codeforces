#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  vector<vector<int>> E2(n);
  for (int i = 0; i < m; i++){
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    E[v].push_back(u);
    E2[u].push_back(v);
  }
  vector<int> d(n, INF);
  d[n - 1] = 0;
  vector<int> cnt(n, 0);
  vector<bool> used(n, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, n - 1));
  while (!pq.empty()){
    int c = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (!used[v]){
      used[v] = true;
      for (int w : E2[v]){
        if (!used[w]){
          int c2 = c + E[w].size() - cnt[w];
          if (c2 < d[w]){
            d[w] = c2;
            pq.push(make_pair(c2, w));
          }
          cnt[w]++;
        }
      }
    }
  }
  cout << d[0] << endl;
}