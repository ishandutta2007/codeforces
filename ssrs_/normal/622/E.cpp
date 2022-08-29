#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<int> d(n, 0);
  vector<int> a(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        d[w] = d[v] + 1;
        if (v == 0){
          a[w] = w;
        } else {
          a[w] = a[v];
        }
        Q.push(w);
      }
    }
  }
  vector<vector<int>> t(n);
  for (int i = 1; i < n; i++){
    if (E[i].size() == 1){
      t[a[i]].push_back(d[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (!t[i].empty()){
      sort(t[i].begin(), t[i].end());
      int cnt = t[i].size();
      for (int j = 1; j < cnt; j++){
        t[i][j] = max(t[i][j], t[i][j - 1] + 1);
      }
      ans = max(ans, t[i][cnt - 1]);
    }
  }
  cout << ans << endl;
}