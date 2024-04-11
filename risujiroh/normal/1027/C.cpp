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
  for (int ti = 0; ti < t; ti++) {
    int n; cin >> n;
    V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp; for (int i = 0; i < n; i++) mp[a[i]]++;
    V<> b;
    for (auto&& i : mp) {
      if (i.second >= 2) b.push_back(i.first);
      if (i.second >= 4) b.push_back(i.first);
    }
    sort(b.begin(), b.end());
    int m = b.size();
    V<> res(2);
    double t = 1e10;
    for (int i = 0; i < m - 1; i++) {
      if (t > (double) b[i + 1] / b[i]) {
        t = (double) b[i + 1] / b[i];
        res[0] = b[i];
        res[1] = b[i + 1];
      }
    }
    cout << res[0] << ' ' << res[0] << ' ' << res[1] << ' ' << res[1] << endl;
  }
}