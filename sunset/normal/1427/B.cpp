#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> block;
    int score = 0;
    int free = 0;
    for (int i = 0, j = -1; i < n; ++i) {
      if (s[i] == 'W') {
        if (j == -1) {
          if (i) {
            free += i;
          }
          ++score;
        } else {
          if (i - j > 1) {
            block.push_back(i - j - 1);
          } else {
            ++score;
          }
          ++score;
        }
        j = i;
      }
      if (i == n - 1) {
        free += i - j;
      }
    }
    if (!score) {
      cout << max(2 * m - 1, 0) << "\n";
      continue;
    }
    sort(block.begin(), block.end());
    for (int i = 0; i < (int) block.size(); ++i) {
      if (m >= block[i]) {
        score += 2 * block[i] + 1;
        m -= block[i];
      } else {
        score += 2 * m;
        m = 0;
      }
    }
    score += 2 * min(free, m);
    cout << score << "\n";
  }
  return 0;
}