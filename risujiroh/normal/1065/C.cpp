#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> h(n); for (int i = 0; i < n; i++) cin >> h[i];
  sort(h.begin(), h.end());
  V<lint> ch(n + 1);
  for (int i = 0; i < n; i++) ch[i + 1] = ch[i] + h[i];
  V<lint> a(h.back() + 1);
  for (int i = 0; i <= h.back(); i++) {
    int j = lower_bound(h.begin(), h.end(), i) - h.begin();
    a[i] = (ch.back() - ch[j]) - (lint) (n - j) * i;
  }
  int res = 0;
  lint t = 0;
  for (int i = h.back() - 1; i >= h[0]; i--) {
    if (t + a[i] - a[i + 1] <= k) {
      t += a[i] - a[i + 1];
    } else {
      t = a[i] - a[i + 1];
      res++;
    }
  }
  res += t > 0;
  cout << res << '\n';
}