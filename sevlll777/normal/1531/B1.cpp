#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  map<int, int> cnt, cntab;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cnt[a]++;
    if (a != b) {
      cnt[b]++;
      cntab[min(a, b) * (int) 2e9 + max(a, b)]++;
    }
  }
  int ans = 0;
  for (auto p : cnt) ans += p.second * (p.second - 1) / 2;
  for (auto p : cntab) {
    ans -= p.second * (p.second - 1) / 2;
  }
  cout << ans << '\n';
}