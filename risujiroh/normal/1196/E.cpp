#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int b, w; cin >> b >> w;
    int ox = 1e6 + 1, oy = 1e6;
    if (b > w) {
      swap(b, w);
      ++ox;
    }
    if (w > 3 * b + 1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    auto out = [&](int x, int y) -> void {
      cout << ox + x << ' ' << oy + y << '\n';
    };
    V< pair<int, int> > v;
    for (int x = 0; x < b; ++x) {
      out(2 * x, 0);
      v.emplace_back(2 * x, -1);
      v.emplace_back(2 * x, 1);
      v.emplace_back(2 * x + 1, 0);
      v.emplace_back(2 * x - 1, 0);
    }
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    sort(begin(v), end(v), [&](auto l, auto r) {
      return make_pair(abs(l.second), l.first) < make_pair(abs(r.second), r.first); 
    });
    for (int i = 0; i < w; ++i) {
      out(v[i].first, v[i].second);
    }
  }
}