#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, p; cin >> n >> p;
  int res = 100;
  for (int k = 1; k < 32; ++k) {
    int x = n - p * k;
    if (x <= 0) continue;
    if (__builtin_popcount(x) > k) continue;
    if (k > x) continue;
    res = min(res, k);
  }
  cout << (res != 100 ? res : -1) << '\n';
}