#include <bits/stdc++.h>
using namespace std;

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

void solve() {
  map<int, vector<int>> v;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int deg = 0;
    while (x % k == 0) {
      x /= k;
      deg++;
    }
    auto &a = v[x];
    while (static_cast<int>(a.size()) <= deg) a.push_back(0);
    a[deg]++;
  }
  int ans = 0;
  for (const auto &it : v) {
    int rem = 0;
    for (int x : it.second) {
      if (rem > x) { ans += rem - x; rem = 0; }
      else rem = x - rem;
    }
    ans += rem;
  }
  cout << ans << "\n";
}

int main() {
  if (D) freopen("../a.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = (D ? 3 : 1);
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}