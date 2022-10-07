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
map<int, int> mp;

int n, k;
bool ok(int copies) {
  int length = 0;
  for (auto p: mp) {
    length += p.se / copies;
  }
  return length >= k;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++mp[x];
  }

  int lo = 1;
  int hi = n;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (ok(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  int length = 0;
  for (auto p: mp) {
    int take = min(p.second / lo, k - length);
    length += take;
    for (int i = 0; i < take; ++i) {
      cout << p.fi << " ";
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