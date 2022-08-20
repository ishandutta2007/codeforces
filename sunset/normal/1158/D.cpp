#include <bits/stdc++.h>

using namespace std;

struct point {
  int x, y;

  point(int x = 0, int y = 0): x(x), y(y) {
  }

  long long operator * (const point &other) const {
    return (long long) x * other.y - (long long) y * other.x;
  }

  point operator - (const point &other) const {
    return point(x - other.x, y - other.y);
  }

  bool operator == (const point &other) const {
    return x == other.x && y == other.y;
  }

  bool operator < (const point &other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
};

vector<point> convex_hull(vector<point> points) {
  if ((int) points.size() == 1) {
    return points;
  }
  vector<point> hull;
  for (int rot = 0; rot < 2; ++rot) {
    int limit = hull.size();
    for (auto p : points) {
      while ((int) hull.size() > limit + 1 && (hull[hull.size() - 1] - hull[hull.size() - 2]) * (p - hull[hull.size() - 2]) <= 0) {
        hull.pop_back();
      }
      hull.push_back(p);
    }
    hull.pop_back();
    reverse(points.begin(), points.end());
  }
  return hull;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<point, int> index;
  vector<point> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
    index[p[i]] = i + 1;
  }
  sort(p.begin(), p.end());
  string s;
  cin >> s;
  s.push_back('L');
  point last = convex_hull(p)[0];
  cout << index[last];
  for (int i = 0; i < n - 1; ++i) {
    vector<point> q = convex_hull(p);
    int j = find(q.begin(), q.end(), last) - q.begin();
    p.erase(find(p.begin(), p.end(), last));
    last = (s[i] == 'L' ? q[(j + 1) % q.size()] : q[(j + q.size() - 1) % q.size()]);
    cout << " " << index[last];
  }
  cout << "\n";
  return 0;
}