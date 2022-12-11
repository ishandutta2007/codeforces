#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

void mne(int &x, int y) {
  if (y < x) x = y;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), u(n);
  vector<int> b;
  for (int &x : a) cin >> x;
  for (int &x : u) cin >> x;
  for (int i = 0; i < n; i++) if (u[i] == 0) b.push_back(a[i]);
  sort(b.rbegin(), b.rend());
  int cur = 0;
  for (int i = 0; i < n; i++)
    if (u[i] == 0) a[i] = b[cur++];
  for (int x : a) cout << x << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}