#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n + 1);
  for (int i = 0; i < n; ++i) {
    char c; cin >> c;
    if (c == '(') {
      a[i + 1] = a[i] + 1;
    } else {
      a[i + 1] = a[i] - 1;
    }
  }
  if (a[n]) {
    cout << 0 << '\n';
    cout << 1 << ' ' << 1 << '\n';
    return 0;
  }
  int o = min_element(begin(a), end(a)) - begin(a);
  rotate(begin(a), begin(a) + o, begin(a) + n);
  for (int i = n - 1; i >= 0; --i) {
    a[i] -= a[0];
  }
  int c0 = count(begin(a), begin(a) + n, 0);
  int mx = c0, l = 0, r = 0;

  V<> idx;
  for (int i = 0; i <= n; ++i) if (a[i] == 0) {
    idx.push_back(i);
  }
  int m = idx.size();
  for (int p = 0; p < m - 1; ++p) {
    int c1 = count(begin(a) + idx[p], begin(a) + idx[p + 1], 1);
    if (c1 > mx) {
      mx = c1;
      l = idx[p], r = idx[p + 1] - 1;
    }
  }

  V<>().swap(idx);
  for (int i = 0; i <= n; ++i) if (a[i] < 2) {
    idx.push_back(i);
  }
  m = idx.size();
  for (int p = 0; p < m - 1; ++p) {
    int c2 = count(begin(a) + idx[p], begin(a) + idx[p + 1], 2);
    if (c0 + c2 > mx) {
      mx = c0 + c2;
      l = idx[p], r = idx[p + 1] - 1;
    }
  }

  cout << mx << '\n';
  cout << (o + l) % n + 1 << ' ' << (o + r) % n + 1 << '\n';
}