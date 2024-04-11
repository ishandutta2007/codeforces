#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  string a, b; cin >> a >> b;
  lint n00 = 0, n01 = 0, n10 = 0, n11 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0' and b[i] == '0') n00++;
    if (a[i] == '0' and b[i] == '1') n01++;
    if (a[i] == '1' and b[i] == '0') n10++;
    if (a[i] == '1' and b[i] == '1') n11++;
  }
  lint res = n00 * (n10 + n11) + n01 * n10;
  cout << res << '\n';
}