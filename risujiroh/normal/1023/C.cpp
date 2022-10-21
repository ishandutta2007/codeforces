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
  string s; cin >> s;
  k /= 2;
  int c = 0;
  V<bool> b(n);
  for (int i = 0; i < n; i++) {
    if (c >= k) break;
    if (s[i] == '(') b[i] = true, c++;
  }
  c = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (c >= k) break;
    if (s[i] == ')') b[i] = true, c++;
  }
  string res;
  for (int i = 0; i < n; i++) {
    if (b[i]) res += s[i];
  }
  cout << res << '\n';
}