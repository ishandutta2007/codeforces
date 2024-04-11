#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<bitset<1 << 10>> bs(n);
  vector<string> pref(n), suff(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int r = 1; r <= int(size(s)); ++r)
      for (int l = r; l >= 0; --l) {
        if (r - l > 9) break;
        int mask = 1 << (r - l);
        for (int j = 0; j < r - l; ++j) mask |= (s[l + j] & 1) << j;
        bs[i][mask] = 1;
      }
    pref[i] = s.substr(0, min(int(size(s)), 10));
    suff[i] = s.substr(size(s) - min(int(size(s)), 10));
  }
  int m;
  cin >> m;
  bs.resize(n + m);
  pref.resize(n + m), suff.resize(n + m);
  for (int i = n; i < n + m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    bs[i] = bs[a] | bs[b];
    auto s = suff[a] + pref[b];
    for (int r = 1; r <= int(size(s)); ++r)
      for (int l = r; l >= 0; --l) {
        if (r - l > 9) break;
        int mask = 1 << (r - l);
        for (int j = 0; j < r - l; ++j) mask |= (s[l + j] & 1) << j;
        bs[i][mask] = 1;
      }
    for (int k = 10; k--;) {
      bool ok = true;
      for (int j = 1 << k; j < 1 << (k + 1); ++j) ok &= bs[i][j];
      if (ok) {
        cout << k << '\n';
        break;
      }
    }
    pref[i] = pref[a];
    if (size(pref[i]) < 10) pref[i] += pref[b].substr(0, min(size(pref[b]), 10 - size(pref[i])));
    suff[i] = suff[b];
    if (size(suff[i]) < 10) suff[i] = suff[a].substr(size(suff[a]) - min(size(suff[a]), 10 - size(suff[i]))) + suff[i];
  }
}