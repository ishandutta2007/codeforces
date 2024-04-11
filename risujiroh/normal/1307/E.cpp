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

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long a = 0) : v((a %= M) < 0 ? a + M : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= M) v -= M; return *this; }
  m& operator-=(m r) { if (v < r.v) v += M; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % M; return *this; }
  m& operator/=(m r) { return *this *= power(r, M - 2); }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend m operator/(m l, m r) { return l /= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
  friend string to_string(m a) { return to_string(a.v); };
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  for (auto&& e : s) {
    cin >> e;
    --e;
  }
  vector<int> lid(n, -1), rid(n, -1), id2l(m, -1), id2r(m, -1);
  for (int id = 0; id < m; ++id) {
    int f, h;
    cin >> f >> h;
    --f;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      t += s[i] == f;
      if (h == t) {
        lid[i] = id;
        id2l[id] = i;
        break;
      }
    }
    t = 0;
    for (int i = n; i--; ) {
      t += s[i] == f;
      if (h == t) {
        rid[i] = id;
        id2r[id] = i;
        break;
      }
    }
  }
  DEBUG(lid);
  DEBUG(rid);
  auto maximum = [](auto l, auto r) {
    if (l.first > r.first) {
      return l;
    }
    if (l.first < r.first) {
      return r;
    }
    return make_pair(l.first, l.second + r.second);
  };
  auto add = [](auto l, auto r) {
    return make_pair(l.first + r.first, l.second * r.second);
  };
  pair<int, mint> res{-1, 0};
  vector<int> v;
  vector<vector<int>> l(n), r(n);
  for (int id = 0; id < m; ++id) {
    if (id2r[id] != -1) {
      r[s[id2r[id]]].push_back(id);
    }
  }
  for (int k = 0; k <= n; ++k) {
    if (k) {
      if (lid[k - 1] != -1) {
        l[s[k - 1]].insert(lower_bound(begin(l[s[k - 1]]), end(l[s[k - 1]]), lid[k - 1]), lid[k - 1]);
      }
      if (rid[k - 1] != -1) {
        r[s[k - 1]].erase(lower_bound(begin(r[s[k - 1]]), end(r[s[k - 1]]), rid[k - 1]));
      }
    }
    if (k < n and rid[k] == -1) {
      continue;
    }
    // for (int id = 0; id < m; ++id) {
    //   if (k < n and rid[k] == id) {
    //     continue;
    //   }
    //   if (id2l[id] != -1 and id2l[id] < k) {
    //     l[s[id2l[id]]].push_back(id);
    //   }
    //   if (id2r[id] != -1 and id2r[id] >= k) {
    //     r[s[id2r[id]]].push_back(id);
    //   }
    // }
    pair<int, mint> cur{0, 1};
    for (int c = 0; c < n; ++c) {
      if (k < n and s[k] == c) {
        if (l[c].size() >= 2 or (l[c].size() == 1 and l[c][0] != rid[k])) {
          cur = add(cur, make_pair<int, mint>(2, l[c].size() - (id2l[rid[k]] != -1 and id2l[rid[k]] < k)));
        } else {
          cur = add(cur, make_pair<int, mint>(1, 1));
        }
      } else {
        v.clear();
        set_intersection(begin(l[c]), end(l[c]), begin(r[c]), end(r[c]), back_inserter(v));
        if (l[c].size() * r[c].size() - v.size()) {
          cur = add(cur, make_pair<int, mint>(2, l[c].size() * r[c].size() - v.size()));
        } else if (not l[c].empty() or not r[c].empty()) {
          cur = add(cur, make_pair<int, mint>(1, l[c].size() + r[c].size()));
        }
      }
    }
    DEBUG(k, cur);
    res = maximum(res, cur);
  }
  cout << res.first << ' ' << res.second.v << '\n';
}