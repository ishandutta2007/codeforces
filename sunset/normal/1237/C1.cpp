#include <bits/stdc++.h>

using namespace std;

struct pt {
  int x, y, z, i;

  bool operator<(const pt& o) const {
    return make_tuple(x, y, z) < make_tuple(o.x, o.y, o.z);
  }
};

int solve1d(vector<pt> p) {
  for (int i = 0; i + 1 < (int) p.size(); i += 2) {
    cout << p[i].i << " " << p[i + 1].i << "\n";
  }
  if ((int) p.size() % 2) {
    return p.back().i;
  } else {
    return -1;
  }
}

int solve2d(vector<pt> p) {
  int n = p.size();
  int id = -1;
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && p[i].y == p[j].y) {
      ++j;
    }
    int new_id = solve1d(vector<pt>(p.begin() + i, p.begin() + j));
    if (new_id != -1) {
      if (id != -1) {
        cout << id << " " << new_id << "\n";
        id = -1;
      } else {
        id = new_id;
      }
    }
  }
  return id;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pt> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y >> p[i].z;
    p[i].i = i + 1;
  }
  sort(p.begin(), p.end());
  int id = -1;
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && p[i].x == p[j].x) {
      ++j;
    }
    int new_id = solve2d(vector<pt>(p.begin() + i, p.begin() + j));
    if (new_id != -1) {
      if (id != -1) {
        cout << id << " " << new_id << "\n";
        id = -1;
      } else {
        id = new_id;
      }
    }
  }
  return 0;
}