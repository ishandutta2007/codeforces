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

const int N = 5e5 + 5, M = 1e6 + 5;

int n, d, delta, tot, q, val[M], A[M], w[N], f[N], r[M];

struct elem {
  int s, a;
} p[N];

struct query {
  int id, t, x;
} que[M];

void change(int x, int v) {
  for (; x <= tot; x += x & -x)
    A[x] += v;
}

int ask(int x) {
  int res = 0;
  for (; x; x -= x & -x)
    res += A[x];
  return res;
}

int main() {
  int m, x, y;
  read(m); read(d);
  while (m--) {
  	read(x); read(y);
  	if (x < d) continue;
  	if (y <= d) {delta++; continue;}
  	p[++n] = (elem) {x, y};
  }
  std::sort(p + 1, p + n + 1, [&](elem u, elem v)
    {return u.s < v.s || (u.s == v.s && u.a < v.a);});
  for (int i = 1; i <= n; i++) val[++tot] = p[i].s, val[++tot] = p[i].a;
  std::sort(val + 1, val + tot + 1);
  tot = std::unique(val + 1, val + tot + 1) - val - 1;
  for (int i = 1; i <= n; i++) {
  	p[i].s = std::lower_bound(val + 1, val + tot + 1, p[i].s) - val;
  	p[i].a = std::lower_bound(val + 1, val + tot + 1, p[i].a) - val;
  	if (p[i].s + 1 < p[i].a)
  	  que[++q] = (query) {-i, p[i].s, p[i].s},
  	  que[++q] = (query) {i, p[i].a - 1, p[i].s};
  }
  std::sort(que + 1, que + q + 1, [&](query u, query v) {return u.t < v.t;});
  for (int i = 1, j = 1; i <= q; i++) {
  	while (j <= n && p[j].s <= que[i].t) change(p[j].a, 1), j++;
  	if (que[i].id < 0) w[-que[i].id] -= ask(que[i].x);
  	else w[que[i].id] += ask(que[i].x);
  }
  for (int i = 1, j = 1; i <= tot; i++) {
  	while (j <= n && p[j].s < i) j++;
  	r[i] = j;
  }
  for (int i = 1; i <= n; i++) {
  	f[i]++;
  	if (p[i].s >= p[i].a) f[i + 1] = Max(f[i + 1], f[i]);
  	else f[r[p[i].a]] = Max(f[r[p[i].a]], f[i] + w[i]),
	  f[i + 1] = Max(f[i + 1], f[i] - 1);
  }
  return std::cout << delta + f[n + 1] << std::endl, 0;
}