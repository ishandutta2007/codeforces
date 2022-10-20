#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  int v = 0, h = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      cout << "1 " << v + 1 << '\n';
      v = v + 1 & 3;
    } else {
      cout << "4 " << 2 * h + 1 << '\n';
      h = h + 1 & 1;
    }
  }
}