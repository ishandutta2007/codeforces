#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr int N = 999;
constexpr int K = 666;

constexpr array<int, 8> dx = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr array<int, 8> dy = {0, 1, 1, 1, 0, -1, -1, -1};
bool in(int x, int y) {
  return 0 <= x and x < N and 0 <= y and y < N;
}

int sgn(int x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}

int main() {
  int x, y; cin >> x >> y, --x, --y;
  V<> rx(K), ry(K); for (int i = 0; i < K; ++i) cin >> rx[i] >> ry[i], --rx[i], --ry[i];

  auto mv = [&](int nx, int ny) -> bool {
    assert(in(nx, ny));
    cout << nx + 1 << ' ' << ny + 1 << endl;
    x = nx;
    y = ny;
    int k, nrx, nry; cin >> k >> nrx >> nry, --k, --nrx, --nry;
    if (k == -2) return true;
    rx[k] = nrx;
    ry[k] = nry;
    return false;
  };

  auto chk = [&](int nx, int ny) -> bool {
    if (!in(nx, ny)) return false;
    for (int i = 0; i < K; ++i) {
      if (rx[i] == nx and ry[i] == ny) return false;
    }
    for (int i = 0; i < K; ++i) {
      if (rx[i] == nx or ry[i] == ny) return true;
    }
    return false;
  };

  while (x != N / 2 or y != N / 2) {
    for (int k = 0; k < 8; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (chk(nx, ny)) {
        bool b = mv(nx, ny);
        assert(b);
        return 0;
      }
    }
    if (mv(x + sgn(N / 2 - x), y + sgn(N / 2 - y))) return 0;
  }

  VV<> c; assign(c, 2, 2, 0);
  for (int i = 0; i < K; ++i) {
    c[0][0] += rx[i] < N / 2 and ry[i] < N / 2;
    c[0][1] += rx[i] < N / 2 and ry[i] > N / 2;
    c[1][0] += rx[i] > N / 2 and ry[i] < N / 2;
    c[1][1] += rx[i] > N / 2 and ry[i] > N / 2;
  }

  int mn = min({c[0][0], c[0][1], c[1][0], c[1][1]});
  while (true) {
    for (int k = 0; k < 8; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (chk(nx, ny)) {
        bool b = mv(nx, ny);
        assert(b);
        return 0;
      }
    }
    int nx, ny;
    if (c[0][0] == mn) nx = x + 1, ny = y + 1;
    if (c[0][1] == mn) nx = x + 1, ny = y - 1;
    if (c[1][0] == mn) nx = x - 1, ny = y + 1;
    if (c[1][1] == mn) nx = x - 1, ny = y - 1;
    if (mv(nx, ny)) return 0;
  }
}