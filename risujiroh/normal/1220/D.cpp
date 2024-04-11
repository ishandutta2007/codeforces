#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  VV<lint> v(60);
  for (int _ = 0; _ < n; ++_) {
    lint b; cin >> b;
    v[__builtin_ctzll(b)].push_back(b);
  }
  int mx = 0, mxi = -1;
  for (int i = 0; i < 60; ++i) {
    if ((int)v[i].size() > mx) {
      mx = (int)v[i].size();
      mxi = i;
    }
  }
  V<lint> res;
  for (int i = 0; i < 60; ++i) if (i != mxi) {
    res.insert(end(res), begin(v[i]), end(v[i]));
  }
  sort(begin(res), end(res));
  int k = res.size();
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i] << " \n"[i == k - 1];
  }
}