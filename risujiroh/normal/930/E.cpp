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
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

template <class T, class Op = multiplies<T>>
T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long x = 0) : v((x %= M) < 0 ? x + M : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((v += b.v) >= M) v -= M; return *this; }
  m& operator-=(m b) { if (v < b.v) v += M; v -= b.v; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % M; return *this; }
  m& operator/=(m b) { return *this *= power(b, M - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

template <class T> struct fenwick {
  const int n;
  vector<T> t;
  fenwick(int _n = -1) : n(_n), t(n + 1) {}
  void add(int i, T a) { for (++i; i <= n; i += i & -i) t[i] += a; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  T get(int i) const { return sum(i, i + 1); }
};

pair<vector<int>, vector<int>> pre(int n) {
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    --l[i];
  }
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return l[i] != l[j] ? l[i] < l[j] : r[i] > r[j];
  });
  stack<int> st;
  for (int i : ord) {
    while (not empty(st) and r[st.top()] >= r[i]) {
      st.pop();
    }
    st.push(i);
  }
  vector<int> nl, nr;
  while (not empty(st)) {
    nl.push_back(l[st.top()]);
    nr.push_back(r[st.top()]);
    st.pop();
  }
  reverse(begin(nl), end(nl));
  reverse(begin(nr), end(nr));
  return {nl, nr};
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int k, n, m;
  cin >> k >> n >> m;
  vector<vector<int>> l(2);
  vector<vector<int>> r(2);
  tie(l[0], r[0]) = pre(n);
  tie(l[1], r[1]) = pre(m);
  DEBUG(l[0]);
  DEBUG(r[0]);
  DEBUG(l[1]);
  DEBUG(r[1]);
  n = l[0].size();
  m = l[1].size();
  vector<int> v{0, k};
  for (int i = 0; i < 2; ++i) {
    v.insert(end(v), begin(l[i]), end(l[i]));
    v.insert(end(v), begin(r[i]), end(r[i]));
  }
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
  auto zip = [&](int x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
  };
  int w = v.size();
  vector dp(2, vector(2, fenwick<mint>(w)));
  vector dp2(2, vector(2, fenwick<mint>(w)));
  vector<int> ord(n + m);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return (i < n ? r[0][i] : r[1][i - n]) < (j < n ? r[0][j] : r[1][j - n]);
  });
  dp[0][0].add(0, 1);
  dp2[0][0].add(0, 1);
  for (int i : ord) {
    for (int p : {0, 1}) {
      if (i < n) {
        mint cur;
        int a = zip(l[0][i]) + 1, b = zip(r[0][i]);
        for (int t : {0, 1}) {
          cur += dp2[t][p ^ 1].sum(a);
        }
        cur *= power<mint>(2, v[a - 1]);
        cur += dp[0][p ^ 1].sum(a, b);
        dp[0][p].add(b, cur);
        dp2[0][p].add(b, cur / power<mint>(2, v[b]));
      } else {
        int j = i - n;
        mint cur;
        int a = zip(l[1][j]) + 1, b = zip(r[1][j]);
        for (int t : {0, 1}) {
          cur += dp2[t][p ^ 1].sum(a);
        }
        cur *= power<mint>(2, v[a - 1]);
        cur += dp[1][p ^ 1].sum(a, b);
        dp[1][p].add(b, cur);
        dp2[1][p].add(b, cur / power<mint>(2, v[b]));
      }
    }
  }
  mint res;
  for (int i = 0; i < w; ++i) {
    for (int t : {0, 1}) {
      for (int p : {0, 1}) {
        DEBUG(i, v[i], t, p, dp[t][p].get(i).v);
        res += power(-1, p) * dp[t][p].get(i) * power<mint>(2, k - v[i]);
      }
    }
    DEBUG();
  }
  cout << res.v << '\n';
}