#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int M = (int) 1e9 + 7;
const int N = 100500;
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

void solve() {
  int n, k;
  cin >> n >> k;
  if (k >= n) {
    cout << binpow(2, n) << '\n';
    return;
  }
  int boba = 0;
  for (int w = 0; w <= k; w++) {
    boba += ((fact[n] * inv_fact[w]) % M * inv_fact[n - w]) % M;
  }
  boba %= M;
  cout << boba << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (i * fact[i-1]) % M;
    inv_fact[i] = binpow(fact[i], M - 2);
  }
  int t = 1;
  while (t--) {
    solve();
  }
}