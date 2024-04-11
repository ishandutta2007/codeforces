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
  ll n, k;
  int q;
  cin >> n >> k >> q;
  k = n - k;
  ll j = n - k;

  ll left, right; // ...x.x.x.x.x
  // '.' * left + 'x' + .x' * right + 'x' * (n - left - 1 - 2 * right)
  if (k <= j) {
    left = 0;
    right = k;
  } else {
    left = k - j + 1;
    if (left % 2 == 0 && left + 1 <= k) ++left;
    right = k - left;
  }

  for (int i = 0; i < q; ++i) {
    ll p;
    cin >> p;
    --p;
    if (p < left) cout << '.';
    else {
      if (left) {
        p -= left + 1;
      }
      if (p < 2 * right && p % 2 == 0) {
        cout << '.';
      } else {
        cout << 'X';
      }
    }
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