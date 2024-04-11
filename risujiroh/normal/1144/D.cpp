#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> c(2e5 + 1);
  for (int i = 0; i < n; ++i) {
    ++c[a[i]];
  }
  int mx = *max_element(begin(c), end(c));
  int goal;
  for (int x = 0; x <= 2e5; ++x) if (c[x] == mx) {
    goal = x;
    break;
  }
  int k = n - mx;
  cout << k << '\n';
  int s;
  for (int i = 0; i < n; ++i) if (a[i] == goal) {
    s = i;
    break;
  }
  for (int i = s + 1; i < n; ++i) if (a[i] != goal) {
    if (a[i] > a[i - 1]) {
      cout << "2 " << i + 1 << ' ' << i << '\n';
    } else {
      cout << "1 " << i + 1 << ' ' << i << '\n';
    }
    a[i] = goal;
  }
  for (int i = s - 1; i >= 0; --i) if (a[i] != goal) {
    if (a[i] > a[i + 1]) {
      cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
    } else {
      cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
    }
    a[i] = goal;
  }
}