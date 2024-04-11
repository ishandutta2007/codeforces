#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  V<lint> l(n), r(n);
  for (int i = 1; i < n; ++i) {
    l[i] = l[i - 1] + (s[i - 1] == 'v' and s[i] == 'v');
  }
  for (int i = n - 2; i >= 0; --i) {
    r[i] = r[i + 1] + (s[i + 1] == 'v' and s[i] == 'v');
  }
  lint res = 0;
  for (int i = 1; i + 1 < n; ++i) if (s[i] == 'o') {
    res += l[i - 1] * r[i + 1];
  }
  cout << res << '\n';
}