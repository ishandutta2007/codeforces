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
  int n, k, l, r, sall, sk;
  cin >> n >> k >> l >> r >> sall >> sk;
  vector<int> ans(n);
  int lo = sall - sk;
  for (int i = 0; i < n - k; ++i) {
    int val = lo / (n - k - i);
    lo -= val;
    cout << val << " ";
  }

  int hi = sk;
  for (int i = 0; i < k; ++i) {
    int val = hi / (k - i);
    hi -= val;
    cout << val << " ";
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