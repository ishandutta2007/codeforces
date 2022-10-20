#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  V<> l(n + 1), r(n + 1);
  for (int i = 0; i < n; ++i) {
    l[i + 1] = l[i] + (l[i] < m and t[l[i]] == s[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    r[i] = r[i + 1] + (r[i + 1] < m and t[m + ~r[i + 1]] == s[i]);
  }

  auto chk = [&](int x) -> bool {
    for (int i = 0; i + x <= n; ++i) {
      if (l[i] + r[i + x] >= m) {
        return true;
      }
    }
    return false;
  };

  int ok = 0, ng = n;
  while (ng - ok > 1) {
    int mid = ok + ng >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}