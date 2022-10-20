#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

struct rolling_hash {
  static constexpr uint64_t mod = 2e9 + 33;
  static long long base[2];
  static vector<int> powb[2];
  vector<int> h[2];
  template <class S = string> rolling_hash(const S& s = "") : h{{0}, {0}} {
    assert(all_of(begin(s), end(s), [](uint64_t c) { return c < mod; }));
    for (int k : {0, 1}) {
      for (auto c : s) h[k].push_back((h[k].back() * base[k] + c) % mod);
      while (powb[k].size() <= s.size())
        powb[k].push_back(powb[k].back() * base[k] % mod);
    }
  }
  int get(int l, int r, int k) const {
    return (h[k][r] + (mod - h[k][l]) * powb[k][r - l]) % mod;
  }
  auto get(int l, int r) const { return make_pair(get(l, r, 0), get(l, r, 1)); }
  int size() const { return h[0].size() - 1; }
};
long long rolling_hash::base[]{rng<int>(1e9, 2e9), rng<int>(1e9, 2e9)};
vector<int> rolling_hash::powb[]{{1}, {1}};

auto concat(pair<int, int> a, pair<int, int> b, int len) {
  int h0 = ((uint64_t)a.first * rolling_hash::powb[0][len] + b.first) % rolling_hash::mod;
  int h1 = ((uint64_t)a.second * rolling_hash::powb[1][len] + b.second) % rolling_hash::mod;
  return make_pair(h0, h1);
}

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

template <class T> struct sparse_table {
  vector<vector<T>> t;
  sparse_table(const vector<T>& v = {}) : t{v} {
    for (int k = 1, n = v.size(); 1 << k <= n; ++k) {
      t.emplace_back(n - (1 << k) + 1);
      for (int i = 0; i + (1 << k) <= n; ++i)
        t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }
  }
  T fold(int l, int r) const {
    if (l >= r) {
      return {inf<int>, -1};
    }
    int k = __lg(r - l);
    return min(t[k][l], t[k][r - (1 << k)]);
  }
};

template <class T> struct segtree {
  const int n;
  vector<T> t;
  segtree(int _n = 0) : n(_n), t(2 * n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  T fold(int l, int r) const {
    if (l >= r) {
      return T();
    }
    T a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
};
template <class T> struct mini {
  T v = inf<T>;
  int i = -1;
  mini operator*(mini b) const {
    return b.v < v ? b : *this;
  }
};

constexpr int th = 128;

struct stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  void operator()(string s = "Time") const {
    cerr << s + ": " << elapsed() << " ms\n";
  }
} sw;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = size(s), m = size(t);
  rolling_hash rs(s), rt(t);
  auto h = [&](int i, int len) {
    if (len <= i) {
      return rs.get(0, len);
    }
    if (len <= i + m) {
      return concat(rs.get(0, i), rt.get(0, len - i), len - i);
    }
    return concat(concat(rs.get(0, i), rt.get(0, m), m), rs.get(i, len - m), len - m - i);
  };
  auto at = [&](int i, int pos) {
    if (pos < i) {
      return s[pos];
    }
    if (pos < i + m) {
      return t[pos - i];
    }
    return s[pos - m];
  };
  vector<int> ord(n + 1);
  iota(begin(ord), end(ord), 0);
  stable_sort(begin(ord), end(ord), [&](int i, int j) {
    int ok = 0, ng = n + m + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (h(i, mid) == h(j, mid) ? ok : ng) = mid;
    }
    return at(i, ok) < at(j, ok);
  });
  vector<pair<int, int>> v(n + 1);
  for (int k = 0; k <= n; ++k) {
    v[ord[k]] = {k, ord[k]};
  }
  sparse_table st(v);
  vector<vector<segtree<mini<int>>>> sts(th);
  for (int k = 1; k < th; ++k) {
    for (int j = 0; j < k; ++j) {
      vector<pair<int, int>> nv;
      for (int i = j; i <= n; i += k) {
        nv.push_back(v[i]);
      }
      sts[k].emplace_back(size(nv));
      for (int i = 0; i < sts[k][j].n; ++i) {
        sts[k][j][i] = {nv[i].first, nv[i].second};
      }
      sts[k][j].build();
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, k, x, y;
    cin >> l >> r >> k >> x >> y;
    ++r, ++y;
    int mi = -1;
    if (k < th) {
      for (int j = x; j < y; ++j) {
        auto [cur, i] = sts[k][j].fold((l - j + k - 1) / k, (r - j + k - 1) / k);
        if (i == -1) continue;
        if (mi == -1 or cur < v[mi].first or (cur == v[mi].first and i < mi)) {
          mi = i;
        }
      }
    } else {
      for (int xx = x, yy = y; xx <= n; xx += k, yy += k) {
        auto [cur, i] = st.fold(max(xx, l), min(yy, r));
        if (i == -1) continue;
        if (mi == -1 or cur < v[mi].first) {
          mi = i;
        }
      }
    }
    cout << mi << " \n"[q == 0];
  }
  sw();
}