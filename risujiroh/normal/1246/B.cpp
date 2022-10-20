#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  map< V< pair<int, int> >, int> mp;
  lint res = 0;
  while (n--) {
    int a; cin >> a;
    V< pair<int, int> > v, w;
    for (const auto& e : factorize(a)) {
      if (e.second % k) {
        v.emplace_back(e.first, e.second % k);
        w.emplace_back(e.first, k - e.second % k);
      }
    }
    if (mp.count(w)) {
      res += mp[w];
    }
    ++mp[v];
  }
  cout << res << '\n';
}