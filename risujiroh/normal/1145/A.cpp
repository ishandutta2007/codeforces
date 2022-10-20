#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int rec(V<> a) {
  int n = a.size();
  if (is_sorted(begin(a), end(a))) return n;
  V<> b, c;
  for (int i = 0; i < n / 2; ++i) {
    b.push_back(a[i]);
    c.push_back(a[n / 2 + i]);
  }
  return max(rec(b), rec(c));
}
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  cout << rec(a) << '\n';
}