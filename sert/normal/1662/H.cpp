#include <bits/stdc++.h>
using namespace std;

void solve(int h, int w, vector<int> &ans) {
  int g = __gcd(h, w);
  ans.push_back(g);
  for (int i = 2; i * i <= g; i++) {
    if (g % i) {
      continue;
    }
    ans.push_back(i);
    ans.push_back(g / i);
  }
}

void solve() {
  int h, w;
  cin >> h >> w;
  vector<int> ans = {1, 2};

  solve(h - 1, w - 1, ans);
  solve(h - 2, w, ans);
  solve(h, w - 2, ans);

  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << " ";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  cin >> t;
  while (t--) {
    solve();
  }
}