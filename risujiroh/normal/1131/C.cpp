#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  sort(begin(a), end(a));
  auto chk = [&](int x, bool out = false) -> bool {
    deque<int> dq(1, a[0]);
    for (int i = 1; i < n; ++i) {
      int l = dq.front();
      int r = dq.back();
      if (a[i] - l > x and a[i] - r > x) return false;
      else if (a[i] - l > x) dq.push_back(a[i]);
      else if (a[i] - r > x) dq.push_front(a[i]);
      else {
        if (l < r) dq.push_front(a[i]);
        else dq.push_back(a[i]);
      }
    }
    if (out) {
      assert(dq.size() == n);
      for (int i = 0; i < n; ++i) {
        cout << dq[i] << " \n"[i == n - 1];
      }
    }
    return abs(dq.front() - dq.back()) <= x;
  };
  int ng = -1, ok = 1e9;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (chk(mid) ? ok : ng) = mid;
  }
  chk(ok, true);
}