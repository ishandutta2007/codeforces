#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

typedef long long ll;

const int N = 2e5 + 5, M = N << 2, L = 1e6 + 5;

int n, q, p[N], ip[N], top, stk[N], T[M], add[M], sum[M], lt[N], pos[N];
std::vector<int> divis[N];
ll addx[M], sumx[M], ans[L];

void down(int l, int r, int mid, int p) {
  add[p2] += add[p]; sum[p2] += add[p] * (mid - l + 1);
  add[p3] += add[p]; sum[p3] += add[p] * (r - mid);
  addx[p2] += addx[p]; sumx[p2] += addx[p] * (mid - l + 1);
  addx[p3] += addx[p]; sumx[p3] += addx[p] * (r - mid);
  add[p] = 0; addx[p] = 0;
}

void change(int l, int r, int s, int e, int v, int t, int p) {
  if (e < l || s > r) return;
  if (s <= l && r <= e) {
  	add[p] += v; sum[p] += (r - l + 1) * v;
  	addx[p] += -v * t; sumx[p] += -1ll * v * t * (r - l + 1);
  	return;
  }
  int mid = l + r >> 1; down(l, r, mid, p);
  change(l, mid, s, e, v, t, p2); change(mid + 1, r, s, e, v, t, p3);
  sum[p] = sum[p2] + sum[p3]; sumx[p] = sumx[p2] + sumx[p3];
}

ll ask(int l, int r, int s, int e, int t, int p) {
  if (e < l || s > r) return 0;
  if (s <= l && r <= e) return 1ll * sum[p] * t + sumx[p];
  int mid = l + r >> 1; down(l, r, mid, p);
  return ask(l, mid, s, e, t, p2) + ask(mid + 1, r, s, e, t, p3);
}

struct query {
  int id, l, r;
} a[L];

int main() {
  read(n); read(q);
  for (int i = 1; i <= n; i++) read(p[i]), ip[p[i]] = i;
  for (int i = 1; i <= q; i++) a[i].id = i, read(a[i].l), read(a[i].r);
  for (int i = 1; i * (i + 1) <= n; i++)
    for (int j = i * (i + 1); j <= n; j += i)
      divis[j].push_back(i);
  std::sort(a + 1, a + q + 1, [&](query u, query v) {return u.r < v.r;});
  stk[top = 0] = 0;
  for (int i = 1, ql = 1; i <= n; i++) {
  	while (top && p[stk[top]] < p[i]) {
  	  if (lt[top] > stk[top - 1])
		change(1, n, stk[top - 1] + 1, lt[top], -1, i - 1, 1);
  	  pos[p[stk[top--]]] = 0;
	}
	stk[++top] = i; lt[top] = stk[top - 1]; pos[p[i]] = top;
	for (int j = 0; j < divis[p[i]].size(); j++) {
	  int x = ip[divis[p[i]][j]], y = ip[p[i] / divis[p[i]][j]];
	  if (x > stk[top - 1] && x <= i && y > stk[top - 1] && y <= i)
	    lt[top] = Max(lt[top], Min(x, y));
	}
	if (lt[top] > stk[top - 1]) change(1, n, stk[top - 1] + 1, lt[top], 1, i - 1, 1);
	for (int j = p[i] * 2; j <= n; j += p[i])
	  if (1ll * p[i] * p[i] != 1ll * j && pos[j]) {
	  	int id = pos[j], x = ip[j / p[i]];
	  	int nlt;
	  	if (stk[id] <= x && x <= i) nlt = stk[id];
	  	else if (stk[id - 1] < x && x < stk[id]) nlt = x;
	  	else nlt = stk[id - 1];
	  	if (nlt > lt[id]) change(1, n, lt[id] + 1, nlt, 1, i - 1, 1), lt[id] = nlt;
	  }
  	while (ql <= q && a[ql].r == i) ans[a[ql].id] = ask(1, n, a[ql].l, i, i, 1), ql++;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
  return 0;
}