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

// =========== Solution ============= //

int main() {
  ll n;
  int m, k;
  cin >> n >> m >> k;
  int x, s;
  cin >> x >> s;
  vector<ll> A(m + 1), B(m + 1), C(k + 1), D(k + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> B[i];
  }
  A[0] = x;
  for (int i = 1; i <= k; ++i) {
    cin >> C[i];
  }
  for (int i = 1; i <= k; ++i) {
    cin >> D[i];
  }
  vector<pll> BA(m + 1);
  for (int i = 0; i <= m; ++i) {
    BA[i] = pll(B[i], A[i]);
  }
  sort(BA.begin(), BA.end());
  int j = k;
  ll ans = n * x;
  for (pll ba: BA) {
    while (j >= 0 && ba.fi + D[j] > s) {
      --j;
    }
    if (j < 0) break;
    ans = min(ans, (n - C[j]) * ba.se);
  }
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - special cases (n=1? graph not connected?)
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - re-initialize efficiently between test cases
// strategy
// - solution too complex? read samples to see if you missed something