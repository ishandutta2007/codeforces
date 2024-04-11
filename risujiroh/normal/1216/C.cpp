#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int sx[3], sy[3], tx[3], ty[3];
  V<> vx, vy;
  for (int i = 0; i < 3; ++i) {
    cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];
    vx.push_back(sx[i]);
    vx.push_back(tx[i]);
    vy.push_back(sy[i]);
    vy.push_back(ty[i]);
  }
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  for (auto&& e : sx) {
    e = lower_bound(begin(vx), end(vx), e) - begin(vx);
  }
  for (auto&& e : tx) {
    e = lower_bound(begin(vx), end(vx), e) - begin(vx);
  }
  for (auto&& e : sy) {
    e = lower_bound(begin(vy), end(vy), e) - begin(vy);
  }
  for (auto&& e : ty) {
    e = lower_bound(begin(vy), end(vy), e) - begin(vy);
  }
  int n = vx.size(), m = vy.size();
  VV<> a(n, V<>(m));
  for (int i = 1; i < 3; ++i) {
    for (int x = sx[i]; x < tx[i]; ++x) for (int y = sy[i]; y < ty[i]; ++y) {
      ++a[x][y];
    }
  }
  for (int x = sx[0]; x < tx[0]; ++x) for (int y = sy[0]; y < ty[0]; ++y) {
    if (!a[x][y]) {
      return cout << "YES" << '\n', 0;
    }
  }
  cout << "NO" << '\n';
}