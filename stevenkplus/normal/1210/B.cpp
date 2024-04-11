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
  int n;
  cin >> n;
  map<ll, int> cnt;
  vector<ll> v, good;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    v.push_back(x);
    ++cnt[x];
    if (cnt[x] == 2) {
      good.push_back(x);
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll w;
    cin >> w;
    bool ok = false;
    for (ll k: good) {
      if ((v[i] & k) == v[i]) {
        ok = true;
      }
    }
    if (ok) {
      ans += w;
    }
  }
  cout << ans << "\n";
}

// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases