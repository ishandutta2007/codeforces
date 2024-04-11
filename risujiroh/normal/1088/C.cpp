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
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  cout << n + 1 << '\n';
  for (int i = n - 1; i >= 0; --i) {
    cout << "1 " << i + 1 << ' ' << n + i - a[i] % n << '\n';
    for (int j = 0; j < i; ++j) a[j] += n + i - a[i] % n;
  }
  cout << "2 " << n << ' ' << n << endl;
}