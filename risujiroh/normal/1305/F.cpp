#include <bits/stdc++.h>
using namespace std;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

template <class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  shuffle(begin(a), end(a), mt);
  auto f = [&](long long d) {
    if (d < 2) {
      return n;
    }
    long long res = 0;
    for (auto e : a) {
      auto le = e / d * d, ge = (e + d - 1) / d * d;
      res += min(le ? e - le : n, ge - e);
      if (res >= n) {
        return n;
      }
    }
    return (int)res;
  };
  set<long long> se;
  for (int i = 0; i < min(n, 30); ++i) {
    for (int j = -1; j <= 1; ++j) {
      for (auto e : factorize(a[i] + j)) {
        se.insert(e.first);
      }
    }
  }
  int res = n;
  for (auto e : se) {
    res = min(res, f(e));
  }
  cout << res << '\n';
}