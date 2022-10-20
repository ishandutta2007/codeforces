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
  VV<> a; assign(a, n, 2, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i][0] >> a[i][1], --a[i][0], --a[i][1];
  }
  if (n == 3) return cout << "1 2 3" << '\n', 0;
  V<> res{0};
  for (int i = 0; res.size() < n;) {
    int i0 = a[i][0], i1 = a[i][1];
    if (a[i0][0] == i1 or a[i0][1] == i1) {
      res.push_back(i = i0);
    } else {
      res.push_back(i = i1);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] + 1 << (i != n - 1 ? ' ' : '\n');
  }
}