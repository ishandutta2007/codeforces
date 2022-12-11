#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MD = 998244353;
#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif
constexpr int INF = (int)1e9 + 41;
struct pt {
  int x{}, y{};
};
bool cmpX(const pt &a, const pt &b) { return a.x < b.x; }
bool cmpY(const pt &a, const pt &b) { return a.y < b.y; }

bool solve(const vector<pt> &x1, const vector<pt> &y2, const vector<pt> &y3, int k) {
  auto getK = [](int minX, int maxX, const vector<pt> &v, int st, int dir, int k) {
    for (int i = st; 0 <= i && i < (int)v.size(); i += dir) {
      if (minX <= v[i].x && v[i].x <= maxX) {
        k--;
        if (k == 0) return v[i].y;
      }
    }
    return (INF + 1) * (dir);
  };
  auto kek = [&](int minX, int maxX) -> bool {
    bool a1 = getK(minX, maxX, y2, 0, 1, k) < getK(minX, maxX, y3, (int)y3.size() - 1, -1, k);
    bool a2 = getK(minX, maxX, y3, 0, 1, k) < getK(minX, maxX, y2, (int)y2.size() - 1, -1, k);
    //cout << a1 << " " << a2 << " " << minX << " " << maxX << "\n";
    return a1 || a2;
  };

  bool a1 = kek(x1[k - 1].x + 1, INF);
  bool a2 = kek(-INF, x1[x1.size() - k].x - 1);
  //cout << a1 << " " << a2 << " " << k << "\n";
  return a1 || a2;
}

bool solve2(const vector<pt> &x1, const vector<pt> &x2, const vector<pt> &x3, int k) {
  auto it = lower_bound(x2.begin(), x2.end(), pt({x1[k - 1].x + 1, -INF}), cmpX);
  int ind = static_cast<int>(it - x2.begin()) + k - 1;
  if (ind >= (int)x2.size()) return false;
  it = lower_bound(x3.begin(), x3.end(), pt({x2[ind].x + 1, -INF}), cmpX);
  ind = (int)(it - x3.begin()) + k - 1;
  return (ind < (int)x3.size());
}

void solve() {
  vector<pt> x[3], y[3];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int xx, yy, nn;
    cin >> xx >> yy >> nn;
    x[nn - 1].push_back({xx, yy});
    y[nn - 1].push_back({xx, yy});
  }

  auto kek = [&]() -> int {
    int L = 0;
    int R = n / 3 + 1;
    while (R - L > 1) {
      int M = (R + L) / 2;
      bool ok = false;
      ok |= solve(x[0], y[1], y[2], M);
      ok |= solve(x[1], y[2], y[0], M);
      ok |= solve(x[2], y[0], y[1], M);
      ok |= solve2(x[0], x[1], x[2], M);
      ok |= solve2(x[1], x[2], x[0], M);
      ok |= solve2(x[2], x[0], x[1], M);
      ok |= solve2(x[0], x[2], x[1], M);
      ok |= solve2(x[1], x[0], x[2], M);
      ok |= solve2(x[2], x[1], x[0], M);
      if (ok) L = M;
      else R = M;
    }
    return L;
  };

  for (int i = 0; i < 3; i++) {
    sort(x[i].begin(), x[i].end(), cmpX);
    sort(y[i].begin(), y[i].end(), cmpY);
  }
  int a1 = kek();
  for (int i = 0; i < 3; i++) {
    for (pt &p : x[i]) swap(p.x, p.y);
    for (pt &p : y[i]) swap(p.x, p.y);
    sort(x[i].begin(), x[i].end(), cmpX);
    sort(y[i].begin(), y[i].end(), cmpY);
  }
  int a2 = kek();
  cout << max(a1, a2) * 3 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 2;
  }
  //cin >> t;
  while (t--) {
    solve();
  }
}