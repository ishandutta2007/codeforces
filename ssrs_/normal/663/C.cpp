#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, char>>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    char c;
    cin >> u >> v >> c;
    u--;
    v--;
    E[u].push_back(make_pair(v, c));
    E[v].push_back(make_pair(u, c));
  }
  vector<int> c1(n, -1);
  vector<int> c2(n, -1);
  vector<bool> used(n, false);
  vector<int> ans1, ans2;
  bool ok1 = true, ok2 = true;
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      c1[i] = 0;
      c2[i] = 0;
      vector<int> cc;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        cc.push_back(v);
        for (auto P : E[v]){
          int w = P.first;
          char c = P.second;
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
          if (c == 'B'){
            if (c1[w] == -1){
              c1[w] = 1 - c1[v];
            } else if (c1[w] == c1[v]){
              ok1 = false;
            }
            if (c2[w] == -1){
              c2[w] = c2[v];
            } else if (c2[w] == 1 - c2[v]){
              ok2 = false;
            }
          }
          if (c == 'R'){
            if (c1[w] == -1){
              c1[w] = c1[v];
            } else if (c1[w] == 1 - c1[v]){
              ok1 = false;
            }
            if (c2[w] == -1){
              c2[w] = 1 - c2[v];
            } else if (c2[w] == c2[v]){
              ok2 = false;
            }
          }
        }
      }
      vector<int> c10, c11, c20, c21;
      for (int v : cc){
        if (c1[v] == 0){
          c10.push_back(v);
        }
        if (c1[v] == 1){
          c11.push_back(v);
        }
        if (c2[v] == 0){
          c20.push_back(v);
        }
        if (c2[v] == 1){
          c21.push_back(v);
        }
      }
      if (c10.size() < c11.size()){
        for (int x : c10){
          ans1.push_back(x);
        }
      } else {
        for (int x : c11){
          ans1.push_back(x);
        }
      }
      if (c20.size() < c21.size()){
        for (int x : c20){
          ans2.push_back(x);
        }
      } else {
        for (int x : c21){
          ans2.push_back(x);
        }
      }
    }
  }
  if (!ok1 && !ok2){
    cout << -1 << endl;
  } else {
    vector<int> ans;
    if (ok1 && !ok2 || ok1 && ok2 && ans1.size() < ans2.size()){
      ans = ans1;
    } else {
      ans = ans2;
    }
    int k = ans.size();
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << ans[i] + 1;
      if (i < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}