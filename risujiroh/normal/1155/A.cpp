#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0; i < n - 1; ++i) if (s[i] > s[i + 1]) {
    cout << "YES" << '\n';
    cout << i + 1 << ' ' << i + 2 << '\n';
    return 0;
  }
  cout << "NO" << '\n';
}