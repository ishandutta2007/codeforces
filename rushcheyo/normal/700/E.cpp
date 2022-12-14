#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int n, tot, lst, fa[N], ch[N][26], dep[N], cnt[N], q[N], pos[N], sz, root[N], ls[N * 20], rs[N * 20], f[N], top[N], ans;
char s[N];

void extend(int i) {
	int c = s[i] - 'a', np = ++tot, p = lst;
	dep[np] = dep[p] + 1;
	pos[np] = i;
	for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
	if (!p) fa[np] = 1;
	else {
		int q = ch[p][c];
		if (dep[q] == dep[p] + 1) fa[np] = q;
		else {
			int nq = ++tot;
			pos[nq] = i;
			dep[nq] = dep[p] + 1;
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			for (int j = 0; j < 26; j++) ch[nq][j] = ch[q][j];
			for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
		}
	}
	lst = np;
}

int merge(int p, int q) {
	if (!p || !q) return p ^ q;
	int r = ++sz;
	ls[r] = merge(ls[p], ls[q]);
	rs[r] = merge(rs[p], rs[q]);
	return r;
}

void update(int &x, int l, int r, int p) {
	if (!x) x = ++sz;
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) update(ls[x], l, mid, p);
	else update(rs[x], mid + 1, r, p);
}

bool query(int x, int l, int r, int ql, int qr) {
	if (!x) return false;
	if (l >= ql && r <= qr) return true;
	int mid = l + r >> 1;
	bool ret = false;
	if (ql <= mid) ret = query(ls[x], l, mid, ql, qr);
	if (qr > mid) ret = ret | query(rs[x], mid + 1, r, ql, qr);
	return ret;
}

int main() {
	scanf("%d%s", &n, s + 1);
	tot = lst = 1;
	for (int i = 1; i <= n; i++)
		extend(i);
	for (int i = 1; i <= tot; i++) cnt[dep[i]]++;
	for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	for (int i = tot; i; i--) q[cnt[dep[i]]--] = i;
	for (int i = tot; i; i--) {
		if (pos[q[i]])
			update(root[q[i]], 1, n, pos[q[i]]);
		if (fa[q[i]] > 1)
			root[fa[q[i]]] = merge(root[fa[q[i]]], root[q[i]]);
	}
	for (int i = 1; i <= tot; i++) {
		if (fa[q[i]] <= 1) f[q[i]] = 1, top[q[i]] = q[i];
		else if (query(root[top[fa[q[i]]]], 1, n, pos[q[i]] - (dep[q[i]] - dep[top[fa[q[i]]]]), pos[q[i]] - 1))
			f[q[i]] = f[fa[q[i]]] + 1, top[q[i]] = q[i];
		else
			f[q[i]] = f[fa[q[i]]], top[q[i]] = top[fa[q[i]]];
		ans = max(ans, f[q[i]]);
	}
	printf("%d\n", ans);
	return 0;
}