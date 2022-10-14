#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int M = 998244353;
const int N = 200500;
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
  return (((fact[n] * inv_fact[k]) % M) * inv_fact[n - k] % M) % M;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  p[0] = a[0];
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + a[i];
  }
  int sum = p[n - 1];
  map<int, int> cnt;
  for (int i = 0; i < n - 1; i++) {
    cnt[p[i]]++;
  }
  int ans = 1;
  for (auto pr : cnt) {
    if (cnt.find(sum - pr.first) == cnt.end()) {
      continue;
    }
    if (pr.first * 2 > sum) {
      continue;
    }
    if (pr.first * 2 == sum) {
      int kek = binpow(2, pr.second);
      ans *= kek;
      ans %= M;
      continue;
    }
    int m1 = pr.second, m2 = cnt[sum - pr.first];
    int sus = 0;
    for (int k = 0; k <= min(m1, m2); k++) {
      sus += (C(k, m1) * C(k, m2) % M) % M;
    }
    sus %= M;
    ans *= sus;
    ans %= M;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact[0] = 1;
  inv_fact[0] = 1;
  for (int w = 1; w < N; w++) {
    fact[w] = (fact[w - 1] * w) % M;
    inv_fact[w] = binpow(fact[w], M - 2);
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}