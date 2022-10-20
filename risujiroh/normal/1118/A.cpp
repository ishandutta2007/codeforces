#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    lint n, a, b; cin >> n >> a >> b;
    lint res;
    if (2 * a <= b) res = n * a;
    else res = n / 2 * b + (n & 1) * a;
    cout << res << '\n';
  }
}