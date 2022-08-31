#include <bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin >> m;
  vector<int> n(m);
  vector<vector<int>> a(m);
  for (int i = 0; i < m; i++){
    cin >> n[i];
    a[i] = vector<int>(n[i]);
    for (int j = 0; j < n[i]; j++){
      cin >> a[i][j];
    }
  }
  map<int, int> mp;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n[i]; j++){
      mp[a[i][j]]++;
    }
  }
  bool ok = true;
  for (auto P : mp){
    if (P.second % 2 == 1){
      ok = false;
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    vector<string> ans(m);
    for (int i = 0; i < m; i++){
      ans[i] = string(n[i], '.');
    }
    vector<vector<int>> r(m);
    for (int i = 0; i < m; i++){
      map<int, int> mp;
      vector<bool> used(n[i], false);
      for (int j = 0; j < n[i]; j++){
        if (mp.count(a[i][j]) == 0){
          mp[a[i][j]] = j;
        } else {
          used[j] = true;
          used[mp[a[i][j]]] = true;
          ans[i][mp[a[i][j]]] = 'L';
          ans[i][j] = 'R';
          mp.erase(a[i][j]);
        }
      }
      for (int j = 0; j < n[i]; j++){
        if (!used[j]){
          r[i].push_back(j);
        }
      }
    }
    vector<int> S(m + 1);
    S[0] = 0;
    for (int i = 0; i < m; i++){
      S[i + 1] = S[i] + r[i].size();
    }
    vector<vector<int>> E(S[m]);
    for (int i = 0; i < S[m]; i += 2){
      E[i].push_back(i + 1);
      E[i + 1].push_back(i);
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++){
      int sz = r[i].size();
      for (int j = 0; j < sz; j++){
        mp[a[i][r[i][j]]].push_back(S[i] + j);
      }
    }
    for (auto P : mp){
      int sz = P.second.size();
      for (int i = 0; i < sz; i += 2){
        E[P.second[i]].push_back(P.second[i + 1]);
        E[P.second[i + 1]].push_back(P.second[i]);
      }
    }
    vector<int> c(S[m], -1);
    for (int i = 0; i < S[m]; i++){
      if (c[i] == -1){
        c[i] = 0;
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E[v]){
            if (c[w] == -1){
              c[w] = 1 - c[v];
              Q.push(w);
            }
          }
        }
      }
    }
    for (int i = 0; i < m; i++){
      int sz = r[i].size();
      for (int j = 0; j < sz; j++){
        if (c[S[i] + j] == 0){
          ans[i][r[i][j]] = 'L';
        } else {
          ans[i][r[i][j]] = 'R';
        }
      }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < m; i++){
      cout << ans[i] << "\n";
    }
  }
}