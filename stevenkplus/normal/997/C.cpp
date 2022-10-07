#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
typedef long long ll;

int calls = 0;
// a ^ b mod c
ll pw(int a, ll b, int c) {
  ll m = a;
  ll r = 1;
  for(int i = 0; i < 40; ++i) {
    if ((b >> i) & 1) {
      r = r * m % c;
    }
    m = m * m % c;
  }
  return r;
}

const int MAXN = 1001000;
ll chs[MAXN];
int inv(int x, int p) {
  return pw(x, p - 2, p);
}

ll n;
ll go(int i) {
  // i rows chosen, at least 1 col chosen
  ll m = -pw(3, n * n - i * n, MOD);
  ll r = inv(pw(3, n - i, MOD), MOD);
  ll tot = m * (pw(1 - r, n, MOD) - 1) % MOD;
  // cout << "go(" << i << "):" << "\n";
  // cout << m << "," << r << "," << tot << "\n";
  return tot * 3;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  chs[0] = 1;
  for(int i = 1; i <= n; ++i) {
    chs[i] = chs[i - 1] * (n - i + 1) % MOD * inv(i, MOD) % MOD;
  }
  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    int sgn = i % 2 == 1 ? 1 : MOD - 1;
    ll v = chs[i] * go(i) % MOD;
    ans = (ans + sgn * v) % MOD;
  }
  // ans = 0;
  // cout << ans << "\n";
  // ans: satisfies both row and col
  ans = ans * -1;
  for(int i = 1; i <= n; ++i) {
    int sgn = i % 2 == 1 ? 1 : MOD - 1;
    ll v = chs[i] * pw(3, i + n * (n - i), MOD) % MOD;
    ans = (ans + 2 * sgn * v) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << "\n";
}