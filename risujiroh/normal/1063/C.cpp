#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr int inf = 1e9;

int solve(int n, int y) {
  int l = 0, r = inf, res = (l + r) / 2;
  for (int _ = 0; _ < n; _++) {
    cout << res << ' ' << y << endl;
    string s; cin >> s;
    if (s == "white") {
      l = res;
    } else {
      r = res;
    }
    res = (l + r) / 2;
  }
  return res;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  int n0 = n / 2, n1 = n - n0;
  int x0 = solve(n0, 0);
  int x1 = solve(n1, 1);
  cout << x0 << ' ' << 0 << ' ' << x1 << ' ' << 1 << endl;
}