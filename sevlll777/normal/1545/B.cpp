#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244353;
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

int C(int k, int n) {
  return (((fact[n] * inv_fact[k]) % M) * inv_fact[n - k]) % M;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int z = 0;
  for (auto c : s) {
    z += (c == '0');
  }
  int cnt = 0, f = 0;
  bool kek = false;
  for (int i = 0; i <= n; i++) {
    if (i < n && s[i] == '1') {
      cnt++;
    } else {
      if (cnt > 0) {
        if (cnt > 1) {
          kek = true;
        }
        f += cnt % 2;
      }
      cnt = 0;
    }
  }
  if (!kek) {
    cout << "1\n";
  } else {
    int l = f, r = z + 1;
    int o = n - z;
    o -= f;
    o /= 2;
    int ans = 0;
    for (int d = (f == 0); d <= o; d++) {
      int x = o - d;
      int mest = f + d;
      x += mest;
      int bbz = C(mest - 1, x - 1);
      if (f + d <= z + 1) {
        int z2 = z - (f + d - 1);
        int suz = C(z2, z2 + d);
        bbz *= suz;
        bbz %= M;
        ans += bbz;
      }
    }
    ans %= M;
    cout << ans << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (i * fact[i - 1]) % M;
    inv_fact[i] = binpow(fact[i], M - 2);
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}