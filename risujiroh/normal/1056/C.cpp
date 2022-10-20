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
  int n, m; cin >> n >> m;
  V<> p(2 * n); for (int i = 0; i < 2 * n; ++i) cin >> p[i];
  V<> a(2 * n, -1);
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    a[x] = y;
    a[y] = x;
  }
  bitset<2000> chosen;
  auto my = [&](int x) -> void {
    cout << x + 1 << endl;
    chosen[x] = true;
  };
  auto op = [&]() -> int {
    int x; cin >> x, --x;
    chosen[x] = true;
    return x;
  };
  V<> id(2 * n); iota(begin(id), end(id), 0);
  sort(rbegin(id), rend(id), [&](int i, int j) { return p[i] < p[j]; });
  int turn; cin >> turn;
  if (turn == 1) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < 2 * n; ++j) if (!chosen[j] and a[j] != -1) {
        if (p[j] > p[a[j]]) {
          my(j); op();
        } else {
          my(a[j]); op();
        }
        break;
      }
    }
    while (chosen.count() < 2 * n) {
      int i = 0;
      for (; i < 2 * n; ++i) if (!chosen[id[i]]) {
        my(id[i]); op();
        break;
      }
    }
  } else {
    for (int i = m + 1; i >= 0; --i)  {
      int x = op();
      if (a[x] != -1) my(a[x]), --m;
      else break;
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < 2 * n; ++j) if (!chosen[j] and a[j] != -1) {
        if (p[j] > p[a[j]]) {
          my(j); op();
        } else {
          my(a[j]); op();
        }
        break;
      }
    }
    while (chosen.count() < 2 * n) {
      int i = 0;
      for (; i < 2 * n; ++i) if (!chosen[id[i]]) {
        my(id[i]);
        if (chosen.count() == 2 * n) break;
        op();
        break;
      }
    }
  }
}