#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

vector<int> min_factor;
void prepare(int n) {
  min_factor.assign(n + 1, 0);
  for (int p = 2; p <= n; ++p) {
    if (min_factor[p]) continue;
    for (int i = p; i <= n; i += p)
      if(min_factor[i] == 0) min_factor[i] = p;
  }
}
vector<int> factors(int n) {
  vector<int> res;
  while (int d = min_factor[n])
    res.push_back(d), n /= d;
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  prepare(n);
  long long m = n - 1;
  for (int i = n / 2 + 1; i <= n; ++i) {
    m -= min_factor[i] == i;
  }
  long long res = m * (m - 1) / 2;
  vector<int> cum(n + 2);
  for (int i = n; i >= 2; --i) {
    cum[i] = (min_factor[i] == i) + cum[i + 1];
  }
  for (int i = 2; i <= n; ++i) {
    if (i <= n / 2 or min_factor[i] < i) {
      auto ps = factors(i);
      ps.erase(unique(begin(ps), end(ps)), end(ps));
      int totient = i;
      for (int p : ps) {
        totient /= p;
        totient *= p - 1;
      }
      int cur = totient - 1;
      if (i > n / 2) {
        cur -= cum[n / 2 + 1] - cum[i];
      }
      res += cur;
    }
  }
  vector<int> cnt(n + 2);
  for (int i = 2; i <= n; ++i) {
    if (i <= n / 2 or min_factor[i] < i) {
      ++cnt[min_factor[i]];
    }
  }
  for (int i = n; i >= 2; --i) {
    cnt[i] += cnt[i + 1];
  }
  long long cur = 0;
  for (int i = 2; i <= n; ++i) {
    if (i <= n / 2 or min_factor[i] < i) {
      int lb = n / min_factor[i] + 1;
      cur += cnt[lb];
      cur -= lb <= min_factor[i];
    }
  }
  cur /= 2;
  res += cur;
  cout << res << '\n';
}