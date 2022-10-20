#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    int n; cin >> n;
    string s; cin >> s;
    bool chk = true;
    for (int j = 0; j < n / 2; j++) {
      if (abs(s[j] - s[n - 1 - j]) != 2 and s[j] != s[n - 1 - j]) chk = false;
    }
    cout << (chk ? "YES" : "NO") << '\n';
  }
}