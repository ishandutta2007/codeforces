#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, l, r;
    cin >> n >> l >> r;
    --l;
    vector<long long> head(n + 1);
    for (int i = 0; i < n; ++i) {
      head[i + 1] = head[i] + 2 * (n - i - 1);
    }
    ++head.back();
    DEBUG(head);
    auto fn = [&](auto i) -> int{
      int j = upper_bound(begin(head), end(head), i) - begin(head) - 1;
      i -= head[j];
      if (j < n - 1) {
        if (i & 1) {
          return j + i / 2 + 1;
        } else {
          return j;
        }
      }
      return 0;
    };
    for (auto i = l; i < r; ++i) {
      cout << fn(i) + 1 << " \n"[i == r - 1];
    }
  }
}