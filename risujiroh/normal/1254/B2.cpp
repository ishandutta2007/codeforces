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

constexpr lint inf = 9e18;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n);
  lint sum = 0;
  for (auto&& e : a) {
    cin >> e;
    sum += e;
  }
  lint res = inf;
  for (const auto& p : factorize(sum)) {
    lint d = p.first;
    lint s = 0, crr = 0;
    for (int e : a) {
      s = (s + e) % d;
      crr += min(s, d - s);
    }
    res = min(res, crr);
  }
  cout << (res < inf ? res : -1) << '\n';
}