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
  int n; cin >> n;
  int ng = -1, ok = 1e9 + 1;
  int q = 60;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    cout << "> " << mid << endl;
    int r; cin >> r;
    --q;
    (r ? ng : ok) = mid;
  }
  q = min(q, n);
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  shuffle(begin(idx), end(idx), mt19937(chrono::steady_clock::now().time_since_epoch().count()));
  V<> a;
  for (int i = 0; i < q; ++i) {
    cout << "? " << idx[i] + 1 << endl;
    int r; cin >> r;
    a.push_back(r);
  }
  sort(begin(a), end(a));
  int mn = a[0];
  for (auto&& e : a) {
    e -= mn;
  }
  auto gcd = [](int x, int y) { return __gcd(x, y); };
  int d = accumulate(begin(a), end(a), 0, gcd);
  cout << "! " << ok - (n - 1) * d << ' ' << d << endl;
}