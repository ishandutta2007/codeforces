#include <bits/stdc++.h>
using namespace std;

template <class T> struct Deque {
  vector<T> l, r;
  void build(vector<T> v) {
    l = {rend(v) - v.size() / 2, rend(v)};
    r = {begin(v) + v.size() / 2, end(v)};
  }
  void push_front(T a) { l.push_back(a); }
  void push_back(T a) { r.push_back(a); }
  void pop_front() {
    if (l.empty()) build({++begin(r), end(r)});
    else l.pop_back();
  }
  void pop_back() {
    if (r.empty()) build({rbegin(l), --rend(l)});
    else r.pop_back();
  }
  size_t size() const { return l.size() + r.size(); }
  T& operator[](size_t i) {
    return i < l.size() ? l[l.size() - i - 1] : r[i - l.size()];
  }
  T& front() { return (*this)[0]; }
  T& back() { return (*this)[size() - 1]; }
  friend string to_string(Deque d) {
    string res = "{";
    for (size_t i = 0; i < d.size(); ++i) res += to_string(d[i]) + ", ";
    return res += "}";
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector< vector<int> > g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector< Deque<int> > d(n);
  auto dfs = [&](auto&& F, int v, int p) -> void {
    // d[v].build({v, v});
    d[v].push_back(v);
    d[v].push_back(v);
    for (int u : g[v]) {
      if (u != p) {
        F(F, u, v);
        if (d[v].size() < d[u].size()) {
          swap(d[v], d[u]);
          int fv = d[v].front();
          d[v].pop_front();
          int fu = d[u].front();
          d[u].pop_front();
          while (d[u].size()) {
            d[v].push_front(d[u].back());
            d[u].pop_back();
          }
          d[v].push_front(fv);
          d[v].push_front(fu);
        } else {
          int t = d[v].front();
          d[v].pop_front();
          d[v].push_front(d[u].front());
          d[u].pop_front();
          d[v].push_front(t);
          while (d[u].size()) {
            d[v].push_back(d[u].front());
            d[u].pop_front();
          }
        }
      }
    }
  };
  dfs(dfs, 0, -1);
  vector< vector<int> > res(n);
  for (int i = 0; i < 2 * n; ++i) {
    res[d[0][i]].push_back(i);
  }
  for (auto e : res) {
    cout << e[0] + 1 << ' ' << e[1] + 1 << '\n';
  }
}