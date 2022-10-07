// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second

// =========== Book ============ //

int fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
  return 0;
}
int __fastio = fastio();

typedef priority_queue<pll, vector<pll>, greater<pll> > PQ;

// =========== Solution ============= //

// ans[n][n] = 10
// ans[n][n - 1] = 180
// ans[n][i] = (n - i - 1) * 10 * 81 * 10^(n - i - 2) + 2 * 10 * 9 * 10^(n - i - 1)

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<ll> pows(n);
  pows[0] = 1;
  for (int i = 0; i + 1 < n; ++i) {
    pows[i + 1] = pows[i] * 10 % MOD;
  }
  for (int i = 1; i <= n; ++i) {
    ll ans = 0;
    if (i == n) {
      ans = 10;
    } else if (i == n - 1) {
      ans = 180;
    } else {
      ans += (n - i - 1) * 10 * 81 * pows[n - i - 2];
      ans += 2 * 10 * 9 * pows[n - i - 1];
      ans %= MOD;
    }
    cout << ans << " ";
  }
  cout << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases