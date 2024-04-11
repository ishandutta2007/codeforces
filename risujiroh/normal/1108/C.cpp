#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  string t = "BGR";
  int r = n;
  string res;
  do {
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      curr += s[i] != t[i % 3];
    }
    if (curr < r) {
      r = curr;
      res = t;
    }
  } while (next_permutation(begin(t), end(t)));
  cout << r << '\n';
  for (int i = 0; i < n; ++i) {
    cout << res[i % 3];
  }
  cout << '\n';
}