#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
void dfs(vector<vector<int>> &c, vector<int> &l, vector<int> &r, vector<int> &sz, int v = 0){
  if (!c[v].empty()){
    l[v] = INF;
    r[v] = -INF;
    sz[v] = 1;
    for (int w : c[v]){
      dfs(c, l, r, sz, w);
      l[v] = min(l[v], l[w]);
      r[v] = max(r[v], r[w]);
      sz[v] += sz[w];
    }
  }
}
int main(){
  int n;
  cin >> n;
  int a;
  cin >> a;
  vector<int> p(a, -1);
  vector<vector<int>> c1(a);
  for (int i = 1; i < a; i++){
    cin >> p[i];
    p[i]--;
    c1[p[i]].push_back(i);
  }
  vector<int> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
    x[i]--;
  }
  vector<int> l1(a), r1(a), sz1(a);
  for (int i = 0; i < n; i++){
    l1[x[i]] = i;
    r1[x[i]] = i + 1;
    sz1[x[i]] = 1;
  }
  dfs(c1, l1, r1, sz1, 0);
  int b;
  cin >> b;
  vector<int> q(b, -1);
  vector<vector<int>> c2(b);
  for (int i = 1; i < b; i++){
    cin >> q[i];
    q[i]--;
    c2[q[i]].push_back(i);
  }
  vector<int> y(n);
  for (int i = 0; i < n; i++){
    cin >> y[i];
    y[i]--;
  }
  vector<int> l2(b), r2(b), sz2(b);
  for (int i = 0; i < n; i++){
    l2[y[i]] = i;
    r2[y[i]] = i + 1;
    sz2[y[i]] = 1;
  }
  dfs(c2, l2, r2, sz2, 0);
  vector<vector<pair<int, int>>> E(n + 1);
  for (int i = 1; i < a; i++){
    E[l1[i]].push_back(make_pair(sz1[i], r1[i]));
  }
  for (int i = 1; i < b; i++){
    E[l2[i]].push_back(make_pair(sz2[i], r2[i]));
  }
  vector<int> dp(n + 1, -INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    for (auto P : E[i]){
      int d = P.first;
      int j = P.second;
      dp[j] = max(dp[j], dp[i] + d);
    }
  }
  cout << dp[n] << endl;
}