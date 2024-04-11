#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  for (int i = 0; i < n; ++i) if (a[i] == 1) {
    a[i] = 3;
    break;
  }
  sort(rbegin(a), rend(a));
  if (a[0] == 3) {
    a[0] = 1;
    if (n > 1) swap(a[0], a[1]);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[!(n + ~i)];
  }
}