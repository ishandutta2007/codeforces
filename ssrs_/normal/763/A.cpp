#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<set<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].insert(v);
    E[v].insert(u);
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  bool same = true;
  for (int i = 1; i < n; i++){
    if (c[i] != c[0]){
      same = false;
    }
  }
  if (same){
    cout << "YES" << endl;
    cout << 1 << endl;
  } else {
    queue<int> Q;
    for (int i = 0; i < n; i++){
      if (E[i].size() == 1){
        Q.push(i);
      }
    }
    int V = n;
    while (!Q.empty()){
      int v = Q.front();
      int w = *(E[v].begin());
      Q.pop();
      if (c[v] == c[w]){
        E[v].erase(w);
        E[w].erase(v);
        V--;
        if (E[w].size() == 1){
          Q.push(w);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
      if (E[i].size() == V - 1){
        ans = i + 1;
      }
    }
    if (ans == -1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << ans << endl;
    }
  }
}