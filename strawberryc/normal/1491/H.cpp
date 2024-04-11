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

int n, q, a[N], S, bl[N], br[N], tot, add[N], mx[N], out[N], in[N];

void pushdown(int b) {
  mx[b] = 0;
  for (int i = bl[b]; i <= br[b]; i++) {
    mx[b] = Max(mx[b], a[i] = Max(1, a[i] - add[b]));
    out[i] = a[i] < bl[b] ? a[i] : out[a[i]];
  }
  add[b] = 0;
}

void change(int l, int r, int x) {
  int il = in[l], ir = in[r];
  if (il == ir) {
  	for (int i = l; i <= r; i++) a[i] -= x;
  	return pushdown(il);
  }
  for (int i = il + 1; i < ir; i++) {
  	add[i] = Min(n, add[i] + x);
  	if (mx[i] >= bl[i]) pushdown(i);
  	else mx[i] = Max(1, mx[i] - x);
  }
  for (int i = l; i <= br[il]; i++) a[i] -= x;
  for (int i = bl[ir]; i <= r; i++) a[i] -= x;
  pushdown(il); pushdown(ir);
}

int _out(int u) {
  int b = in[u];
  return mx[b] >= bl[b] ? out[u] : Max(1, a[u] - add[b]);
}

int lca(int u, int v) {
  if (u == 1 || v == 1) return 1;
  if (u < v) std::swap(u, v);
  int ou = _out(u), ov = _out(v);
  if (in[u] == in[v]) {
  	if (ou == ov) {
  	  while (u != v) {
  	  	if (u < v) std::swap(u, v);
  	  	u = Max(1, a[u] - add[in[u]]);
	  }
	  return u;
	}
	else return lca(ou, ov);
  }
  else return lca(ou, v);
}

int main() {
  int op, l, r, x;
  read(n); read(q); S = sqrt(n - 1);
  for (int i = 2; i <= n; i++) read(a[i]), in[i] = (i - 2) / S + 1;
  for (int i = 2; i <= n; i += S)
    bl[++tot] = i, br[tot] = Min(i + S - 1, n);
  for (int i = 1; i <= tot; i++) pushdown(i);
  while (q--) {
  	read(op); read(l); read(r);
  	if (op == 1) read(x), change(l, r, x);
  	else printf("%d\n", lca(l, r));
  }
  return 0;
}