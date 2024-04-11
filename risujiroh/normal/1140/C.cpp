#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<lint> t(n), b(n); for (int i = 0; i < n; ++i) cin >> t[i] >> b[i];
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return b[i] > b[j]; });
  lint res = 0;
  priority_queue< lint, V<lint>, greater<lint> > pque;
  lint s = 0;
  for (int i : idx) {
    pque.push(t[i]);
    s += t[i];
    if (pque.size() > k) {
      s -= pque.top();
      pque.pop();
    }
    res = max(res, s * b[i]);
  }
  cout << res << '\n';
}