#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, d;
    cin >> n >> d;
    long long c = sqrt(d);
    bool ok = false;
    for (long long i = max(c - 10, 0LL); i <= c + 10; ++i) {
      if (i + (d + i) / (i + 1) <= n) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}