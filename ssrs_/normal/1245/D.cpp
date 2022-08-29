#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N){
    p = vector<int>(N, -1);
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
    p[y] = x;
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<int> k(n);
  for (int i = 0; i < n; i++){
    cin >> k[i];
  }
  vector<tuple<long long, int, int>> E;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      E.push_back(make_tuple((long long) (k[i] + k[j]) * (abs(x[j] - x[i]) + abs(y[j] - y[i])), i, j));
    }
  }
  for (int i = 0; i < n; i++){
    E.push_back(make_tuple(c[i], i, n));
  }
  sort(E.begin(), E.end());
  unionfind UF(n + 1);
  long long ans = 0;
  int m = E.size();
  vector<int> st;
  vector<pair<int, int>> con;
  for (int i = 0; i < m; i++){
    long long cost = get<0>(E[i]);
    int u = get<1>(E[i]);
    int v = get<2>(E[i]);
    if (!UF.same(u, v)){
      UF.unite(u, v);
      ans += cost;
      if (v == n){
        st.push_back(u);
      } else {
        con.push_back(make_pair(u, v));
      }
    }
  }
  cout << ans << endl;
  int v = st.size();
  cout << v << endl;
  for (int i = 0; i < v; i++){
    cout << st[i] + 1;
    if (i < v - 1){
      cout << ' ';
    }
  }
  cout << endl;
  int e = con.size();
  cout << e << endl;
  for (int i = 0; i < e; i++){
    cout << con[i].first + 1 << ' ' << con[i].second + 1 << endl;
  }
}