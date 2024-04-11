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
    int n, m, k;
    cin >> n >> m >> k;
    --m;
    k = min(k, m);
    vector<int> a(n);
    for_each(begin(a), end(a), [](int& e) { cin >> e; });
    int res = 0;
    for (int l = 0; l <= k; ++l) {
      int r = k - l;
      int crr = 0x3f3f3f3f;
      for (int i = l; i < n - r; ++i) {
        int j = i + n - m - 1;
        // DEBUG(i, j);
        if (j >= n - r) {
          continue;
        }
        crr = min(crr, max(a[i], a[j]));
      }
      // DEBUG(l, r, crr);
      res = max(res, crr);
    }
    cout << res << '\n';
  }
}