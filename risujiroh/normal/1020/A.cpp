#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, h, a, b, k; cin >> n >> h >> a >> b >> k;
  for (int i = 0; i < k; i++) {
    int ta, fa, tb, fb; cin >> ta >> fa >> tb >> fb;
    if (ta == tb) cout << abs(fb - fa) << '\n';
    else if (fa < a and fb < a) cout << abs(tb - ta) + (a - fa) + (a - fb) << '\n';
    else if (fa > b and fb > b) cout << abs(tb - ta) + (fa - b) + (fb - b) << '\n';
    else cout << abs(tb - ta) + abs(fb - fa) << '\n';
  }
}