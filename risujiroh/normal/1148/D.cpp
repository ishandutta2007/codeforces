#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n), b(n);
  int k = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    k += a[i] < b[i];
  }
  if (k < n - k) {
    k = n - k;
    for (int i = 0; i < n; ++i) a[i] = -a[i], b[i] = -b[i];
  }
  V<> idx;
  for (int i = 0; i < n; ++i) if (a[i] < b[i]) idx.push_back(i);
  sort(begin(idx), end(idx), [&](int i, int j) { return b[i] > b[j]; });
  cout << k << '\n';
  for (int i = 0; i < k; ++i) cout << idx[i] + 1 << " \n"[!(k + ~i)];
}