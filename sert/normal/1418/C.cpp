#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

void mne(int &x, int y) {
  if (y < x) x = y;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  a.push_back(INF);

  vector<int> dpM(n + 3, INF);
  vector<int> dpF(n + 3, INF);

  dpF[0] = 0;
  for (int num = 0; num < n; num++) {
    if (dpM[num] != INF) {
      mne(dpF[num + 1], dpM[num]);
      mne(dpF[num + 2], dpM[num]);
    }
    if (dpF[num] != INF) {
      mne(dpM[num + 1], dpF[num] + a[num]);
      mne(dpM[num + 2], dpF[num] + a[num] + a[num + 1]);
    }
  }

  cout << min(dpM[n], dpF[n]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}