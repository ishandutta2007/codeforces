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
  vector<vector<int>> v(m, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      --a;
      if (a % m == j and a / m < n) {
        a /= m;
      } else {
        a = -1;
      }
      v[j][i] = a;
    }
  }
  int res = 0;
  for (auto e : v) {
    DEBUG(e);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      if (e[i] != -1) {
        ++c[(i + (n - e[i])) % n];
      }
    }
    DEBUG(c);
    int mn = n;
    for (int k = 0; k < n; ++k) {
      mn = min(mn, k + (n - c[k]));
    }
    res += mn;
  }
  cout << res << '\n';
}