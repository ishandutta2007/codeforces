#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  V<> dp0(n + 1), dp1(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    dp0[i] = dp0[i + 1];
    dp1[i] = dp1[i + 1];
    if (s[i] == '0') {
      dp0[i] = max(dp0[i], 1 + max(dp0[i + 1], dp1[i + 1]));
    } else {
      dp1[i] = max(dp1[i], 1 + dp1[i + 1]);
    }
  }

  string t(n, '1');
  for (int i = n - 1; i >= 0; --i) {
    if (1 + max(dp0[i + 1], dp1[i + 1]) == max(dp0[i], dp1[i])) {
      t[i] = '0';
    }
  }
  cout << t << '\n';
}