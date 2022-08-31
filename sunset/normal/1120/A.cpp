#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 5e5;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m, k, n, s;
  cin >> m >> k >> n >> s;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> need(MAX);
  for (int i = 0; i < s; ++i) {
    int x;
    cin >> x;
    --x;
    ++need[x];
  }
  vector<int> cur(MAX);
  int already = 0;
  for (int i = 0, j = 0; i < m; ++i) {
    while (j < m && already < s) {
      ++cur[a[j]];
      if (cur[a[j]] <= need[a[j]]) {
        ++already;
      }
      ++j;
    }
    if (already == s) {
      int remove = max(i % k, i - k * (n - 1));
      int extra = max(j - i - k, 0);
      if (remove + extra + n * k <= m) {
        vector<int> ans;
        for (int x = 0; x < remove; ++x) {
          ans.push_back(x);
        }
        for (int x = i; x < j; ++x) {
          if (need[a[x]]) {
            --need[a[x]];
          } else if (extra) {
            --extra;
            ans.push_back(x);
          }
        }
        cout << ans.size() << "\n";
        for (int x = 0; x < (int) ans.size(); ++x) {
          if (x) {
            cout << " ";
          }
          cout << ans[x] + 1;
        }
        cout << "\n";
        return 0;
      }
    }
    if (cur[a[i]] <= need[a[i]]) {
      --already;
    }
    --cur[a[i]];
  }
  cout << -1 << "\n";
  return 0;
}