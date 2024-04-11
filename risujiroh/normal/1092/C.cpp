#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<string> s(2 * (n - 1)); for (int i = 0; i < 2 * (n - 1); ++i) cin >> s[i];
  string pref, suff;
  for (const auto& str : s) {
    if (str.size() == n - 1) {
      (pref.empty() ? pref : suff) = str;
    }
  }
  struct P { int i; string s; };
  VV<P> a(n);
  for (int i = 0; i < 2 * (n - 1); ++i) {
    a[s[i].size()].push_back({i, s[i]});
  }
  auto chk = [&]() -> bool {
    if (pref.substr(1, n - 2) != suff.substr(0, n - 2)) return false;
    string t = pref + suff.back();
    for (int k = 1; k < n; ++k) {
      if (a[k][0].s == t.substr(0, k) and a[k][1].s == t.substr(n - k, k)) continue;
      if (a[k][1].s == t.substr(0, k) and a[k][0].s == t.substr(n - k, k)) continue;
      return false;
    }
    return true;
  };
  auto out = [&] {
    string t = pref + suff.back();
    string res(2 * (n - 1), 0);
    for (int k = 1; k < n; ++k) {
      if (a[k][0].s == t.substr(0, k) and a[k][1].s == t.substr(n - k, k)) {
        res[a[k][0].i] = 'P';
        res[a[k][1].i] = 'S';
      } else {
        res[a[k][0].i] = 'S';
        res[a[k][1].i] = 'P';
      }
    }
    cout << res << '\n';
  };
  if (chk()) {
    out();
    return 0;
  }
  swap(pref, suff);
  assert(chk());
  out();
}