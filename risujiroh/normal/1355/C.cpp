#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

constexpr int lim = 1e6;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<long long> cnt(lim + 2);
  for (int x = a; x <= b; ++x) {
    ++cnt[x + b];
    --cnt[x + c + 1];
  }
  for (int i = 0; i <= lim; ++i) {
    cnt[i + 1] += cnt[i];
  }
  auto res = 0LL;
  for (int i = 0; i <= lim; ++i) {
    res += cnt[i] * max(min(d, i - 1) - c + 1, 0);
  }
  cout << res << '\n';
}