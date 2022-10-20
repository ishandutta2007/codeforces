#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int h, n; cin >> h >> n;
    deque<int> p(n); for (auto&& e : p) cin >> e;
    p.push_back(0);
    int res = 0;
    while ((int)p.size() >= 3) {
      if (p[0] - p[1] >= 2) {
        p[0] = p[1] + 1;
        continue;
      }
      if (p[1] - p[2] == 1) {
        p.pop_front();
        p.pop_front();
      } else {
        p.pop_front();
        --p[0];
        ++res;
      }
    }
    cout << res << '\n';
  }
}