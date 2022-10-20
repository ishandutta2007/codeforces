#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  int n; cin >> n;
  auto query = [&](int t, int i, int j, int k) -> lint {
    cout << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    lint res; cin >> res;
    return res;
  };
  int a = 1;
  for (int i = 2; i < n; ++i) {
    if (query(2, 0, a, i) < 0) {
      a = i;
    }
  }
  V<lint> area(n);
  for (int i = 1; i < n; ++i) if (i != a) {
    area[i] = query(1, 0, a, i);
  }
  int m = max_element(begin(area), end(area)) - begin(area);
  V<> rs, ls;
  for (int i = 1; i < n; ++i) if (i != m) {
    if (query(2, 0, m, i) < 0) {
      rs.push_back(i);
    } else {
      ls.push_back(i);
    }
  }
  sort(begin(rs), end(rs), [&](int l, int r) { return area[l] < area[r]; });
  sort(begin(ls), end(ls), [&](int l, int r) { return area[l] > area[r]; });
  V<> res{0};
  res.insert(end(res), begin(rs), end(rs));
  res.push_back(m);
  res.insert(end(res), begin(ls), end(ls));
  cout << 0;
  for (int e : res) {
    cout << ' ' << e + 1;
  }
  cout << endl;
}