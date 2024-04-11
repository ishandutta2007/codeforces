#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];

    {
      while (s[0].back() == '.' && s[1].back() == '.') {
        s[0].pop_back();
        s[1].pop_back();
      }
      reverse(begin(s[0]), end(s[0]));
      reverse(begin(s[1]), end(s[1]));
      while (s[0].back() == '.' && s[1].back() == '.') {
        s[0].pop_back();
        s[1].pop_back();
      }
      n = int(size(s[0]));
    }

    vector f(1 << 2, 0);
    for (int i = n; i--;) {
      vector nf(1 << 2, int(1e9));
      int sub = (s[0][i] == '*') | (s[1][i] == '*') << 1;
      for (int mask = sub; mask < 1 << 2; mask = (mask + 1) | sub) {
        if (mask == 0) {
          continue;
        }
        for (int prv = 1; prv < 1 << 2; ++prv) {
          if ((mask & prv) == 0) {
            continue;
          }
          nf[mask] = min(nf[mask], __builtin_popcount(mask) + f[prv]);
        }
      }
      f = move(nf);
    }

    cout << *min_element(begin(f), end(f)) - 1 << '\n';
  }
}