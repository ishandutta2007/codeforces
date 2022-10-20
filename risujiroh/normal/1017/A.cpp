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
  struct s { int sum, id; };
  V<s> t(n);
  for (int i = 0; i < n; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    t[i] = s{a + b + c + d, i};
  }
  sort(t.begin(), t.end(), [](s a, s b) { return a.sum > b.sum or a.sum == b.sum and a.id < b.id; });
  for (int i = 0; i < n; i++) {
    if (t[i].id == 0) return cout << i + 1 << '\n', 0;
  }
}