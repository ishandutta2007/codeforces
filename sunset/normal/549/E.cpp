#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

struct point_t {
  int x, y;

  point_t(int x = 0, int y = 0): x(x), y(y) {
  }

  point_t operator + (const point_t &b) const {
    return point_t(x + b.x, y + b.y);
  }

  point_t operator - (const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }

  bool operator < (const point_t &b) const {
    return x < b.x || (x == b.x && y < b.y);
  }

  int operator * (const point_t &b) const {
    return x * b.y - y * b.x;
  }

  int operator ^ (const point_t &b) const {
    return x * b.x + y * b.y;
  }
} a[N], b[N], c[N];

int na, nb, nc;

void convex_hull(point_t *a, int na, point_t *b, int &nb) {
  nb = 0;
  for (int iter = 0; iter < 2; ++iter) {
    int old = nb + 1;
    for (int i = 0; i < na; ++i) {
      while (nb > old && (b[nb - 1] - b[nb - 2]) * (a[i] - b[nb - 2]) >= 0) {
        --nb;
      }
      b[nb++] = a[i];
    }
    --nb;
    reverse(a, a + na);
  }
}

bool check(point_t *a, point_t *b, int na, int nb, int i, int j) {
  int min_num = INT_MIN, min_den = 1;
  int p = -1;
  for (int k = i + 1; k < j; ++k) {
    int num = (a[k] - a[j]) ^ (a[k] - a[i]);
    int den = (a[k] - a[i]) * (a[i] - a[j]);
    if ((long long)num * min_den > (long long)den * min_num) {
      min_num = num;
      min_den = den;
      p = k;
    }
  }
  int max_num = INT_MAX, max_den = 1;
  for (int k = (j + 1) % na; k != i; k = (k + 1) % na) {
    int num = (a[k] - a[j]) ^ (a[i] - a[k]);
    int den = (a[i] - a[k]) * (a[i] - a[j]);
    if ((long long)num * max_den < (long long)den * max_num) {
      max_num = num;
      max_den = den;
    }
  }
  bool ok = true;
  for (int k = 0; k < nb; ++k) {
    int num = (b[k] - a[j]) ^ (b[k] - a[i]);
    int den = (b[k] - a[i]) * (a[i] - a[j]);
    if (den > 0) {
      if ((long long)num * max_den < (long long)den * max_num) {
        max_num = num;
        max_den = den;
      }
    } else if (den < 0) {
      if ((long long)num * min_den < (long long)den * min_num) {
        min_num = -num;
        min_den = -den;
      }
    } else if (num <= 0) {
      ok = false;
      break;
    }
    if ((long long)min_num * max_den >= (long long)min_den * max_num) {
      ok = false;
      break;
    }
  }
  if (ok) {
    return true;
  } else if (~p) {
    return check(a, b, na, nb, i, p) || check(a, b, na, nb, p, j);
  } else {
    return false;
  }
}

bool solve(point_t *a, point_t *b, int na, int nb) {
  if (na == 1) {
    return true;
  }
  convex_hull(a, na, c, nc);
  return check(c, b, nc, nb, 0, nc - 1);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &na, &nb);
  for (int i = 0; i < na; ++i) {
    scanf("%d %d", &a[i].x, &a[i].y);
  }
  for (int i = 0; i < nb; ++i) {
    scanf("%d %d", &b[i].x, &b[i].y);
  }
  sort(a, a + na);
  sort(b, b + nb);
  puts(solve(a, b, na, nb) || solve(b, a, nb, na) ? "YES" : "NO");
  return 0;
}