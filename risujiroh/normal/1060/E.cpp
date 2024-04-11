#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v, u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> par(n, -1);
  queue<int> que;
  par[0] = -2; que.push(0);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int w : g[v]) if (par[w] == -1) {
      par[w] = v; que.push(w);
    }
  }
  VV<> ch(n);
  for (int v = 1; v < n; v++) ch[par[v]].push_back(v);
  struct data { lint sum; lint odd, even; data(lint sum = 0, lint odd = 0, lint even = 0) : sum(sum), odd(odd), even(even) {} };
  V<data> a(n);
  V<lint> res(n);
  function<void(int)> dfs = [&](int v) {
    for (int w : ch[v]) dfs(w);
    lint so = 0, se = 0;
    for (int w : ch[v]) {
      a[v].sum += a[w].sum + a[w].odd + a[w].even + 1;
      a[v].odd += a[w].even + 1;
      a[v].even += a[w].odd;
      res[v] += res[w];
      so += a[w].odd;
      se += a[w].even + 1;
    }
    res[v] += (a[v].sum + a[v].odd) / 2;
    // if (!v) cerr << v << ' ' << so << ' ' << se << '\n';
    lint s = 0, sodd = 0;
    for (int w : ch[v]) {
      s += (a[w].sum + a[w].odd + a[w].even + 1) * (se + so - a[w].odd - a[w].even - 1);
      sodd += a[w].odd * (se - a[w].even - 1) + (a[w].even + 1) * (so - a[w].odd);
    }
    s = (s + sodd / 2) / 2;
    res[v] += s;
  };
  dfs(0);
  cout << res[0] << '\n';
  // for (int i = 0; i < n; i++) cerr << i << ' ' << a[i].sum << ' ' << a[i].odd << ' ' << a[i].even << '\n';
  // cerr << "res" << '(' << res.size() << ") = {"; for (auto&& i : res) cerr << i << ", "; cerr << "} (l." << __LINE__ << ")\n";
}