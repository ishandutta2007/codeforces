#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
auto clc = clock();

void solve() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int bam = -1;
  string ans;
  while (clock() - clc < 2.6 * CLOCKS_PER_SEC) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int i = uniform_int_distribution<int>(0, n - 1)(rng);
    vector<int> ok;
    for (int b = 0; b < m; b++) {
      if (a[i][b] == '1') {
        ok.pb(b);
      }
    }
    vector<int> cnt(1 << p);
    for (int j = 0; j < n; j++) {
      int num = 0;
      for (int ii = 0; ii < (int) ok.size(); ii++) {
        int bit = ok[ii];
        if (a[j][bit] == '1') {
          num += (1LL << ii);
        }
      }
      cnt[(1 << p) - 1 - num]++;
    }
    vector<int> SOS(1 << p);
    for (int j = 0; j < (1 << p); j++) {
      SOS[j] = cnt[j];
    }
    for (int j = 0; j < p; j++) {
      for (int x = 0; x < (1 << p); x++) {
        if ((x >> j) & 1) {
          SOS[x] += SOS[x ^ (1 << j)];
        }
      }
    }
    for (int j = 0; j < (1 << p); j++) {
      if (SOS[j] >= (n + 1) / 2) {
        if (bam < p - __builtin_popcount(j)) {
          bam = p - __builtin_popcount(j);
          string sas;
          for (int __ = 0; __ < m; __++) sas += '0';
          for (int b = 0; b < p; b++) {
            if (((j >> b) & 1) == 0) {
              sas[ok[b]] = '1';
            }
          }
          ans = sas;
        }
      }
    }
  }
  cout << ans << '\n';


}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}