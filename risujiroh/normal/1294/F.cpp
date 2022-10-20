#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << ' ' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> d(n), prv(n);
  vector<bool> vis(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    prv[v] = p;
    for (int u : g[v]) {
      if (u != p and not vis[u]) {
        d[u] = d[v] + 1;
        self(self, u, v);
      }
    }
  };
  d[0] = 0;
  dfs(dfs, 0, -1);
  int x = max_element(begin(d), end(d)) - begin(d);
  d[x] = 0;
  dfs(dfs, x, -1);
  int y = max_element(begin(d), end(d)) - begin(d);
  int res = d[y];
  for (int v = y; v != x; v = prv[v]) {
    vis[v] = true;
  }
  vis[x] = true;
  auto _prv = prv;
  for (int v = y; v != x; v = _prv[v]) {
    d[v] = 0;
    dfs(dfs, v, -1);
  }
  d[x] = d[y] = -1;
  int z = max_element(begin(d), end(d)) - begin(d);
  DEBUG(d);
  res += d[z];
  cout << res << '\n';
  cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
}