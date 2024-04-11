#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;
    V<> a(n); for (auto&& e : a) cin >> e;
    int mn = 2e9, mi = -1;
    for (int i = 0; i + k < n; ++i) {
      if (a[i + k] - a[i] < mn) {
        mn = a[i + k] - a[i];
        mi = i;
      }
    }
    cout << (a[mi + k] + a[mi]) / 2 << '\n';
  }
}