#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long x;
  cin >> x;
  long long mn = x + 1;
  pair<long long, long long> res;
  for (long long i = 1; i * i <= x; ++i) {
    if (x % i == 0 and __gcd(i, x / i) == 1) {
      if (max(i, x / i) < mn) {
        mn = max(i, x / i);
        res = {i, x / i};
      }
    }
  }
  cout << res.first << ' ' << res.second << '\n';
}