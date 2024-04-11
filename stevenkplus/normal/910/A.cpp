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
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  int ans = 0;
  int cur = 0;
  while (cur < n - 1) {
    int nxt = -1;
    for (int i = cur + 1; i <= cur + d; ++i) {
      if (s[i] == '1') {
        nxt = i;
      }
    }
    if (nxt == -1) {
      cout << -1 << "\n";
      return 0;
    }
    cur = nxt;
    ++ans;
  }
  cout << ans << "\n";
}