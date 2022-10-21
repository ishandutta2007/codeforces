#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  V<> b{4, 8, 15, 16, 23, 42};
  int n; cin >> n;
  V<> c(6);
  int res = 0;
  while (n--) {
    int a; cin >> a;
    a = lower_bound(begin(b), end(b), a) - begin(b);
    if (!a) ++c[0];
    else {
      if (c[a - 1]) {
        --c[a - 1];
        ++c[a];
      } else {
        ++res;
      }
    }
  }
  for (int i = 0; i < 5; ++i) res += c[i] * (i + 1);
  cout << res << '\n';
}