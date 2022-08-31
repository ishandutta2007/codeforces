#include <bits/stdc++.h>
using namespace std;
int dfs1(vector<int> &sum, vector<vector<int>> &c, vector<int> &p, int v = 0){
  sum[v] = p[v];
  for (int w : c[v]){
    sum[v] += dfs1(sum, c, p, w);
  }
  return sum[v];
}
void dfs2(vector<long long> &good, vector<vector<int>> &c, bool& ok, int v = 0){
  long long sum = 0;
  for (int w : c[v]){
    sum += good[w];
  }
  if (sum > good[v]){
    ok = false;
  } else {
    for (int w : c[v]){
      dfs2(good, c, ok, w);
      if (!ok){
        break;
      }
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    vector<long long> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n - 1; j++){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      E[x].push_back(y);
      E[y].push_back(x);
    }
    vector<int> par(n, -1);
    vector<vector<int>> c(n);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (w != par[v]){
          par[w] = v;
          c[v].push_back(w);
          Q.push(w);
        }
      }
    }
    vector<int> sum(n);
    dfs1(sum, c, p);
    bool ok = true;
    vector<long long> good(n);
    vector<long long> bad(n);
    for (int j = 0; j < n; j++){
      if ((h[j] + sum[j]) % 2 != 0){
        ok = false;
      } else {
        good[j] = (sum[j] + h[j]) / 2;
        bad[j] = (sum[j] - h[j]) / 2;
        if (good[j] < 0 || bad[j] < 0){
          ok = false;
        }
      }
    }
    dfs2(good, c, ok);
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}