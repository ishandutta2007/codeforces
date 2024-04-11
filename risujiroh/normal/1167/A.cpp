#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int i = s.find('8');
    // cerr << i << '\n';
    cout << (i >= 0 and n - 1 - i >= 10 ? "YES" : "NO") << '\n';
  }
}