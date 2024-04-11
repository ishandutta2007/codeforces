#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int m;
  cin >> m;
  while (m--) {
    long long n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<bool> hard(n);
    long long sa = 0, sb = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      hard[i] = x;
      ++(x ? sb : sa);
    }
    vector<long long> t(n);
    for (auto&& e : t) {
      cin >> e;
    }
    map< int, vector<int> > mp;
    for (int i = 0; i < n; ++i) {
      mp[t[i]].push_back(i);
    }
    int res = 0;
    if (sa * a + sb * b <= T) {
      res = n;
    }
    long long ma = 0, mb = 0;
    for (auto e : mp) {
      long long ct = e.first - 1;
      long long ra = sa - ma, rb = sb - mb;
      if (ma * a + mb * b <= ct) {
        int rT = ct - ma * a - mb * b;
        int crr = ma + mb;
        int x = min(rT / a, ra);
        rT -= x * a;
        crr += x;
        x = min(rT / b, rb);
        rT -= x * b;
        crr += x;
        res = max(res, crr);
      }
      for (int i : e.second) {
        if (hard[i]) {
          ++mb;
        } else {
          ++ma;
        }
      }
    }
    cout << res << '\n';
  }
}