#include <iostream>
#include <iomanip>
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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;
const int N = 1000009;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  vector<int> B(m);
  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }
  int g = 0;
  for (auto x : B) {
    g = gcd(g, x);
  }
  if (g == 1) {
    int ans = 0;
    for (auto x : A) {
      ans += abs(x);
    }
    cout << ans << '\n';
    return;
  }
  vector<int> sm(g);
  for (int i = 1; i <= n; i++) {
    sm[i % g] += abs(A[i]);
  }
  vector<int> cntneg(g);
  for (int i = 1; i <= n; i++) {
    cntneg[i % g] += (A[i] < 0);
  }
  vector<int> mods(g, (int) 1e18);
  for (int i = 1; i <= n; i++) {
    mods[i % g] = min(mods[i % g], 2 * abs(A[i]));
  }
  int ans = (int) -1e18;
  int kk = 0;
  for (int r = 0; r < g; r++) {
    if (cntneg[r] % 2) {
      kk += sm[r] - mods[r];
    } else {
      kk += sm[r];
    }
  }
  ans = kk;
  for (int i = 1; i <= g; i++) {
    cntneg[i % g] -= (A[i] < 0);
    A[i] *= -1;
    cntneg[i % g] += (A[i] < 0);
  }
  kk = 0;
  for (int r = 0; r < g; r++) {
    if (cntneg[r] % 2) {
      kk += sm[r] - mods[r];
    } else {
      kk += sm[r];
    }
  }
  for (int i = 1; i <= n - g; i++) {
    ans = max(ans, kk);
    if (cntneg[i % g] % 2) {
      kk -= sm[i % g] - mods[i % g];
    } else {
      kk -= sm[i % g];
    }
    cntneg[i % g] -= (A[i] < 0);
    A[i] *= -1;
    cntneg[i % g] += (A[i] < 0);
    if (cntneg[i % g] % 2) {
      kk += sm[i % g] - mods[i % g];
    } else {
      kk += sm[i % g];
    }

    if (cntneg[i % g] % 2) {
      kk -= sm[i % g] - mods[i % g];
    } else {
      kk -= sm[i % g];
    }
    cntneg[i % g] -= (A[i + g] < 0);
    A[i + g] *= -1;
    cntneg[i % g] += (A[i + g] < 0);
    if (cntneg[i % g] % 2) {
      kk += sm[i % g] - mods[i % g];
    } else {
      kk += sm[i % g];
    }
  }
  ans = max(ans, kk);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}