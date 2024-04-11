#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n + 1, -1), b(n + 1, -1);
  for (int i = 0; i < 2 * n; ++i) {
    int x; cin >> x;
    if (a[x] == -1) a[x] = i;
    else b[x] = i;
  }
  a[0] = b[0] = 0;
  lint res = 0;
  for (int i = 0; i < n; ++i) {
    int curr = 1e9;
    curr = min(curr, abs(a[i + 1] - a[i]) + abs(b[i + 1] - b[i]));
    curr = min(curr, abs(b[i + 1] - a[i]) + abs(a[i + 1] - b[i]));
    res += curr;
  }
  cout << res << '\n';
}