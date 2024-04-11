#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, sum[N], pre[N][26], suf[N][26], pref[N][26], suff[N][26];
bool visit[40];
char s[N];

int solve(int l, int r) {
  if (l > r) {
    return 0;
  }
  for (int i = 0; i <= 26; ++i) {
    visit[i] = false;
  }
  for (int i = 0; i < 26; ++i) {
    if (suf[l][i] <= r) {
      int x = suf[l][i], y = pre[r][i];
      visit[suff[l][i] ^ pref[r][i] ^ sum[y] ^ sum[x]] = true;
    }
  }
  for (int i = 0; ; ++i) {
    if (!visit[i]) {
      return i;
    }
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      pre[i][j] = pre[i - 1][j];
    }
    pre[i][s[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; ++i) {
    suf[n + 1][i] = n + 1;
  }
  for (int i = n; i; --i) {
    for (int j = 0; j < 26; ++j) {
      suf[i][j] = suf[i + 1][j];
    }
    suf[i][s[i] - 'a'] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (pre[i - 1][s[i] - 'a']) {
      sum[i] = sum[pre[i - 1][s[i] - 'a']] ^ pref[i - 1][s[i] - 'a'];
    }
    for (int j = i; j > pre[i - 1][s[i] - 'a']; --j) {
      suff[j][s[i] - 'a'] = solve(j, i - 1);
    }
    vector<pair<int, int>> all;
    for (int j = 0; j < 26; ++j) {
      if (pre[i][j]) {
        all.emplace_back(pre[i][j], j);
      }
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int j = 0; j < all.size(); ++j) {
      int c = all[j].second;
      pref[i][c] = solve(pre[i][c] + 1, i);
    }
  }
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    puts(solve(l, r) ? "Alice" : "Bob");
  }
  return 0;
}