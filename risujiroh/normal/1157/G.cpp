#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V< bitset<200> > a(n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    int x; cin >> x;
    if (x) a[i][j] = true;
  }
  bitset<200> mask;
  for (int j = 0; j < m; ++j) mask[j] = true;
  auto chk = [&]() -> void {
    for (int i = 1; i < n; ++i) {
      if (a[0] != a[i] and (a[0] ^ mask) != a[i]) return;
    }
    cout << "YES" << '\n';
    string s;
    for (int i = 0; i < n; ++i) {
      s += '0' + (a[i] != a[0]);
    }
    string t;
    for (int j = 0; j < m; ++j) {
      t += '0' + a[0][j];
    }
    cout << s << '\n';
    cout << t << '\n';
    exit(0);
  };
  chk();
  for (int pi = 0; pi < n; ++pi) for (int pj = 0; pj < m; ++pj) {
    a[n + ~pi][m + ~pj] = !a[n + ~pi][m + ~pj];
    chk();
  }
  cout << "NO" << '\n';
}