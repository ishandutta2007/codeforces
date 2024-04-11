#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<lint> c(n + 1); for (int i = 0; i < n; i++) c[i + 1] = c[i] + a[i];
  for (int i = 0; i < n; i++) cout << c[i + 1] / m - c[i] / m << ' ';
  cout << '\n';
}