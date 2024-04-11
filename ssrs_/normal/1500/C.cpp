#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> b[i][j];
    }
  }
  map<vector<int>, queue<int>> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]].push(i);
  }
  bool ok = true;
  vector<int> id(n, -1);
  for (int i = 0; i < n; i++){
    if (mp.count(b[i])){
      if (!mp[b[i]].empty()){
        id[i] = mp[b[i]].front();
        mp[b[i]].pop();
      }
    }
    if (id[i] == -1){
      ok = false;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    vector<bool> d(n - 1, false);
    vector<vector<int>> inc(m);
    vector<set<int>> dec(m);
    queue<int> Q;
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n - 1; j++){
        if (b[j][i] < b[j + 1][i]){
          inc[i].push_back(j);
        }
        if (b[j][i] > b[j + 1][i]){
          dec[i].insert(j);
        }
      }
      if (dec[i].empty()){
        Q.push(i);
      }
    }
    vector<int> b;
    while (!Q.empty()){
      int c = Q.front();
      b.push_back(c);
      Q.pop();
      for (int i : inc[c]){
        if (!d[i]){
          d[i] = true;
          for (int j = 0; j < m; j++){
            if (dec[j].count(i)){
              dec[j].erase(i);
              if (dec[j].empty()){
                Q.push(j);
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n - 1; i++){
      if (!d[i] && id[i] > id[i + 1]){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      int k = b.size();
      cout << k << endl;
      for (int i = 0; i < k; i++){
        cout << b[k - 1 - i] + 1;
        if (i < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}