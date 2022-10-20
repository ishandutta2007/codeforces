#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int m;
  cin >> m;
  string s;
  cin >> s;
  int n = size(s);
  for (char mx = 'a'; mx <= 'z'; ++mx) {
    vector<int> suff(n + 1);
    for (int i = n; i--;) suff[i] = (s[i] <= mx) + suff[i + 1];
    bool ok = true;
    for (int i = 0; i + m <= n; ++i) ok &= suff[i] > suff[i + m];
    if (not ok) continue;
    for (char c = 'a'; c < mx; ++c)
      for (int i = 0; i < n; ++i)
        if (s[i] == c) cout << c;
    int last = -1, last_mx = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] < mx) last = i;
      if (s[i] == mx) last_mx = i;
      if (i - last >= m) {
        cout << mx;
        last = last_mx;
      }
    }
    cout << '\n';
    break;
  }
}