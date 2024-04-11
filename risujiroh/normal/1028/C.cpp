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
  struct rec { int id, x1, y1, x2, y2; };
  V<rec> a(n); for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    a[i] = rec{i, x1, y1, x2, y2};
  }
  auto ca = a;
  int ir, il, iu, id;
  auto f = [&] {
    sort(a.begin(), a.end(), [](rec a, rec b) { return a.x1 < b.x1; });
    ir = a.back().id;
    sort(a.begin(), a.end(), [](rec a, rec b) { return a.x2 < b.x2; });
    il = a[0].id;
    sort(a.begin(), a.end(), [](rec a, rec b) { return a.y1 < b.y1; });
    iu = a.back().id;
    sort(a.begin(), a.end(), [](rec a, rec b) { return a.y2 < b.y2; });
    id = a[0].id;
    if (ca[ir].x1 <= ca[il].x2 and ca[iu].y1 <= ca[id].y2) {
      cout << ca[ir].x1 << ' ' << ca[iu].y1 << '\n';
      return true;
    }
    return false;
  };
  if(f()) return 0;
  int i1, i2;
  if (ca[ir].x1 > ca[il].x2) {
    i1 = ir, i2 = il;
  } else {
    i1 = iu, i2 = id;
  }
  a.clear();
  for (int i = 0; i < n; i++) if (i != i1) a.push_back(ca[i]);
  if(f()) return 0;
  a.clear();
  for (int i = 0; i < n; i++) if (i != i2) a.push_back(ca[i]);
  if(f()) return 0;
}