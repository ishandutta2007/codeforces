#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> E(n);
    for (int j = 0; j < n - 1; j++){
      int x, y, v;
      cin >> x >> y >> v;
      x--;
      y--;
      E[x].push_back(make_pair(v, y));
      E[y].push_back(make_pair(v, x));
    }
    vector<vector<pair<int, int>>> E2(n);
    for (int j = 0; j < n; j++){
      for (auto P : E[j]){
        int x = P.first;
        if (x != -1){
          int w = P.second;
          E2[j].push_back(make_pair(__builtin_parity(x), w));
        }
      }
    }
    for (int j = 0; j < m; j++){
      int a, b, p;
      cin >> a >> b >> p;
      a--;
      b--;
      E2[a].push_back(make_pair(p, b));
      E2[b].push_back(make_pair(p, a));
    }
    vector<int> D(n, -1);
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (D[j] == -1){
        D[j] = 0;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (auto P : E2[v]){
            int x = P.first;
            int w = P.second;
            if (D[w] == -1){
              D[w] = D[v] ^ x;
              Q.push(w);
            } else if ((D[w] ^ D[v]) != x){
              ok = false;
            }
          }
        }
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      vector<int> p(n, -1);
      queue<int> Q;
      Q.push(0);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int w = P.second;
          if (w != p[v]){
            p[w] = v;
            int x = P.first;
            if (x != -1){
              cout << v + 1 << ' ' << w + 1 << ' ' << x << "\n";
            } else {
              cout << v + 1 << ' ' << w + 1 << ' ' << (D[v] ^ D[w]) << "\n";
            }
            Q.push(w);
          }
        }
      }
    }
  }
}