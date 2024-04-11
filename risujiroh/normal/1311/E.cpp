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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    int lower = 0, upper = n * (n - 1) / 2;
    for (int i = 0; i < n; ++i) {
      lower += __lg(i + 1);
    }
    if (d < lower or upper < d) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> c(n, 1);
    int sum = upper;
    while (sum > d) {
      // for (int x = n; x-- > 2; ) {
      for (int x = 2; x < n; ++x) {
        if (c[x] and c[x - 1] < 2 * c[x - 2]) {
          if (x + 1 < n and 2 * (c[x] - 1) < c[x + 1]) {
            continue;
          }
          --c[x];
          ++c[x - 1];
          --sum;
          break;
        }
      }
      DEBUG(c);
    }
    DEBUG(c);
    for (int x = 1; x < n; ++x) {
      d -= x * c[x];
      // assert(c[x] <= 2 * c[x - 1]);
    }
    assert(d == 0);
    vector<vector<int>> vs(n);
    int v = 0;
    vector<int> res(n);
    for (int x = 0; x < n; ++x) {
      while (c[x]--) {
        vs[x].push_back(v++);
      }
      if (x == 0) {
        continue;
      }
      for (int i = 0; i < (int)vs[x].size(); ++i) {
        res[vs[x][i]] = vs[x - 1][i / 2];
      }
    }
    for (v = 1; v < n; ++v) {
      cout << res[v] + 1 << " \n"[v == n - 1];
    }
  }
}