#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> c(n + 1);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    c[i + 1] = c[i] ^ a;
  }

  V<> o(1 << 20), e(1 << 20);
  lint res = 0;
  for (int i = 0; i <= n; ++i) {
    res += (i & 1 ? o : e)[c[i]]++;
  }
  cout << res << '\n';
}