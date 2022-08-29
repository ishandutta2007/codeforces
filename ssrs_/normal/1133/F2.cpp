#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, D;
  cin >> n >> m >> D;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    E[v].push_back(u);
    E[u].push_back(v);
  }
  vector<int> cc(n, -1);
  int cnt = 0;
  for (int i = 1; i < n; i++){
    if (cc[i] == -1){
      cc[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (cc[w] == -1 && w != 0){
            cc[w] = cnt;
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  if (D < cnt || D > E[0].size()){
    cout << "NO" << endl;
  } else {
    vector<vector<int>> A(cnt);
    for (int i : E[0]){
      A[cc[i]].push_back(i);
    }
    vector<int> B;
    for (int i = 0; i < cnt; i++){
      B.push_back(A[i].back());
      A[i].pop_back();
      D--;
    }
    for (int i = 0; i < cnt; i++){
      while (D > 0 && !A[i].empty()){
        B.push_back(A[i].back());
        A[i].pop_back();
        D--;
      }
    }
    cout << "YES" << endl;
    D = B.size();
    for (int i = 0; i < D; i++){
      cout << 1 << ' ' << B[i] + 1 << endl;
    }
    vector<bool> used(n, false);
    used[0] = true;
    queue<int> Q;
    for (int i = 0; i < D; i++){
      used[B[i]] = true;
      Q.push(B[i]);
    }
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (!used[w]){
          cout << v + 1 << ' ' << w + 1 << endl;
          used[w] = true;
          Q.push(w);
        }
      }
    }
  }
}