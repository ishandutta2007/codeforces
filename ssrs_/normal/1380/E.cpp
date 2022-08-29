#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int n){
    p = vector<int>(n, -1);
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else { 
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    p[x] = y;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
    t[i]--;
  }
  vector<vector<int>> tower(m);
  for (int i = 0; i < n; i++){
    tower[t[i]].push_back(i);
  }
  vector<map<int, int>> mp(n);
  for (int i = 0; i < n; i++){
    mp[i][0] = t[i];
  }
  unionfind UF(n);
  for (int i = 1; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    a = UF.root(a);
    b = UF.root(b);
    if (tower[a].size() > tower[b].size()){
      swap(a, b);
    }
    //merge a -> b
    UF.unite(a, b);
    int sz = tower[a].size();
    for (int j = 0; j < sz; j++){
      mp[tower[a][j]][i] = b;
      tower[b].push_back(tower[a][j]);
    }
    tower[a].clear();
  }
  vector<int> d(m, 0);
  for (int i = 0; i < n - 1; i++){
    int tv = m;
    int fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int pos_a = (*prev(mp[i].upper_bound(mid))).second;
      int pos_b = (*prev(mp[i + 1].upper_bound(mid))).second;
      if (pos_a == pos_b){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    d[tv]--;
  }
  d[0] += n - 1;
  for (int i = 0; i < m - 1; i++){
    d[i + 1] += d[i];
  }
  for (int i = 0; i < m; i++){
    cout << d[i] << "\n";
  }
}