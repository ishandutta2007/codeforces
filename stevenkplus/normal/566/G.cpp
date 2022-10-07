#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, int> point; // ((x, y), id)

const int MAXN = 200100;

#define x first
#define y second
point upper[MAXN];
point points[MAXN];

pll operator-(point a, point b) {
  return pll(a.x.x - b.x.x, a.x.y - b.x.y);
}

ll cross(pll a, pll b) {
  return a.x * b.y - a.y * b.x;
}

bool up(point &a, point &b, point &c) {
  if (b == c) return true;
  ll cr = cross(b - a, c - a);
  return cr > 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int lol, lol2;
  scanf("%d %d", &lol, &lol2);

  for(int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = point(pll(x, y), 1);
  }

  for(int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[n + i] = point(pll(x, y), 0);
  }

  n += m;
  sort(points, points + n);
  int start = 0;
  for(int i = 0; i < n; ++i) {
    if (points[i].x.y > points[start].x.y) {
      start = i;
    }
  }

  upper[1] = points[start];

  int cur = 1;
  for(int i = start + 1; i < n; ++i) {
    point &p = points[i];
    while (cur >= 2 && up(upper[cur - 1], upper[cur], p)) {
      --cur;
    }
    upper[++cur] = p;
  }

  bool ans = false;
  for(int i = 1; i <= cur; ++i) {
    int a = upper[i].x.x, b = upper[i].x.y;
//    printf("(%d, %d) ", a, b);
    if (upper[i].y == 1) {
      ans = true;
    }
  }

  int xright = upper[cur].x.x;
  for(int i = 0; i < n; ++i) {
    if (points[i].x.x == xright && points[i].y == 1) {
      ans = true;
    }
  }

  if (ans) {
    printf("Max\n");
  } else {
    printf("Min\n");
  }
  return 0;
}