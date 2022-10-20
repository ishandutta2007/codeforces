#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    int c, sum;
    cin >> c >> sum;
    long long res = 0;
    for (int i = 0; i < c; ++i) {
      long long t = sum / c;
      t += i < sum % c;
      res += t * t;
    }
    cout << res << '\n';
  }
}