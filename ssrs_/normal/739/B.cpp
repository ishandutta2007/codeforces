#include <bits/stdc++.h>
using namespace std;
int LOG = 20;
int dfs(vector<int> &add, vector<vector<int>> &c, int v = 0){
  for (int w : c[v]){
    add[v] += dfs(add, c, w);
  }
  return add[v];
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> p(n, 0), w(n, 0);
  for (int i = 1; i < n; i++){
    cin >> p[i] >> w[i];
    p[i]--;
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  vector<vector<int>> next(LOG, vector<int>(n));
  for (int i = 0; i < n; i++){
    next[0][i] = p[i];
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < n; j++){
      next[i][j] = next[i - 1][next[i - 1][j]];
    }
  }
  vector<vector<long long>> sum(LOG, vector<long long>(n));
  for (int i = 0; i < n; i++){
    sum[0][i] = w[i];
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < n; j++){
      sum[i][j] = sum[i - 1][j] + sum[i - 1][next[i - 1][j]];
    }
  }
  vector<int> add(n, 0);
  for (int i = 0; i < n; i++){
    add[i]++;
    int v = i;
    for (int j = LOG - 1; j >= 0; j--){
      long long s = sum[j][v];
      if (a[i] - sum[j][v] >= 0){
        a[i] -= sum[j][v];
        v = next[j][v];
      }
    }
    if (v != 0){
      add[p[v]]--;
    }
  }
  dfs(add, c);
  for (int i = 0; i < n; i++){
    cout << add[i] - 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}