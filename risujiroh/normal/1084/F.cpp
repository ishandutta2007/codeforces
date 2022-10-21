#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
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

template <class T, T Op(T, T), T E()> struct SegmentTree {
  const int n;
  vector<T> t;
  SegmentTree(int _n) : n(_n), t(2 * n, E()) {}
  T& operator[](int i) { return t[n + i]; }
  void build() {
    for (int i = n - 1; i >= 1; --i) t[i] = Op(t[2 * i], t[2 * i + 1]);
  }
  T fold(int l, int r) const {
    T a = E(), b = E();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = Op(a, t[l++]);
      if (r & 1) b = Op(t[--r], b);
    }
    return Op(a, b);
  }
  void set(int i, const T& a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = Op(t[2 * i], t[2 * i + 1]);
  }
};

using P = pair<int, int>;
template <class T> T _min(T a, T b) { return b < a ? b : a; }
int _max(int a, int b) { return a < b ? b : a; }
int inf() { return 0x3f3f3f3f; }
int ninf() { return -0x3f3f3f3f; }
P P_inf() { return {0x3f3f3f3f, -1}; }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto&& e : p) {
    cin >> e;
  }
  vector<int> par(n);
  vector< vector<int> > g(n);
  for (int v = 1; v < n; ++v) {
    cin >> par[v];
    --par[v];
    g[par[v]].push_back(v);
  }
  vector<int> sz(n), dep(n);
  {
    auto dfs = [&](auto& F, int v) -> void {
      sz[v] = 1;
      for (int u : g[v]) {
        dep[u] = dep[v] + 1;
        F(F, u);
        sz[v] += sz[u];
      }
      sort(begin(g[v]), end(g[v]), [&](int l, int r) {
        return sz[l] > sz[r];
      });
    };
    dfs(dfs, 0);
  }
  SegmentTree<P, _min, P_inf> pdv(n);
  for (int v = 0; v < n; ++v) {
    pdv[p[v]] = {dep[v], v};
  }
  pdv.build();
  vector<int> in(n), iin(n), anc(n);
  {
    int t = 0;
    auto dfs = [&](auto& F, int v) -> void {
      in[v] = t++;
      iin[in[v]] = v;
      for (int u : g[v]) {
        anc[u] = u == g[v][0] ? anc[v] : u;
        F(F, u);
      }
    };
    dfs(dfs, 0);
  }
  vector<int> rin(n), irin(n);
  {
    int t = 0;
    auto dfs = [&](auto& F, int v) -> void {
      rin[v] = t++;
      irin[rin[v]] = v;
      for (int u : vector<int>(rbegin(g[v]), rend(g[v]))) {
        F(F, u);
      }
    };
    dfs(dfs, 0);
  }
  for (int v = 0; v < n; ++v) {
    DEBUG(v, g[v]);
  }
  DEBUG(in);
  DEBUG(iin);
  DEBUG(rin);
  DEBUG(irin);
  SegmentTree<int, _max, ninf> pin(n);
  SegmentTree<int, _max, ninf> prin(n);
  for (int v = 0; v < n; ++v) {
    pin[p[v]] = in[v];
    prin[p[v]] = rin[v];
  }
  pin.build();
  prin.build();
  SegmentTree<int, _min, inf> st(n);
  for (int v = 0; v < n; ++v) {
    st[in[v]] = p[v];
  }
  st.build();
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      swap(p[u], p[v]);
      pdv.set(p[u], {dep[u], u});
      pdv.set(p[v], {dep[v], v});
      pin.set(p[u], in[u]);
      pin.set(p[v], in[v]);
      prin.set(p[u], rin[u]);
      prin.set(p[v], rin[v]);
      st.set(in[u], p[u]);
      st.set(in[v], p[v]);
    } else {
      auto chk = [&](int mid) {
        int u = irin[prin.fold(0, mid)];
        int v = iin[pin.fold(0, mid)];
        if (u == v) {
          v = pdv.fold(0, mid).second;
        }
        DEBUG(q, mid, u, v);
        vector<int> idx{n};
        while (true) {
          if (in[u] > in[v]) {
            swap(u, v);
          }
          if (anc[u] == anc[v]) {
            idx.push_back(in[v] + 1);
            idx.push_back(in[u]);
            break;
          }
          idx.push_back(in[v] + 1);
          idx.push_back(in[anc[v]]);
          v = par[anc[v]];
        }
        idx.push_back(0);
        reverse(begin(idx), end(idx));
        int mn = inf();
        for (int t = 0; t < (int)idx.size(); t += 2) {
          mn = min(mn, st.fold(idx[t], idx[t + 1]));
        }
        return mn >= mid;
      };
      int ok = 2, ng = n + 1;
      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        (chk(mid) ? ok : ng) = mid;
      }
      cout << ok << '\n';
      DEBUG(ok);
    }
  }
  DEBUG(p);
  for (int i = 0; i < n; ++i) {
    DEBUG(i, pin[i], prin[i]);
  }
}