#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    lint n; cin >> n;
    V<> v;
    while (n) {
      v.push_back(n % 3);
      n /= 3;
    }
    v.push_back(0);
    if (count(begin(v), end(v), 2)) {
      for (int i = (int)v.size() - 1; ; --i) if (v[i] == 2) {
        for (int j = i; ; ++j) if (v[j] == 0) {
          v[j] = 1;
          fill(begin(v), begin(v) + j, 0);
          break;
        }
        break;
      }
    }
    lint res = 0;
    while (not v.empty()) {
      res *= 3;
      res += v.back();
      v.pop_back();
    }
    cout << res << '\n';
  }
}