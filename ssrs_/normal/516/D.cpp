#include <bits/stdc++.h>
using namespace std;
const int LOG = 17;
vector<long long> get_dist(vector<vector<pair<int, int>>> &E, int s){
  int N = E.size();
  vector<long long> d(N, -1);
  d[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (d[w] == -1){
        d[w] = d[v] + P.first;
        Q.push(w);
      }
    }
  }
  return d;
}
pair<int, int> get_diameter(vector<vector<pair<int, int>>> &E){
  vector<long long> d1 = get_dist(E, 0);
  int s = max_element(d1.begin(), d1.end()) - d1.begin();
  vector<long long> d2 = get_dist(E, s);
  int t = max_element(d2.begin(), d2.end()) - d2.begin();
  return make_pair(s, t);
}
int dfs(vector<int> &dp, vector<vector<int>> &c, vector<int> &a, int v){
  dp[v] = 1 - a[v];
  for (int w : c[v]){
    dp[v] += dfs(dp, c, a, w);
  }
  return dp[v];
}
int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y, v;
    cin >> x >> y >> v;
    x--;
    y--;
    E[x].push_back(make_pair(v, y));
    E[y].push_back(make_pair(v, x));
  }
  int s, t;
  tie(s, t) = get_diameter(E);
  vector<long long> d1 = get_dist(E, s);
  vector<long long> d2 = get_dist(E, t);
  vector<long long> d(n);
  for (int i = 0; i < n; i++){
    d[i] = max(d1[i], d2[i]);
  }
  int r = min_element(d.begin(), d.end()) - d.begin();
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  queue<int> Q;
  Q.push(r);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  vector<vector<int>> pp(LOG, vector<int>(n, -1));
  for (int i = 0; i < n; i++){
    pp[0][i] = p[i];
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < n; j++){
      if (pp[i - 1][j] != -1){
        pp[i][j] = pp[i - 1][pp[i - 1][j]];
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    long long l;
    cin >> l;
    vector<int> a(n, 0);
    for (int j = 0; j < n; j++){
      if (d[j] - l > d[r]){
        int v = j;
        for (int k = LOG - 1; k >= 0; k--){
          if (pp[k][v] != -1){
            if (d[j] - l <= d[pp[k][v]]){
              v = pp[k][v];
            }
          }
        }
        a[p[v]]++;
      }
    }
    vector<int> dp(n, 0);
    dfs(dp, c, a, r);
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
}