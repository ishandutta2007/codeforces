#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  lint res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] - '0' & 1) continue;
    res += i + 1;
  }
  cout << res << '\n';
}