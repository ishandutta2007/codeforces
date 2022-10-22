#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5;

int n, nx = 1, ny = 1, ans, z1, z2;

struct elem {
  int x, y, c;
} a[N], b[N];

bool calc(int qx, int p, int q, int r) {
  int cnt1 = 0, c2 = 0, c3 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
  for (int i = 1; i <= n; i++)
    if (a[i].x <= qx && a[i].c == p) cnt1++;
    else if (a[i].x > qx && a[i].c == q) c2++;
    else if (a[i].x > qx && a[i].c == r) c3++;
  for (int i = 1; i < n; i++) {
  	if (b[i].x > qx) {
  	  if (b[i].c == q) cnt2++;
	  else if (b[i].c == r) cnt3++;
    }
  	if (b[i].y == b[i + 1].y) continue;
  	ans = Max(ans, Min(cnt2, c3 - cnt3));
  	ans = Max(ans, Min(cnt3, c2 - cnt2));
  }
  cnt2 = cnt3 = 0;
  for (int i = 1; i < n; i++) {
  	if (a[i].x > qx) {
  	  if (a[i].c == q) cnt2++;
	  else if (a[i].c == r) cnt3++;
    }
  	if (a[i].x == a[i + 1].x) continue;
  	ans = Max(ans, Min(cnt2, c3 - cnt3));
  	ans = Max(ans, Min(cnt3, c2 - cnt2));
  }
  return z1 = cnt1, z2 = ans, cnt1 > ans;
}

void solve(int P, int Q, int R) {
  int l = 1, r = nx;
  while (l <= r) {
  	int mid = l + r >> 1;
  	if (calc(mid, P, Q, R)) r = mid - 1;
  	else l = mid + 1;
  }
  if (l <= nx) calc(l, P, Q, R), ans = Max(ans, z2);
  if (l > 1) calc(l - 1, P, Q, R), ans = Max(ans, z1);
}

void jiejuediao() {
 solve(1, 2, 3); solve(2, 1, 3); solve(3, 1, 2);
}

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y), read(a[i].c);
  std::sort(a + 1, a + n + 1, [&](elem u, elem v) {return u.x < v.x;});
  for (int i = 1; i <= n; i++)
    a[i].x = i < n && a[i].x < a[i + 1].x ? nx++ : nx;
  std::sort(a + 1, a + n + 1, [&](elem u, elem v) {return u.y < v.y;});
  for (int i = 1; i <= n; i++)
    a[i].y = i < n && a[i].y < a[i + 1].y ? ny++ : ny, b[i] = a[i];
  std::sort(a + 1, a + n + 1, [&](elem u, elem v) {return u.x < v.x;});
  jiejuediao();
  for (int i = 1; i <= n; i++) a[i].x = nx - a[i].x + 1, b[i].x = nx - b[i].x + 1;
  jiejuediao();
  std::swap(nx, ny);
  for (int i = 1; i <= n; i++) std::swap(a[i], b[i]),
    std::swap(a[i].x, a[i].y), std::swap(b[i].x, b[i].y);
  jiejuediao();
  for (int i = 1; i <= n; i++) a[i].x = nx - a[i].x + 1, b[i].x = nx - b[i].x + 1;
  jiejuediao();
  return std::cout << ans * 3 << std::endl, 0;
}