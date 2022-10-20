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
  int r = n % (2 * k + 1);
  int i;
  if (1 <= r and r <= k + 1) i = 0;
  else i = k;
  V<> res;
  while (i < n) {
    res.push_back(i);
    i += 2 * k + 1;
  }
  cout << res.size() << '\n';
  for (int v : res) cout << v + 1 << ' ';
  cout << '\n';
}