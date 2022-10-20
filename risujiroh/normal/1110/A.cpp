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
  int b, k; cin >> b >> k;
  V<> a(k); for (int i = 0; i < k; ++i) cin >> a[i];
  if (b & 1) {
    cout << (accumulate(begin(a), end(a), 0) & 1 ? "odd" : "even") << '\n';
  } else {
    cout << (a.back() & 1 ? "odd" : "even") << '\n';
  }
}