#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    bool ok = true;
    if (a * a % b or b * b % a) {
      ok = false;
    }
    for (int _ = 2; _--; ) {
      long long x = round(cbrt(a * a / b));
      if (x * x * x != a * a / b) {
        ok = false;
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}