#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int l0 = n, r0 = -1, l1 = n, r1 = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') l0 = min(l0, i), r0 = i;
    if (s[i] == '1') l1 = min(l1, i), r1 = i;
  }
  if (r0 - l0 < k) return cout << "tokitsukaze" << '\n', 0;
  if (r1 - l1 < k) return cout << "tokitsukaze" << '\n', 0;
  V<> p0(n, n), p1(n, n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      p0[i] = i;
      p1[i] = i ? p1[i - 1] : n;
    } else {
      p0[i] = i ? p0[i - 1] : n;
      p1[i] = i;
    }
  }
  V<> n0(n + 1, -1), n1(n + 1, -1);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      n0[i] = i;
      n1[i] = i + 1 < n ? n1[i + 1] : -1;
    } else {
      n0[i] = i + 1 < n ? n0[i + 1] : -1;
      n1[i] = i;
    }
  }
  bool ok = false;
  for (int i = 0; i + k <= n; ++i) {
    {
      int l0 = min(i, n0[0]);
      int r0 = max(i + k - 1, p0.back());
      int l1 = n1[0] < i ? n1[0] : n1[i + k];
      int r1 = p1.back() >= i + k ? p1.back() : i ? p1[i - 1] : n;
      if (!(r0 - l0 < k) and !(r1 - l1 < k)) ok = true;
    }
    {
      int l0 = n0[0] < i ? n0[0] : n0[i + k];
      int r0 = p0.back() >= i + k ? p0.back() : i ? p0[i - 1] : n;
      int l1 = min(i, n1[0]);
      int r1 = max(i + k - 1, p1.back());
      if (!(r0 - l0 < k) and !(r1 - l1 < k)) ok = true;
    }
  }
  if (!ok) cout << "quailty" << '\n';
  else cout << "once again" << '\n';
}