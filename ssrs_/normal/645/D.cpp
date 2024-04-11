#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  map<pair<int, int>, int> mp;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    mp[make_pair(u, v)] = i;
  }
  vector<int> in(n, 0);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      in[j]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (in[i] == 0){
      Q.push(i);
    }
  }
  vector<int> t;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    t.push_back(v);
    for (int w : E[v]){
      in[w]--;
      if (in[w] == 0){
        Q.push(w);
      }
    }
  }
  bool ok = true;
  int ans = 0;
  for (int i = 0; i < n - 1; i++){
    pair<int, int> P = make_pair(t[i], t[i + 1]);
    if (mp.count(P) == 0){
      ok = false;
    } else {
      ans = max(ans, mp[P]);
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    cout << ans + 1 << endl;
  }
}