#include <bits/stdc++.h>

// #define int long long
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const int S = 350;
const int N = 100500;
map<int, int> kek[N];

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> check;
  for (int d = -S; d <= S; d++) {
    check.pb(d);
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < min(n, i + S); j++) {
      if (a[j] >= a[i] && (a[j] - a[i]) % (j - i) == 0) {
        int d = (a[j] - a[i]) / (j - i);
        if (kek[d].find(i) == kek[d].end()) {
          if (kek[d].find(j) != kek[d].end()) {
            int w = kek[d][j] + 1;
            kek[d][i] = w;
            ans = max(ans, w);
          } else {
            kek[d][i] = 2;
            ans = max(ans, 2);
          }
        }
      }
    }
  }

  for (int v = 0; v < n; v++) {
    kek[v] = {};
  }
  reverse(all(a));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < min(n, i + S); j++) {
      if (a[j] >= a[i] && (a[j] - a[i]) % (j - i) == 0) {
        int d = (a[j] - a[i]) / (j - i);
        if (kek[d].find(i) == kek[d].end()) {
          if (kek[d].find(j) != kek[d].end()) {
            int w = kek[d][j] + 1;
            kek[d][i] = w;
            ans = max(ans, w);
          } else {
            kek[d][i] = 2;
            ans = max(ans, 2);
          }
        }
      }
    }
  }

  for (auto d: check) {
    vector<ll> lol;
    for (int i = 0; i < n; i++) {
      lol.pb((ll) a[i] - (ll) d * (ll) i);
    }
    sort(all(lol));
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (lol[i] == lol[i - 1]) {
        cnt++;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }
    ans = max(ans, cnt);
  }
  cout << n - ans << '\n';

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}