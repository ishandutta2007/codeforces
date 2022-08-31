#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &E, vector<bool> &used, vector<int> &ans, vector<int> &next, int v){
  int d = E[v].size();
  while (next[v] < d){
    int w = E[v][next[v]].first;
    int id = E[v][next[v]].second;
    next[v]++;
    if (!used[id]){
      used[id] = true;
      dfs(E, used, ans, next, w);
    }
  }
  ans.push_back(v);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> b[i];
  }
  vector<int> c(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> c[i];
  }
  for (int i = 0; i < n - 1; i++){
    if (b[i] > c[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> x;
  for (int i = 0; i < n - 1; i++){
    x.push_back(b[i]); 
    x.push_back(c[i]);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int cnt = x.size();
  for (int i = 0; i < n - 1; i++){
    b[i] = lower_bound(x.begin(), x.end(), b[i]) - x.begin();
    c[i] = lower_bound(x.begin(), x.end(), c[i]) - x.begin();
  }
  vector<int> d(cnt, 0);
  for (int i = 0; i < n - 1; i++){
    d[b[i]]++;
    d[c[i]]++;
  }
  int odd = 0;
  int s = 0;
  for (int i = 0; i < cnt; i++){
    if (d[i] % 2 == 1){
      s = i;
      odd++;
    }
  }
  if (odd > 2){
    cout << -1 << endl;
    return 0;
  }
  vector<vector<pair<int, int>>> E(cnt);
  for (int i = 0; i < n - 1; i++){
    E[b[i]].push_back(make_pair(c[i], i));
    if (b[i] != c[i]){
      E[c[i]].push_back(make_pair(b[i], i));
    }
  }
  vector<bool> used(n - 1, false);
  vector<int> ans;
  vector<int> next(cnt, 0);
  dfs(E, used, ans, next, s);
  for (int i = 0; i < n - 1; i++){
    if (!used[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++){
    cout << x[ans[i]];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}