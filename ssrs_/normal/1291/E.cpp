#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
struct unionfind{
  vector<int> p;
  vector<int> cnt0, cnt1;
  unionfind(int N){
    p = vector<int>(N, -1);
    cnt0 = vector<int>(N, 0);
    cnt1 = vector<int>(N, 0);
    for (int i = 0; i < N / 2; i++){
      cnt0[i]++;
      cnt1[N / 2 + i]++;
    }
  }
  int root(int x){
    if (p[x] < 0){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void set(int x){
    x = root(x);
    cnt0[x] = INF;
    cnt1[x] = INF;
  }
  int get(int x){
    int N = p.size() / 2;
    x %= N;
    int x1 = root(x);
    int x2 = root(x + N);
    return min(cnt1[x1], cnt1[x2]);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    p[x] = y;
    cnt0[y] += cnt0[x];
    cnt0[y] = min(cnt0[y], INF);
    cnt1[y] += cnt1[x];
    cnt1[y] = min(cnt1[y], INF);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> c(k);
  vector<vector<int>> x(k);
  for (int i = 0; i < k; i++){
    cin >> c[i];
    x[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++){
      cin >> x[i][j];
      x[i][j]--;
    }
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < k; i++){
    for (int j = 0; j < c[i]; j++){
      id[x[i][j]].push_back(i);
    }
  }
  unionfind UF(k * 2);
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (id[i].size() == 1){
      int p = id[i][0];
      int r;
      if (s[i] == '1'){
        r = UF.root(k + p);
      } else {
        r = UF.root(p);
      }
      ans -= UF.get(r);
      UF.set(r);
      ans += UF.get(r);
    } else if (id[i].size() == 2){
      int u = id[i][0];
      int v = id[i][1];
      if (s[i] == '1'){
        if (!UF.same(u, v)){
          ans -= UF.get(u);
          ans -= UF.get(v);
          UF.unite(u, v);
          UF.unite(k + u, k + v);
          ans += UF.get(u);
        }
      } else {
        if (!UF.same(u, k + v)){
          ans -= UF.get(u);
          ans -= UF.get(k + v);
          UF.unite(u, k + v);
          UF.unite(k + u, v);
          ans += UF.get(u);
        }
      }
    }
    cout << ans << "\n";
  }
}