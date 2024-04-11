#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }
const lint inf = 1e18;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> p(n), c(n); for (int i = 0; i < n; i++) cin >> p[i] >> c[i], p[i]--;
  VV<> pc(m);
  for (int i = 0; i < n; i++) pc[p[i]].push_back(c[i]);
  for (auto&& i : pc) sort(i.begin(), i.end());
  V<> v(m);
  for (int i = 0; i < n; i++) v[p[i]]++;
  int ma = *max_element(v.begin(), v.end());
  lint res = inf;
  for (int k = ma + 1; k; k--) {
    lint tmp = 0;
    int t = v[0];
    priority_queue<int, V<>, greater<int> > q;
    for (int i = 1; i < m; i++) {
      if (v[i] >= k) {
        for (int j = 0; j < v[i] - k + 1; j++) {
          tmp += pc[i][j];
          t++;
        }
        for (int j = v[i] - k + 1; j < pc[i].size(); j++) q.push(pc[i][j]);
      } else {
        for (int j = 0; j < pc[i].size(); j++) q.push(pc[i][j]);
      }
    }
    while (t < k and !q.empty()) {
      tmp += q.top(); q.pop();
      t++;
    }
    res = min(res, tmp);
  }
  cout << res << '\n';
}