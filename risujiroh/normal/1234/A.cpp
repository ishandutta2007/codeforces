#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    lint s = accumulate(begin(a), end(a), 0LL);
    lint res = (s + n - 1) / n;
    cout << res << '\n'; 
  }
}