#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;
const lint MOD = 998244353;
int emod(lint x, lint p = MOD) {
  return (x % p + p) % p;
}

lint power(lint x, lint n, lint mod = numeric_limits<lint>::max()) {
  return n ? power(x * x % mod, n >> 1, mod) * (n & 1 ? x : 1) % mod : 1;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) return cout << a[0] << '\n', 0;
  vector<lint> c(n + 1);
  for (int i = 0; i < n; i++) {
    c[i + 1] = (c[i] + a[i]) % MOD;
  }

  lint res = 0;
  for (int k = 1; k <= n - 2; k++) {
    res = (res + 2 * c[k] * power(2, n - k - 1, MOD) % MOD) % MOD;
    res = (res + (n - k - 1) * c[k] % MOD * power(2, n - k - 2, MOD) % MOD) % MOD;
  }
  res = (res + 2 * c[n - 1]) % MOD;
  res = (res + c[n]) % MOD;
  cout << emod(res) << '\n';
  return 0;
}