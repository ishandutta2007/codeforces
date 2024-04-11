#include <bits/extc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.h"
#else
#define DUMP(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  using ll = long long;
  ll n;
  cin >> n;
  ll a = 1, b = 2, res = 0;
  while (b <= n) {
    DUMP(a, b);
    ++res;
    swap(a += b, b);
  }
  cout << res << '\n';
}