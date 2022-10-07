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

// _gcd: a, b non-negative integers
ll _gcd(ll a, ll b) {
  if (a == 0) return b;
  return _gcd(b % a, a);
}

// =========== Solution ============= //

int main() {
  int n, m;
  cin >> n >> m;
  vector<pii> ans;
  if (m < n - 1) {
    cout << "Impossible\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (ans.size() >= m) break;
    for (int j = 1; j + i <= n; ++j) {
      if (ans.size() >= m) break;
      if (_gcd(i, j) == 1) {
        ans.push_back(pii(j, j + i));
      }
    }
  }
  if (ans.size() >= m) {
    cout << "Possible\n";
    for (pii p: ans) {
      cout << p.fi << " " << p.se << "\n";
    }
  } else {
    cout << "Impossible\n";
  }
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases