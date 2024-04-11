#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  map<int, int> cnt;
  multiset<int> pcs;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
    cnt[a[i]]++;
  }
  pcs.insert(s);
  while (!pcs.empty()) {
    if ((int) pcs.size() > n) {
      cout << "NO\n";
      return;
    }
    int z = *pcs.rbegin();
    pcs.erase(pcs.find(z));
    if (cnt[z] >= 1) {
      cnt[z]--;
    } else if (z != 1) {
      pcs.insert(z / 2);
      pcs.insert((z + 1) / 2);
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";


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