#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 2 "main.cpp"

unordered_set<string> two, three[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    two.clear(), three[0].clear(), three[1].clear();
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    bool found = false;
    rep(i, n) {
      if (s[i].front() == s[i].back()) {
        found = true;
        break;
      }
      string rev = s[i];
      reverse(all(rev));
      bool ok = s[i].size() == 1 ? true
                : s[i].size() == 2
                    ? two.count(rev) ||
                          three[0].count(rev.substr(0, 2))
                    : two.count(rev.substr(0, 2)) ||
                          three[1].count(rev);
      if (ok) {
        found = true;
        break;
      }
      if (s[i].size() == 2) two.insert(move(s[i]));
      else {
        three[0].insert(s[i].substr(0, 2));
        three[1].insert(move(s[i]));
      }
    }
    printf("%s\n", found ? "YES" : "NO");
  }
}