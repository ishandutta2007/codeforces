#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3005;
const ld pi = acosl(-1);

struct point_t {
  int x, y, i;
  ld k;

  bool operator < (const point_t &b) const {
    return k < b.k;
  }
} o, p[N];

int n, number[2], belong[N];
ll answer, temp;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
    p[i].i = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j].i == i) {
        o = p[j];
        break;
      }
    }
    for (int j = 1; j <= n; ++j) {
      p[j].k = p[j].i == i ? 1e9 : atan2l(p[j].y - o.y, p[j].x - o.x);
      if (p[j].k < 0) {
        p[j].k += pi;
      }
      if (p[j].k >= pi) {
        p[j].k -= pi;
      }
    }
    number[0] = number[1] = 0;
    sort(p + 1, p + n + 1);
    for (int j = 1; j < n; ++j) {
      if (p[j].y < o.y || (p[j].y == o.y && p[j].x < o.x)) {
        ++number[belong[j] = 0];
      } else {
        ++number[belong[j] = 1];
      }
    }
    for (int j = 1; j < n; ++j) {
      --number[belong[j]];
      answer += (ll)number[0] * number[1] * (number[0] - 1) * (number[1] - 1) / 4;
      ++number[!belong[j]];
    }
  }
  printf("%lld\n", answer >> 1);
  return 0;
}