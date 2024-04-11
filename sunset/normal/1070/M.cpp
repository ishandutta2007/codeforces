#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld pi = acos(-1);
const ld eps = 1e-9;

struct point_t {
  int x, y, id, degree;

  point_t(int x = 0, int y = 0, int id = 0, int degree = 0):x(x), y(y), id(id), degree(degree) {
  }
};

void solve(vector<point_t> points) {
  int max_degree = 0, max_id = -1;
  for (int i = 0; i < points.size(); ++i) {
    if (max_degree < points[i].degree) {
      max_degree = points[i].degree;
      max_id = i;
    }
  }
  if (max_degree == 1) {
    for (int i = 0; i < points.size(); ++i) {
      if (!points[i].degree) {
        max_id = i;
      }
    }
    for (int i = 0; i < points.size(); ++i) {
      if (i != max_id) {
        cout << points[i].id + 1 << " " << points[max_id].id + 1 << endl;
      }
    }
  } else {
    int n = points.size() - 1;
    swap(points[max_id], points[n]);
    vector<pair<ld, int>> events;
    for (int i = 0; i < n; ++i) {
      ld from = atan2(points[i].y - points[n].y, points[i].x - points[n].x);
      ld to = from + pi;
      if (to > pi) {
        to -= pi * 2;
      }
      events.emplace_back(from, i);
      events.emplace_back(to, i + n);
    }
    sort(events.begin(), events.end());
    vector<bool> side(n);
    int sum = 0;
    for (auto p : events) {
      if (p.first > eps && p.second < n) {
        sum += points[p.second].degree - 1;
        side[p.second] = true;
      }
    }
    for (auto p : events) {
      if (sum <= -1 && sum >= 1 - max_degree) {
        break;
      }
      if (p.second < n) {
        sum += points[p.second].degree - 1;
        side[p.second] = true;
      } else {
        sum -= points[p.second - n].degree - 1;
        side[p.second - n] = false;
      }
    }
    vector<point_t> left, right;
    for (int i = 0; i < n; ++i) {
      if (side[i]) {
        left.push_back(points[i]);
      } else {
        right.push_back(points[i]);
      }
    }
    left.emplace_back(points[n].x, points[n].y, points[n].id, -sum);
    right.emplace_back(points[n].x, points[n].y, points[n].id, sum + max_degree);
    solve(left);
    solve(right);
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> degree(m);
    for (int i = 0; i < m; ++i) {
      cin >> degree[i];
    }
    vector<point_t> points(n + m);
    for (int i = 0; i < n; ++i) {
      cin >> points[i].x >> points[i].y;
      points[i].id = i;
    }
    for (int i = 0; i < m; ++i) {
      cin >> points[i + n].x >> points[i + n].y;
      points[i + n].degree = degree[i];
      points[i + n].id = i;
    }
    cout << "YES" << endl;
    solve(points);
  }
  return 0;
}