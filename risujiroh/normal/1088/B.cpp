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
  int n, k; cin >> n >> k;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  sort(begin(a), end(a));
  a.erase(unique(begin(a), end(a)), end(a));
  int i = 0;
  if (!a[i]) ++i;
  n = a.size();
  int t = 0;
  for (int _ = 0; _ < k; ++_) {
    cout << (i < n ? a[i] - t : 0) << '\n';
    if (i < n) t = a[i];
    ++i;
  }
}