#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> r(m), w(m);
  for (int i = 0; i < m; i++) {
    cin >> r[i] >> w[i];
  }
  int R = *max_element(r.begin(), r.end());
  int W = *max_element(w.begin(), w.end());
  if (R + W > n) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << string(R, 'R') + string(n - R, 'W') << "\n";
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