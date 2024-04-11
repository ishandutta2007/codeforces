#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, s; cin >> n >> s;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  lint res = 0;
  for (int i = 0; i < n / 2; i++) res += max(a[i] - s, 0);
  res += abs(s - a[n / 2]);
  for (int i = n / 2 + 1; i < n; i++) res += max(s - a[i], 0);
  cout << res << '\n';
}