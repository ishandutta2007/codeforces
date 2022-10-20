#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  int res = 0;
  int i = 0;
  while (true) {
    while (i < n and a[i] <= res) ++i;
    res += i < n and a[i] > res;
    if (++i >= n) break;
  }
  cout << res << '\n';
}