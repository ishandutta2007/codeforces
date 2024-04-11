#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, p; cin >> n >> p;
  string s; cin >> s;
  VV<> A(p, V<>(p));
  V<bool> ok(1 << p, true);
  for (int i = 0; i < p; ++i) for (int j = 0; j < p; ++j) {
    V<bool> b(1 << p, true);
    auto rec = [&](const auto& rec, int i, int j, int bit) -> void {
      if (!b[1 << i | 1 << j | bit]) return;
      b[1 << i | 1 << j | bit] = false;
      for (int k = 0; k < p; ++k) if (k != i and k != j and bit & 1 << k) {
        rec(rec, i, j, bit ^ 1 << k);
      }
    };
    cin >> A[i][j];
    if (A[i][j]) continue;
    int r = 0;
    for (int l = 0; l < n; ++l) if (s[l] - 'a' == i) {
      r = max(r, l + 1);
      while (r < n and s[r] - 'a' != i and s[r] - 'a' != j) ++r;
      if (r == n) break;
      if (s[r] - 'a' != j) continue;
      int bit = (1 << p) - 1;
      for (int x = l + 1; x < r; ++x) {
        assert(s[x] - 'a' != i and s[x] - 'a' != j);
        bit &= ~(1 << s[x] - 'a');
      }
      rec(rec, i, j, bit);
    }
    for (int bit = 0; bit < 1 << p; ++bit) if (!b[bit]) {
      ok[bit] = false;
    }
  }
  assert(ok.back());
  V<> cnt(p);
  for (char c : s) {
    ++cnt[c - 'a'];
  }
  V<> len(1 << p);
  for (int bit = 0; bit < 1 << p; ++bit) {
    for (int i = 0; i < p; ++i) if (bit & 1 << i) {
      len[bit] += cnt[i];
    }
  }
  V<bool> dp(1 << p);
  dp.back() = true;
  for (int bit = (1 << p) - 1; bit >= 0; --bit) if (dp[bit]) {
    for (int i = 0; i < p; ++i) if (bit & 1 << i and ok[bit ^ 1 << i]) {
      dp[bit ^ 1 << i] = true;
    }
  }
  int res = n;
  for (int bit = 0; bit < 1 << p; ++bit) if (dp[bit]) {
    res = min(res, len[bit]);
  }
  cout << res << '\n';
}