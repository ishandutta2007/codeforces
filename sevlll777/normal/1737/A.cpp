#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (auto c : s) {
    cnt[c - 'a']++;
  }
  for (int _ = 0; _ < k; _++) {
    int w = n / k;
    for (int l = 0; l < 26; l++) {
      if (w == 0) {
        cout << (char) ('a' + l);
        break;
      }
      if (cnt[l]) {
        cnt[l]--;
        w--;
      } else {
        cout << (char) ('a' + l);
        break;
      }
    }
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