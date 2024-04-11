#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MD = 998244353;
#ifdef SERT
bool D = true;
#else
bool D = false;
#endif
constexpr int INF = (int)1e9 + 41;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  if (n <= 3) {
    cout << "0\n";
    for (int i = 0; i < 3; i++) {
      cout << a[i % n] << " ";
    }
    cout << "\n";
    return;
  }

  double x1 = a[0], x3 = a[n - 1], x2 = (a[1] + a[n - 2]) * 0.5;
  double ans = (a[n - 2] - a[1]) * 0.5;

  int c1 = 0;
  int c2 = n - 1;
  while (c1 + 1 < c2 - 1) {
    if (a[c1 + 1] - a[0] < a[n - 1] - a[c2 - 1]) c1++;
    else c2--;
    double cur = max({a[c1] - a[0], a[c2 - 1] - a[c1 + 1], a[n - 1] - a[c2]}) * 0.5;
    if (cur < ans) {
      ans = cur;
      x1 = (a[0] + a[c1]) * 0.5;
      x2 = (a[c2 - 1] + a[c1 + 1]) * 0.5;
      x3 = (a[n - 1] + a[c2]) * 0.5;
    }
  }
  cout.precision(2);
  cout << fixed << ans << "\n";
  cout << x1 << " " << x2 << " " << x3 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  //cin >> t;
  while (t--) {
    solve();
  }
}