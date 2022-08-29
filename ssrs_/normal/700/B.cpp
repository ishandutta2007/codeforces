#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> &b, vector<vector<int>> &c, int v = 0){
  for (int w : c[v]){
    b[v] += dfs(b, c, w);
  }
  return b[v];
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(k * 2);
  for (int i = 0; i < k * 2; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> b(n, 0);
  for (int i = 0; i < k * 2; i++){
    b[a[i]]++;
  }
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
  vector<vector<int>> c(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (p[w] == -1 && w != 0){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  dfs(b, c);
  long long ans = 0;
  for (int i = 0; i < n; i++){
    for (int j : c[i]){
      ans += min(b[j], b[0] - b[j]);
    }
  }
  cout << ans << endl;
}