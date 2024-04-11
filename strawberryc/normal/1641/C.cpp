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

const int N = 2e5 + 5;

int n, q, typ[N], L[N], R[N], X[N], ans[N], A[N], res[N], p[N], xp[N], tot, tmp[N];
std::set<int> cur;

void clean(int x) {
  for (; x <= n; x += x & -x)
    A[x] = 0;
}

void change(int x, int v) {
  for (; x <= n; x += x & -x)
    A[x] += v;
}

int ask(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += A[x];
  return res;
}

void dac(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1, ql = l;
  dac(l, mid); dac(mid + 1, r);
  tot = 0;
  for (int i = mid + 1; i <= r; i++) {
  	while (ql <= mid && L[p[ql]] >= L[p[i]]) {
  	  if (!typ[p[ql]] && X[p[ql]]) change(R[p[ql]], 1);
  	  xp[++tot] = p[ql]; ql++;
	}
  	if (typ[p[i]]) res[p[i]] += ask(R[p[i]]);
  	xp[++tot] = p[i];
  }
  while (ql <= mid) xp[++tot] = p[ql], ql++;
  for (int i = l; i <= mid; i++) if (!typ[p[i]] && X[p[i]]) clean(R[p[i]]);
  for (int i = 1; i <= tot; i++) p[l + i - 1] = xp[i];
}

int main() {
  memset(ans, -1, sizeof(ans));
  read(n); read(q);
  for (int i = 1; i <= n; i++) cur.insert(i);
  for (int i = 1; i <= q; i++) {
  	read(typ[i]);
  	if (!typ[i]) {
  	  read(L[i]); read(R[i]); read(X[i]);
  	  if (!X[i]) for (std::set<int>::iterator it = cur.lower_bound(L[i]);
		it != cur.end() && *it <= R[i];) {
		  std::set<int>::iterator ti = it; ti++;
		  cur.erase(it); it = ti;
		}
	}
	else {
	  read(X[i]);
	  std::set<int>::iterator it, ti;
	  if ((it = cur.find(X[i])) == cur.end()) ans[i] = 0;
	  else {
	  	ti = it;
	  	L[i] = it == cur.begin() ? 1 : (*--ti) + 1; it++;
	  	R[i] = it == cur.end() ? n : (*it) - 1;
	  }
	}
  }
  for (int i = 1; i <= q; i++) p[i] = i;
  dac(1, q);
  for (int i = 1; i <= q; i++) if (typ[i]) {
  	if (ans[i] == 0) puts("NO");
  	else if (res[i]) puts("YES");
  	else puts("N/A");
  }
  return 0;
}