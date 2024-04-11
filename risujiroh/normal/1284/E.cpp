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

using R = long double;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> xs(n), ys(n);
  for (int i = 0; i < n; ++i) {
    cin >> xs[i] >> ys[i];
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += (long long)(n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    vector<R> th(n);
    vector<int> idx;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        th[j] = atan2<R>(ys[j] - ys[i], xs[j] - xs[i]);
        idx.push_back(j);
      }
    }
    sort(begin(idx), end(idx), [&](int l, int r) {
      return th[l] < th[r];
    });
    auto det = [&](int l, int r) {
      r %= n - 1;
      return (xs[idx[l]] - xs[i]) * (ys[idx[r]] - ys[i]) - (ys[idx[l]] - ys[i]) * (xs[idx[r]] - xs[i]);
    };
    int r = 0;
    for (int l = 0; l < n - 1; ++l) {
      while (r < l + (n - 1) and det(l, r) >= 0) {
        ++r;
      }
      long long x = max(r - l - 1, 0);
      res -= x * (x - 1) * (x - 2) / 6;
    }
  }
  cout << res << '\n';
}