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
  string s; cin >> s;
  lint res = 0;
  priority_queue< int, V<>, greater<int> > pque;
  for (int i = 0; i < n; ++i) {
    if (i == 0 or s[i] != s[i - 1]) {
      while (!pque.empty()) pque.pop();
    }
    pque.push(a[i]);
    res += a[i];
    if (pque.size() > k) {
      res -= pque.top();
      pque.pop();
    }
  }
  cout << res << '\n';
}