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
  lint n; cin >> n;
  auto mp = factorize(n);
  if (mp.size() == 1) {
    cout << begin(mp)->first << '\n';
  } else {
    cout << 1 << '\n';
  }
}