#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  for (int i = 0; i < n; i++){
    cin >> r[i];
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < m; i++){
    int x;
    cin >> x;
    for (int j = 0; j < x; j++){
      int p;
      cin >> p;
      p--;
      id[p].push_back(i);
    }
  }
  vector<vector<pair<int, int>>> E(m);
  for (int i = 0; i < n; i++){
    int x = id[i][0];
    int y = id[i][1];
    E[x].push_back(make_pair(1 - r[i], y));
    E[y].push_back(make_pair(1 - r[i], x));
  }
  vector<int> p(m, -1);
  bool ok = true;
  for (int i = 0; i < m; i++){
    if (p[i] == -1){
      p[i] = 0;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int w = P.second;
          if (p[w] == -1){
            p[w] = p[v] ^ P.first;
            Q.push(w);
          } else if (p[w] != (p[v] ^ P.first)){
            ok = false;
          }
        }
      }
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}