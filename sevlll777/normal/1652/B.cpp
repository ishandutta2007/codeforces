#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> last(26, -1);
  for (int i = 0; i < (int) s.size(); i++) {
    last[s[i] - 'a'] = i;
  }
  int mn = (int) s.size();
  for (int c = 0; c < 26; c++) {
    if (last[c] != -1) {
      mn = min(mn, last[c]);
    }
  }
  for (int j = mn; j < (int) s.size(); j++) {
    cout << s[j];
  }
  cout << '\n';
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