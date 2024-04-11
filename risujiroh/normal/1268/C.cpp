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

template<class T> struct FenwickTree {
  const int n;
  vector<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  int lower_bound(T s) const {
    if (s <= 0) return 0;
    int i = 0;
    for (int k = 1 << __lg(n); k; k >>= 1) {
      if (i + k <= n and t[i + k] < s) s -= t[i += k];
    }
    return i + 1;
  }
  int kth(T k) const { return lower_bound(k + 1) - 1; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> p(n), ip(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    ip[p[i]] = i;
  }
  vector<long long> res(n);
  {
    FenwickTree<int> ft(n);
    vector<int> r(n);
    for (int i = n; i--; ) {
      r[i] = ft.sum(p[i]);
      ft.add(p[i], 1);
    }
    for (int i = 0; i < n; ++i) {
      res[i] = (i ? res[i - 1] : 0) + r[ip[i]];
    }
  }
  FenwickTree<int> ft(n);
  long long sum = 0;
  for (int x = 0; x < n; ++x) {
    int i = ip[x];
    if (x & 1) {
      int m = ft.kth(x / 2);
      if (i < m) {
        sum += (m - i - 1) - ft.sum(i + 1, m);
        sum -= ft.sum(i);
      } else {
        assert(m < i);
        sum += (i - m) - ft.sum(m, i);
        sum -= ft.sum(i, n);
      }
    } else if (x) {
      int l = ft.kth(x / 2 - 1);
      int r = ft.kth(x / 2);
      assert(i != l and i != r);
      if (i < l) {
        sum += (l - i - 1) - ft.sum(i + 1, l);
        sum -= ft.sum(i);
      } else if (r < i) {
        sum += (i - r) - ft.sum(r, i);
        sum -= ft.sum(i, n);
      } else {
        sum -= x / 2;
      }
    }
    DEBUG(x, sum);
    ft.add(i, 1);
    res[x] += sum;
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i == n - 1];
  }
}