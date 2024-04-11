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
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    bool ng = false;
    ng |= min(a, b) < m;
    ng |= a + b < n + m;
    cout << (ng ? "No\n" : "Yes\n");
  }
}