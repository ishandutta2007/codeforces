#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<lint> b(n); for (int i = 0; i < n; i++) cin >> b[i];
  V<lint> ca(n + 1); for (int i = 0; i < n; i++) ca[i + 1] = ca[i] + a[i];
  V<lint> cb(n + 1); for (int i = 0; i < n; i++) cb[i + 1] = cb[i] + b[i];
  V<lint> ra(n + 1); for (int i = n - 1; i >= 0; i--) ra[i] = ra[i + 1] + i * a[i];
  V<lint> rb(n + 1); for (int i = n - 1; i >= 0; i--) rb[i] = rb[i + 1] + i * b[i];
  V<lint> la(n + 1); for (int i = n - 1; i >= 0; i--) la[i] = la[i + 1] + (n - 1 - i) * a[i];
  V<lint> lb(n + 1); for (int i = n - 1; i >= 0; i--) lb[i] = lb[i + 1] + (n - 1 - i) * b[i];
  lint res = 0, mem = 0;
  for (int i = 0; i < n; i++) {
    lint tmp = mem;
    if (i & 1) {
      tmp += i * (cb[n] - cb[i]) + rb[i];
      tmp += (n + i) * (ca[n] - ca[i]) + la[i];
      mem += 2 * i * b[i] + (2 * i + 1) * a[i];
    } else {
      tmp += i * (ca[n] - ca[i]) + ra[i];
      tmp += (n + i) * (cb[n] - cb[i]) + lb[i];
      mem += 2 * i * a[i] + (2 * i + 1) * b[i];
    }
    res = max(res, tmp);
  }
  cout << res << '\n';
}