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
  V<> p(n); for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  for (int i = 0; i < n; i++) {
    set<int> s;
    int t = i;
    s.insert(t);
    int res;
    while (true) {
      if (s.count(p[t])) {
        res = p[t];
        break;
      }
      s.insert(t = p[t]);
    }
    cout << res + 1 << ' ';
  }
  cout << '\n';
}