#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<array<int, 17>> suff(n + 1);
  for (int i = n; i--;) {
    suff[i] = suff[i + 1];
    if (s[i] == '?')
      for (auto&& e : suff[i]) ++e;
    else
      ++suff[i][s[i] - 'a'];
  }
  auto check = [&](int m) -> bool {
    vector nxt(k, vector<int>(n - m + 1, n));
    for (int i = 0; i < k; ++i) {
      for (int j = n - m; j >= 0; --j) {
        if (j < n - m) nxt[i][j] = nxt[i][j + 1];
        if (suff[j][i] - suff[j + m][i] == m) nxt[i][j] = j;
      }
    }
    vector<int> f(1 << k, 1e9);
    f[0] = 0;
    for (int mask = 0; mask < 1 << k; ++mask) {
      if (f[mask] > n - m) continue;
      for (int i = 0; i < k; ++i) f[mask | 1 << i] = min(f[mask | 1 << i], nxt[i][f[mask]] + m);
    }
    return f.back() <= n;
  };
  int ok = 0, ng = n / k + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}