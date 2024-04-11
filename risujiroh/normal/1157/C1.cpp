#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int l = 1;
  while (l < n and a[l - 1] < a[l]) ++l;
  int r = n - 1;
  while (r > 0 and a[r - 1] > a[r]) --r;
  r = max(r, l);
  string s(n, 0);
  V<> idx;
  for (int i = 0; i < l; ++i) {
    s[i] = 'L';
    idx.push_back(i);
  }
  for (int i = r; i < n; ++i) {
    s[i] = 'R';
    idx.push_back(i);
  }
  sort(begin(idx), end(idx), [&](int i, int j) { return a[i] < a[j]; });
  string res;
  for (int i : idx) {
    res += s[i];
  }
  cout << res.size() << '\n';
  cout << res << '\n';
}