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

constexpr int lim = 2e3;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<array<int, 3>> g(lim + 1);
    for (int i = 1; i <= lim; ++i) {
      for (int t = 0; t < 3; ++t) {
        set<int> se;
        se.insert(g[max(i - x, 0)][0]);
        if (t != 1) {
          se.insert(g[max(i - y, 0)][1]);
        }
        if (t != 2) {
          se.insert(g[max(i - z, 0)][2]);
        }
        for (int r = 0; ; ++r) {
          if (not se.count(r)) {
            g[i][t] = r;
            break;
          }
        }
      }
    }
    int len = -1;
    for (int d = lim / 4; ; --d) {
      bool ok = true;
      for (int i = 0; i < d; ++i) {
        if (g[lim - i] != g[lim - d - i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        // DEBUG(x, y, z, d);
        len = d;
        break;
      }
    }
    auto f = [&](long long a) {
      if (a <= lim) {
        return a;
      }
      return a - (a - lim / 2) / len * len;
    };
    vector<long long> a(n);
    int xr = 0;
    for (auto&& e : a) {
      cin >> e;
      xr ^= g[f(e)][0];
    }
    int res = 0;
    for (auto e : a) {
      res += g[f(max(e - x, 0ll))][0] == (xr ^ g[f(e)][0]);
      res += g[f(max(e - y, 0ll))][1] == (xr ^ g[f(e)][0]);
      res += g[f(max(e - z, 0ll))][2] == (xr ^ g[f(e)][0]);
    }
    cout << res << '\n';
  }
}