#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
int x, y, a, b;

int f(int m) {
  int s = 0;
  s += m + m;
  int x1 = x - (a + b) * m;
  int y1 = y - (a + b) * m;
  x1 /= a;
  y1 /= b;
  s += min(x1, y1);
  return s;
}

void solve() {
  cin >> x >> y >> a >> b;
  if (x < y) swap(x, y);
  if (a < b) swap(a, b);
  if (a == b) {
    cout << min(x / a, y / a) << '\n';
  } else {
    int ans = 0;
    int l = (a * y - b * x) / (a * a - b * b);
    for (int e = -115; e <= 115; e++) {
      if ((l + e >= 0) && (l + e <= y / (a + b))) {
        ans = max(ans, f(l + e));
      }
    }
    l = 0;
    for (int e = -115; e <= 115; e++) {
      if ((l + e >= 0) && (l + e <= y / (a + b))) {
        ans = max(ans, f(l + e));
      }
    }
    l = y / (a + b);
    for (int e = -115; e <= 115; e++) {
      if ((l + e >= 0) && (l + e <= y / (a + b))) {
        ans = max(ans, f(l + e));
      }
    }

    cout << ans << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}