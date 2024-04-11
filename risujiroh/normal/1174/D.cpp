#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, x; cin >> n >> x;
  set<int> se;
  V<> c;
  for (int i = 0; i < 1 << n; ++i) {
    if (se.count(i)) continue;
    c.push_back(i);
    se.insert(i);
    se.insert(i ^ x);
  }
  int m = c.size() - 1;
  cout << m << '\n';
  for (int i = 0; i < m; ++i) cout << (c[i] ^ c[i + 1]) << " \n"[!(m + ~i)];
}