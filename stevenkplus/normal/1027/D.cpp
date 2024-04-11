// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  int n;
  cin >> n;
  vector<int> p(n), c(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    if (!v[i]) {
      int j = i + 1;
      int cur = i;
      do {
        v[cur] = j;
        cur = p[cur];
      } while (!v[cur]);
      if (v[cur] == j) {
        int root = cur;
        int mn = c[cur];
        do {
          mn = min(mn, c[cur]);
          cur = p[cur];
        } while (cur != root);
        ans += mn;
      }
    }
  }
  cout << ans << "\n";
}