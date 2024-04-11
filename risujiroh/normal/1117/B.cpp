#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<lint> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  sort(rbegin(a), rend(a));
  int q = m / (k + 1), r = m % (k + 1);
  lint res = q * (k * a[0] + a[1]) + r * a[0];
  cout << res << '\n';
}