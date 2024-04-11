#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  vector<pair<int, int>> hist;
  unionfind(int N){
    p = vector<int>(N, -1);
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      return root(p[x]);
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x != y){
      if (p[x] > p[y]){
        swap(x, y);
      }
      hist.push_back(make_pair(x, p[x]));
      hist.push_back(make_pair(y, p[y]));
      p[x] += p[y];
      p[y] = x;
    }
  }
  void snapshot(){
    hist.clear();
  }
  void rollback(){
    while (!hist.empty()){
      int v = hist.back().first;
      int x = hist.back().second;
      p[v] = x;
      hist.pop_back();
    }
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
    c[i]--;
  }
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  map<pair<int, int>, vector<int>> mp;
  for (int i = 0; i < m; i++){
    int x = c[a[i]];
    int y = c[b[i]];
    if (x > y){
      swap(x, y);
    }
    mp[make_pair(x, y)].push_back(i);
  }
  vector<bool> ok(k, true);
  unionfind UF(n * 2);
  int cnt = 0;
  for (int i = 0; i < k; i++){
    for (int x : mp[make_pair(i, i)]){
      UF.unite(a[x] * 2, b[x] * 2 + 1);
      UF.unite(a[x] * 2 + 1, b[x] * 2);
      if (UF.same(a[x] * 2, a[x] * 2 + 1)){
        ok[i] = false;
        break;
      }
      if (UF.same(b[x] * 2, b[x] * 2 + 1)){
        ok[i] = false;
        break;
      }
    }
    if (ok[i]){
      UF.snapshot();
      cnt++;
    } else {
      UF.rollback();
    }
  }
  long long ans = (long long) cnt * (cnt - 1) / 2;
  for (auto P : mp){
    int g1 = P.first.first;
    int g2 = P.first.second;
    if (g1 == g2){
      continue;
    }
    if (!ok[g1] || !ok[g2]){
      continue;
    }
    bool ok2 = true;
    for (int x : P.second){
      UF.unite(a[x] * 2, b[x] * 2 + 1);
      UF.unite(a[x] * 2 + 1, b[x] * 2);
      if (UF.same(a[x] * 2, a[x] * 2 + 1)){
        ok2 = false;
        break;
      }
      if (UF.same(b[x] * 2, b[x] * 2 + 1)){
        ok2 = false;
        break;
      }
    }
    if (!ok2){
      ans--;
    }
    UF.rollback();
  }
  cout << ans << endl;
}