#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  string s;
  cin >> n >> s >> m;
  int log_n = 0;
  while (1 << log_n < n) {
    ++log_n;
  }
  vector<vector<int>> sum(log_n, vector<int> (n));
  for (int i = 0; i < log_n; ++i) {
    for (int j = n - 1; ~j; --j) {
      sum[i][j] = (j == n - 1 ? 0 : s[j] != s[j + 1]) + (j + (1 << i + 1) < n ? sum[i][j + (1 << i + 1)] : 0);
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l;
    int answer = 0;
    for (int i = 0; 1 << i < r - l; ++i) {
      int value = sum[i][l + (1 << i)] - (r + (1 << i) < n ? sum[i][r + (1 << i)] : 0);
      value = min(value, (r - l >> i + 1) - value);
      answer += value;
    }
    printf("%d\n", answer + 1 >> 1);
  }
  return 0;
}