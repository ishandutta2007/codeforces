#include <bits/stdc++.h>
using namespace std;
const long long LOG = 31;
long long d(long long x){
  int cnt = 0;
  while (x > 0){
    x = (x - 1) / 2;
  }
  return cnt;
}
long long lca(long long x, long long y){
  int dx = d(x);
  int dy = d(y);
  if (dx > dy){
    swap(dx, dy);
  }
  for (int i = 0; i < dy - dx; i++){
    y = (y - 1) / 2;
  }
  while (x != y){
    x = (x - 1) / 2;
    y = (y - 1) / 2;
  }
  return x;
}
void dfs(vector<int> &dp1, vector<int> &dp2, vector<int> &p, vector<vector<int>> &c, int v = 0){
  if (c[v].empty()){
    dp1[v] = 0;
  } else {
    dp1[v] = 1;
  }
  dp2[v] = dp1[v];
  int mx = 0;
  for (int w : c[v]){
    dfs(dp1, dp2, p, c, w);
    dp1[v] += dp1[w];
    mx = max(mx, dp2[w]);
  }
  dp2[v] += mx;
}
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] += ((long long) 1 << LOG) - 1;
  }
  sort(a.begin(), a.end());
  vector<long long> L(n - 1);
  for (int i = 0; i < n - 1; i++){
    L[i] = lca(a[i], a[i + 1]);
  }
  vector<long long> x;
  for (int i = 0; i < n; i++){
    x.push_back(a[i]);
  }
  for (int i = 0; i < n - 1; i++){
    x.push_back(L[i]);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int cnt = x.size();
  map<long long, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[x[i]] = i;
  }
  vector<int> p(cnt, -1);
  vector<vector<int>> c(cnt);
  for (int i = 0; i < cnt; i++){
    long long X = x[i];
    int id = mp[X];
    int cnt = 0;
    while (1){
      cnt++;
      if (cnt > LOG * 2)break;
      X = (X - 1) / 2;
      if (mp.count(X)){
        p[id] = mp[X];
        c[p[id]].push_back(id);
        break;
      }
    }
  }
  vector<int> dp1(cnt);
  vector<int> dp2(cnt);
  dfs(dp1, dp2, p, c);
  cout << dp1[0] - dp2[0] << endl;
}