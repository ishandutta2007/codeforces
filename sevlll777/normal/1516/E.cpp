#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = 509;
int d2[N][N];
int fact[N];
int inv_fact[N];
int inv[N];

int binpow(int a, int x) {
  int ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int x = 0; x < N; x++) {
    inv[x] = binpow(x, M - 2);
  }
  fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = d2[0][0] = 1;
  for (int n = 2; n < N; n++) {
    fact[n] = n * fact[n - 1] % M;
    inv_fact[n] = binpow(fact[n], M - 2);
    for (int k = 1; k < N; k++) {
      if (n <= 2 * k - 1) {
        d2[n][k] = 0;
      } else if (k == 1) {
        if (n == 2) {
          d2[n][k] = 1;
        } else {
          d2[n][k] = d2[n - 1][k] * (n - 1) % M;
        }
      } else {
        int f = 1;
        for (int x = 2; x < n; x++) {
          f *= (n - x + 1);
          f %= M;
          d2[n][k] += (f * d2[n - x][k - 1]) % M;
          d2[n][k] %= M;
        }
      }
    }
  }
  int n, k;
  cin >> n >> k;
  int last = 0, sus = 0;
  for (int cycl = n; cycl >= n - k; cycl--) {
    for (int fx = max(0LL, cycl - k - 1); fx <= cycl; fx++) {
      int w = d2[n - fx][cycl - fx];
      for (int y = n; y >= fx + 1; y--) {
        w *= y;
        w %= M;
      }
      w *= inv_fact[n - fx];
      w %= M;
      sus += w;
      sus %= M;
    }
    last = (M + sus - last) % M;
    if (cycl < n) {
      cout << last << ' ';
    }
  }
  cout << '\n';


}