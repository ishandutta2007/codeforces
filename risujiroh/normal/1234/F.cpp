#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> void fzt(V<T>& a) {
  int n = a.size();
  assert(__builtin_popcount(n) == 1);
  for (int i = 0; 1 << i < n; ++i) {
    for (int S = 0; S < n; ++S) if (~S & 1 << i) {
      a[S | 1 << i] = max(a[S | 1 << i], a[S]);
    }
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  V<> a(1 << 20);
  for (int i = 0; i < n; ++i) {
    int S = 0;
    for (int j = i; j < min(i + 20, n); ++j) {
      if (S >> s[j] - 'a' & 1) break;
      S |= 1 << s[j] - 'a';
      ++a[S];
    }
  }
  for (int S = 0; S < 1 << 20; ++S) if (a[S]) {
    a[S] = __builtin_popcount(S);
  }
  auto c = a;
  fzt(c);
  int res = 0;
  for (int S = 0; S < 1 << 20; ++S) if (a[S]) {
    res = max(res, a[S] + c[~(~0U << 20) ^ S]);
  }
  cout << res << '\n';
}