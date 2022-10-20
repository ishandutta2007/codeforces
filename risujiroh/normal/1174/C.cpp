#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n + 1);
  int t = 0;
  for (int p = 2; p <= n; ++p) if (!a[p]) {
    ++t;
    for (int i = p; i <= n; i += p) if (!a[i]) a[i] = t;
  }
  for (int i = 2; i <= n; ++i) cout << a[i] << " \n"[i == n];
}