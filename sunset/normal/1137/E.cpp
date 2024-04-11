#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x, y;

  point(long long x = 0, long long y = 0): x(x), y(y) {
  }

  point operator - (const point &b) const {
    return point(x - b.x, y - b.y);
  }
};

bool check(point p, point q, point r) {
  point pp = p - q, rr = r - q;
  return (long double) pp.x * rr.y >= (long double) pp.y * rr.x;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  int m;
  cin >> n >> m;
  long long add = 0, slope = 0;
  vector<point> hull(1, point(0, 0));
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int cnt;
      cin >> cnt;
      hull.clear();
      hull.push_back(point(0, 0));
      n += cnt;
      add = slope = 0;
    } else if (type == 2) {
      int cnt;
      cin >> cnt;
      while (hull.size() > 1 && check(point(n, -(n * slope + add)), hull[hull.size() - 2], hull[hull.size() - 1])) {
        hull.pop_back();
      }
      hull.push_back(point(n, -(n * slope + add)));
      n += cnt;
    } else {
      int b, s;
      cin >> b >> s;
      add += b;
      slope += s;
    }
    while (hull.size() > 1 && slope * hull.back().x + hull.back().y >= slope * hull[hull.size() - 2].x + hull[hull.size() - 2].y) {
      hull.pop_back();
    }
    cout << hull.back().x + 1 << " " << slope * hull.back().x + hull.back().y + add << "\n";
  }
  return 0;
}