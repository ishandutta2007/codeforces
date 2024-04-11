#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;
const int N = 100009;
int fact[N], inv_fact[N];

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

int C(int k, int n) {
  return ((fact[n] * inv_fact[k]) % M * inv_fact[n - k]) % M;
}

void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 2;
  for (int i = 2; 0 <= (n - (i - 1) * (k - 1) - i); i++) {
    int ansi = 0;
    int m = n - (i - 1) * (k - 1) - i;
    ansi += C(i, m + i);
    ansi *= binpow(C(i, n), M - 2);
    ansi %= M;
    ans += ansi;
  }
  ans %= M;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1] % M;
    inv_fact[i] = binpow(fact[i], M - 2);
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}