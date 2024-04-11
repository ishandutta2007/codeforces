#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> ans;
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(0);
  vector<bool> used(n, false);
  while (!pq.empty()){
    int v = pq.top();
    pq.pop();
    if (!used[v]){
      used[v] = true;
      ans.push_back(v);
      for (int w : E[v]){
        if (!used[w]){
          pq.push(w);
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}