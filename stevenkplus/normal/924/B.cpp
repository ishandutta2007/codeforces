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

void fastio() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cin.tie(0);
}

// =========== Solution ============= //

int main()  {
  fastio();
  int n, U;
  cin >> n >> U;
  double ans = -1;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int j = 0;
  for(int i = 0; i < n; ++i) {
    while (j + 1 < n && v[j + 1] - v[i] <= U) {
      ++j;
    }
    if (j <= i + 1) continue;
    double val = ld(v[j] - v[i + 1]) / (v[j] - v[i]);
    ans = max(ans, val);
  }
  if (ans == -1) cout << "-1\n";
  else cout << ans << "\n";
}