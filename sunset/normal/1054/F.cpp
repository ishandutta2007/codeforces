#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

struct point_t {
  int x, y, i;
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<point_t> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].i = i;
  }
  
  vector<int> nx(n, -1), ny(n, -1);
  sort(a.begin(), a.end(), [&](const point_t &a, const point_t &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
  });
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n && a[i].y == a[i + 1].y) {
      nx[a[i].i] = a[i + 1].i;
    }
  }
  sort(a.begin(), a.end(), [&](const point_t &a, const point_t &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n && a[i].x == a[i + 1].x) {
      ny[a[i].i] = a[i + 1].i;
    }
  }
  sort(a.begin(), a.end(), [&](const point_t &a, const point_t &b) {
    return a.i < b.i;
  });

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    if (~nx[i]) {
      for (int j = 0; j < n; ++j) {
        if (~ny[j]) {
          if (a[j].x > a[i].x && a[i].y > a[j].y && a[nx[i]].x > a[j].x && a[ny[j]].y > a[i].y) {
            adj[i].push_back(j);
          }
        }
      }
    }
  }

  vector<bool> cx(n), cy(n);
  vector<int> p(n, -1);
  for (int i = 0; i < n; ++i) {
    vector<bool> visit(n);

    function<bool(int)> dfs = [&](int x) {
      if (visit[x]) {
        return false;
      }
      visit[x] = true;
      for (auto y : adj[x]) {
        if (!~p[y] || dfs(p[y])) {
          p[y] = x;
          return true;
        }
      }
      return false;
    };

    if (!dfs(i)) {
      for (int x = 0; x < n; ++x) {
        if (visit[x] && !cx[x]) {
          cx[x] = true;
          for (auto y : adj[x]) {
            cy[y] = true;
          }
        }
      }
    }
  }

  vector<vector<int>> answer_x, answer_y;
  sort(a.begin(), a.end(), [&](const point_t &a, const point_t &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
  });
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && cx[a[j].i] && ~nx[a[j].i]) {
      ++j;
    }
    answer_x.push_back({a[i].y, a[i].x, a[j].x});
    i = j;
  }
  sort(a.begin(), a.end(), [&](const point_t &a, const point_t &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && !cy[a[j].i] && ~ny[a[j].i]) {
      ++j;
    }
    answer_y.push_back({a[i].x, a[i].y, a[j].y});
    i = j;
  }

  cout << answer_x.size() << endl;
  for (auto p : answer_x) {
    cout << p[1] << " " << p[0] << " " << p[2] << " " << p[0] << endl;
  }
  cout << answer_y.size() << endl;
  for (auto p : answer_y) {
    cout << p[0] << " " << p[1] << " " << p[0] << " " << p[2] << endl;
  }
  return 0;
}