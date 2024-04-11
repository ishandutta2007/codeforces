#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, k; cin >> n >> k;
  auto query = [&](lint l, lint r) {
    l = max(l, 1LL), r = min(r, n);
    cout << l << ' ' << r << endl;
    string s; cin >> s;
    if (l == r and s == "Yes") exit(0);
    return s == "Yes";
  };
  mt19937 mt(time(NULL));
  lint l = 1, r = n;
  while(true) {
    if (r - l < 100) {
      lint d = mt() % (r - l + 1);
      query(l + d, l + d);
      l = max(l - k, 1LL);
      r = min(r + k, n);
      continue;
    }
    lint m = (l + r) / 2;
    if (query(l, m)) {
      l = max(l - k, 1LL);
      r = min(m + k, n);
    } else {
      l = max(m - k, 1LL);
      r = min(r + k, n);
    }
  }
}