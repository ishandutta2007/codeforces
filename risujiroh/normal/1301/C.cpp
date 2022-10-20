#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    long long res = n * (n + 1) / 2;
    long long z = n - m;
    long long x = (z / (m + 1) + 1);
    long long y = z / (m + 1);
    res -= (x * (x + 1) / 2) * (z % (m + 1)) + (y * (y + 1) / 2) * ((m + 1) - z % (m + 1));
    cout << res << '\n';
  }
}