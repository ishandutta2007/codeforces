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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), rg(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  int k;
  cin >> k;
  vector<int> p(k);
  for (auto&& e : p) {
    cin >> e;
    --e;
  }
  vector<int> d(n, -1);
  d[p.back()] = 0;
  queue<int> que({p.back()});
  while (not que.empty()) {
    int v = que.front();
    que.pop();
    for (int u : rg[v]) {
      if (d[u] == -1) {
        d[u] = d[v] + 1;
        que.push(u);
      }
    }
  }
  DEBUG(d);
  for (int v = 0; v < n; ++v) {
    sort(begin(g[v]), end(g[v]), [&](int a, int b) {
      return d[a] < d[b];
    });
  }
  int mn = 0, mx = 0;
  for (int i = 0; i < k - 1; ++i) {
    int u = p[i], v = p[i + 1];
    DEBUG(d[u], d[v]);
    mn += d[u] - d[v] != 1;
    mx += not (d[u] - d[v] == 1 and (g[u].size() == 1 or d[g[u][1]] > d[v]));
  }
  cout << mn << ' ' << mx << '\n';
}