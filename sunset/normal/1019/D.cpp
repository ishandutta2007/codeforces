#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2005;

struct point_t {
  int x, y;

  point_t(int x = 0, int y = 0):x(x), y(y) {
  }

  bool operator < (const point_t &b) const {
    return x < b.x || (x == b.x && y < b.y);
  }

  point_t operator - (const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }

  ll operator * (const point_t &b) const {
    return (ll)x * b.y - (ll)y * b.x;
  }

  void print() {
    printf("%d %d\n", x, y);
  }
} p[N];

struct line_t {
  int x, y;
  ld k;

  bool operator < (const line_t &b) const {
    return k < b.k;
  }
} l[N * N];

int n, total, id[N], pos[N];
ll area;

ll calc(point_t a, point_t b, point_t c) {
  return abs((b - a) * (c - a));
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %lld", &n, &area);
  area <<= 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
    id[i] = pos[i] = i;
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ++total;
      l[total].x = i;
      l[total].y = j;
      l[total].k = atan2l(p[j].y - p[i].y, p[j].x - p[i].x);
    }
  }
  sort(l + 1, l + total + 1);
  for (int i = 1; i <= total; ++i) {
    int a = l[i].x, b = l[i].y;
    if (id[a] > id[b]) {
      swap(a, b);
    }
    int l = 1, r = id[a] - 1;
    while (l <= r) {
      int mid = l + r >> 1;
      ll value = calc(p[a], p[b], p[pos[mid]]);
      if (value == area) {
        puts("Yes");
        p[a].print();
        p[b].print();
        p[pos[mid]].print();
        return 0;
      } else if (value > area) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    l = id[b] + 1, r = n;
    while (l <= r) {
      int mid = l + r >> 1;
      ll value = calc(p[a], p[b], p[pos[mid]]);
      if (value == area) {
        puts("Yes");
        p[a].print();
        p[b].print();
        p[pos[mid]].print();
        return 0;
      } else if (value > area) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    swap(id[a], id[b]);
    swap(pos[id[a]], pos[id[b]]);
  }
  puts("No");
  return 0;
}