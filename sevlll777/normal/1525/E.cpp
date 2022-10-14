#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244353;
int fact[33];

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
  fact[0] = 1;
  for (int i = 0; i < 30; i++) {
    fact[i + 1] = (i + 1) *fact[i];
    fact[i + 1] %= M;
  }
  int n, m;
  cin >> n >> m;
  vector<vector<int>> D(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> D[i][j];
    }
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cnt[D[i][j] - 1]++;
    }
    if (cnt[0] == 0) {
      int kek = 1;
      for (int i = n; i >= 1; i--) {
        if (i < n) {
          cnt[i] += cnt[i + 1];
          cnt[i]--;
        }
        if (cnt[i] >= 0) {
          kek *= cnt[i];
          kek %= M;
        } else {
          kek = 0;
          break;
        }
      }
      kek = fact[n] + M - kek;
      kek %= M;
      ans += kek;
      ans %= M;
    } else {
      ans += fact[n];
      ans %= M;
    }
  }
  ans *= binpow(fact[n], M - 2);
  ans %= M;
  cout << ans << '\n';


}