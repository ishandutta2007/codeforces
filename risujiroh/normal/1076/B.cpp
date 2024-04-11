#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> map<Int, int> factor(Int n) {
  map<Int, int> res;
  for (Int i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint n; cin >> n;
  auto mp = factor(n);
  lint p = begin(mp)->first;
  if (p == 2) cout << n / 2 << '\n';
  else cout << (n - begin(mp)->first) / 2 + 1 << '\n';
}