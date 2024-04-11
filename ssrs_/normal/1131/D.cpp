#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<vector<int>> E1(n + m);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (S[i][j] == '='){
        E1[i].push_back(n + j);
        E1[n + j].push_back(i);
      }
    }
  }
  vector<int> c(n + m, -1);
  int cnt = 0;
  for (int i = 0; i < n + m; i++){
    if (c[i] == -1){
      c[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E1[v]){
          if (c[w] == -1){
            c[w] = cnt;
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i] == c[n + j] && S[i][j] != '='){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << "No" << endl;
  } else {
    vector<vector<int>> E2(cnt);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (S[i][j] == '<'){
          E2[c[i]].push_back(c[n + j]);
        }
        if (S[i][j] == '>'){
          E2[c[n + j]].push_back(c[i]);
        }
      }
    }
    vector<int> d(cnt, 0);
    for (int i = 0; i < cnt; i++){
      for (int j : E2[i]){
        d[j]++;
      }
    }
    queue<int> Q;
    for (int i = 0; i < cnt; i++){
      if (d[i] == 0){
        Q.push(i);
      }
    }
    vector<int> ans(cnt, 1);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E2[v]){
        d[w]--;
        ans[w] = max(ans[w], ans[v] + 1);
        if (d[w] == 0){
          Q.push(w);
        }
      }
    }
    for (int i = 0; i < cnt; i++){
      if (d[i] != 0){
        ok = false;
      }
    }
    if (!ok){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      for (int i = 0; i < n; i++){
        cout << ans[c[i]];
        if (i < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
      for (int i = 0; i < m; i++){
        cout << ans[c[n + i]];
        if (i < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}