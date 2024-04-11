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
const int N = 200500;
const int B = 22;
int cnt[N][B];

void solve() {
  int l, r;
  cin >> l >> r;
  int ans = (int) 1e9;
  for (int b = 0; b < B; b++) {
    ans = min(ans, cnt[r][b] - cnt[l - 1][b]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int b = 0; b < B; b++) {
    for (int n = 1; n < N; n++) {
      if ((n >> b) & 1) {
        cnt[n][b] = cnt[n - 1][b];
      } else {
        cnt[n][b] = cnt[n - 1][b] + 1;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}