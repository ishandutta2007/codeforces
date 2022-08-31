#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &L, vector<int> &d, vector<vector<int>> &c, int v = 0, int cd = 0){
  L.push_back(v);
  d.push_back(cd);
  for (int w : c[v]){
    dfs(L, d, c, w, cd + 1);
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> p(n, -1);
  for (int i = 1; i < n; i++){
    cin >> p[i];
  }
  vector<vector<int>> c(n);
  for (int i = 1; i < n; i++){
    c[p[i]].push_back(i);
  }
  vector<int> d(n);
  d[0] = 0;
  for (int i = 1; i < n; i++){
    d[i] = d[p[i]] + 1;
  }
  for (int i = n - 1; i >= 1; i--){
    d[p[i]] = max(d[p[i]], d[i]);
  }
  for (int i = 0; i < n; i++){
    vector<pair<int, int>> tmp;
    for (int j : c[i]){
      tmp.push_back(make_pair(d[j], j));
    }
    sort(tmp.begin(), tmp.end());
    int cnt = c[i].size();
    for (int j = 0; j < cnt; j++){
      c[i][j] = tmp[j].second;
    }
  }
  vector<int> L;
  vector<int> d2;
  dfs(L, d2, c);
  for (int i = 0; i < n; i++){
    cout << L[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
  vector<int> v;
  for (int i = 1; i < n; i++){
    int cnt = 1 - (d2[i] - d2[i - 1]);
    for (int j = 0; j < cnt; j++){
      v.push_back(L[i]);
    }
  }
  int k = v.size();
  assert(k <= 1000000);
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << v[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}