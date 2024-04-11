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
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, k;
    cin >> n >> k;
    ++k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    int ans = 1 << 30;
    int ansx = -1;
    for (int i = 0; i + k <= n; ++i) {
      int x = (v[i] + v[i + k - 1]) / 2;
      int d = (v[i + k - 1] - v[i] + 1) / 2;
      if (d < ans) {
        ans = d;
        ansx = x;
      }
    }
    cout << ansx << "\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases