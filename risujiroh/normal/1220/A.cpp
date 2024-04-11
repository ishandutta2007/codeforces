#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int z = count(begin(s), end(s), 'z');
  int o = count(begin(s), end(s), 'n');
  V<> res(o, 1);
  while (z--) {
    res.push_back(0);
  }
  int m = res.size();
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[i == m - 1];
  }
}