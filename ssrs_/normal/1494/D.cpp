#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    c[i] = a[i][i];
  }
  vector<pair<int, int>> ans;
  int k = n;
  vector<int> tmp;
  for (int i = 0; i < n; i++){
    tmp.push_back(i);
  }
  queue<pair<vector<int>, int>> Q;
  Q.push(make_pair(tmp, -1));
  while (!Q.empty()){
    vector<int> id = Q.front().first;
    int P = Q.front().second;
    Q.pop();
    int cnt = id.size();
    if (cnt == 1){
      ans.push_back(make_pair(id[0], P));
    } else {
      int mx = 0;
      for (int i = 0; i < cnt; i++){
        for (int j = 0; j < cnt; j++){
          mx = max(mx, a[id[i]][id[j]]);
        }
      }
      int P2 = k;
      k++;
      c.push_back(mx);
      if (P != -1){
        ans.push_back(make_pair(P2, P));
      }
      vector<vector<int>> E(cnt);
      for (int i = 0; i < cnt; i++){
        for (int j = 0; j < cnt; j++){
          if (a[id[i]][id[j]] != mx){
            E[i].push_back(j);
          }
        }
      }
      vector<bool> used(cnt, false);
      for (int i = 0; i < cnt; i++){
        if (!used[i]){
          used[i] = true;
          queue<int> Q2;
          Q2.push(i);
          vector<int> b;
          while (!Q2.empty()){
            int v = Q2.front();
            Q2.pop();
            b.push_back(id[v]);
            for (int w : E[v]){
              if (!used[w]){
                used[w] = true;
                Q2.push(w);
              }
            }
          }
          Q.push(make_pair(b, P2));
        }
      }
    }
  }
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << c[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
  cout << n + 1 << endl;
  for (int i = 0; i < k - 1; i++){
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
  }
}