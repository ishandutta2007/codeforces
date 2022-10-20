#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n, k), b(n, -1);
  for (int i = 0; i < k; ++i) {
    int x; cin >> x, --x;
    a[x] = min(a[x], i);
    b[x] = max(b[x], i);
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i) {
      if (a[i] == k or a[i - 1] == k) ++res;
      else if (a[i] > b[i - 1]) ++res;
    }
    if (a[i] == k) ++res;
    if (i + 1 < n) {
      if (a[i] == k or a[i + 1] == k) ++res;
      else if (a[i] > b[i + 1]) ++res;
    }
  }
  cout << res << '\n';
}