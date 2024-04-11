#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, h; cin >> n >> h;
  V<> a(n); for (auto&& e : a) cin >> e;
  auto chk = [&](int x) -> bool {
    V<> b(begin(a), begin(a) + x);
    sort(rbegin(b), rend(b));
    lint s = 0;
    for (int i = 0; i < (int) b.size(); i += 2) {
      s += b[i];
    }
    return s <= h;
  };
  int ok = 0, ng = n + 1;
  while (ng - ok > 1) {
    int mid = ok + ng >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}