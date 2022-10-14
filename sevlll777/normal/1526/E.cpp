#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244353;
const int N = 200009;
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
  return (fact[n] * inv_fact[k]) % M * inv_fact[n - k] % M;
}

void zero() {
  cout << "0\n";
  exit(0);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact[0] = inv_fact[0] = 1;
  for (int x = 1; x < N; x++) {
    fact[x] = x * fact[x - 1] % M;
    inv_fact[x] = binpow(fact[x], M - 2);
  }
  int n, k;
  cin >> n >> k;
  vector<int> S(n), P(n);
  for (int i = 0; i < n; i++) cin >> S[i];
  for (int i = 0; i < n; i++) {
    P[S[i]] = i;
  }
  int x = 0, y = 0;
  for (int i = 0; i < n - 1; i++) {
    int a = S[i], b = S[i + 1];
    if (b != n - 1 && (a == n - 1 || P[a + 1] < P[b + 1])) {
      y++;
    } else {
      x++;
    }
  }
  if (x > k - 1) {
    cout << "0\n";
  } else {
    int ans = 0;
    for (int a = 0; a <= y; a++) {
      if (x + 1 + a <= k) {
        ans += C(a, y) * C(x + 1 + a, k) % M;
        ans %= M;
      }
    }
    cout << ans << '\n';
  }
}