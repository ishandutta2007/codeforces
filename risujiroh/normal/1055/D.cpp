#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<string> s(n); for (int i = 0; i < n; ++i) cin >> s[i];
  V<string> t(n); for (int i = 0; i < n; ++i) cin >> t[i];
  string d;
  V<string> head, tail;
  for (int i = 0; i < n; ++i) if (s[i] != t[i]) {
    int l = 0;
    while (s[i][l] == t[i][l]) ++l;
    int r = s[i].size();
    while (s[i][r - 1] == t[i][r - 1]) --r;
    if (d.size() and d != s[i].substr(l, r - l)) return cout << "NO" << '\n', 0;
    d = s[i].substr(l, r - l);
    head.push_back(s[i].substr(0, l));
    tail.push_back(s[i].substr(r, s[i].size() - r));
  }
  for (auto&& e : head) reverse(begin(e), end(e));
  string chead;
  for (int i = 0; i < 3000; ++i) {
    char c = '.';
    bool ok = true;
    for (const auto& str : head) {
      if (i >= str.size() or c != '.' and str[i] != c) {
        ok = false;
        break;
      }
      c = str[i];
    }
    if (ok) chead += c;
    else break;
  }
  string ctail;
  for (int i = 0; i < 3000; ++i) {
    char c = '.';
    bool ok = true;
    for (const auto& str : tail) {
      if (i >= str.size() or c != '.' and str[i] != c) {
        ok = false;
        break;
      }
      c = str[i];
    }
    if (ok) ctail += c;
    else break;
  }
  reverse(begin(chead), end(chead));
  d = chead + d + ctail;
  string d_;
  for (int i = 0; i < n; ++i) if (s[i] != t[i]) {
    int l = 0;
    while (s[i][l] == t[i][l]) ++l;
    int r = s[i].size();
    while (s[i][r - 1] == t[i][r - 1]) --r;
    d_ = chead + t[i].substr(l, r - l) + ctail;
    break;
  }
  for (int i = 0; i < n; ++i) {
    if (s[i].find(d) != string::npos) {
      auto str = s[i];
      str.replace(s[i].find(d), d.size(), d_);
      if (str != t[i]) return cout << "NO" << '\n', 0;
    }
  }
  cout << "YES" << '\n';
  cout << d << '\n';
  cout << d_ << '\n';
}