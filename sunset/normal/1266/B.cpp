#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n >= 14 && n % 14 >= 1 && n % 14 <= 6) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}