#include <bits/stdc++.h>
using namespace std;

const int N = 100105, V = 100100, M = 10000005, BSE = 131, P = 1000000007;

#define id(l, r) (((l) + (r)) | ((l) < (r)))

int n, m, s, t, tot, ls[M], rs[M], h[M], pw[N], pw2[N], nxt[2 * N], fst[N], to[2 * N], w[2 * N], dis[N], pre[N], st[N], rt, f[M];
bool vis[N];

void adde(int u, int v, int x)
{
	static int etot = 1;
	nxt[++etot] = fst[u]; fst[u] = etot; to[etot] = v; w[etot] = x;
	nxt[++etot] = fst[v]; fst[v] = etot; to[etot] = u; w[etot] = x;
}

void build(int l, int r)
{
	f[id(l, r)] = l;
	if (l == r) return;
	int mid = l + r >> 1;
	ls[id(l, r)] = id(l, mid);
	rs[id(l, r)] = id(mid + 1, r);
	build(l, mid); build(mid + 1, r);
}

void upd(int x, int l, int r, int mid)
{
	f[x] = !f[ls[x]] ? f[rs[x]] : f[ls[x]];
	h[x] = (h[ls[x]] + 1ll * h[rs[x]] * pw[mid - l + 1]) % P;
}

void set0(int &x, int y, int l, int r, int ql, int qr)
{
	if (l >= ql && r <= qr) { x = id(l, r); return; }
	x = ++tot;
	ls[x] = ls[y], rs[x] = rs[y];
	int mid = l + r >> 1;
	if (ql <= mid) set0(ls[x], ls[y], l, mid, ql, qr);
	if (qr > mid) set0(rs[x], rs[y], mid + 1, r, ql, qr);
	upd(x, l, r, mid);
}

void set1(int &x, int y, int l, int r, int p)
{
	x = ++tot;
	ls[x] = ls[y], rs[x] = rs[y];
	if (l == r)
	{
		f[x] = 0;
		h[x] = 1;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) set1(ls[x], ls[y], l, mid, p);
	else set1(rs[x], rs[y], mid + 1, r, p);
	upd(x, l, r, mid);
}

int query(int x, int l, int r, int ql, int qr)
{
	if (l >= ql && r <= qr) return f[x];
	int mid = l + r >> 1;
	if (qr <= mid) return query(ls[x], l, mid, ql, qr);
	else if (ql > mid) return query(rs[x], mid + 1, r, ql, qr);
	else
	{
		int v = query(ls[x], l, mid, ql, qr);
		if (v) return v;
		return query(rs[x], mid + 1, r, ql, qr);
	}
}

int add(int x, int w)
{
	int y = query(x, 1, V, w, V), ret, tmp;
	if (y > w) set0(tmp, x, 1, V, w, y - 1);
	else tmp = x;
	set1(ret, tmp, 1, V, y);
	return ret;
}

bool cmp(int x, int y, int l, int r)
{
	if (l == r) return h[x] < h[y];
	int mid = l + r >> 1;
	if (h[rs[x]] == h[rs[y]]) return cmp(ls[x], ls[y], l, mid);
	else return cmp(rs[x], rs[y], mid + 1, r);
}

struct node
{
	int h, d;
};
bool operator<(const node &a, const node &b)
{
	return cmp(b.d, a.d, 1, V);
}
priority_queue<node> q;

int main()
{
	scanf("%d%d", &n, &m);
	build(1, V);
	tot = id(V, V) + 1;
	pw[0] = pw2[0] = 1;
	for (int i = 1; i <= V; i++)
	{
		pw2[i] = pw2[i - 1] * 2 % P;
		pw[i] = 1ll * BSE * pw[i - 1] % P;
	}
	for (int i = 0, u, v, w; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, ++w);
	}
	scanf("%d%d", &s, &t);
	dis[s] = id(1, V);
	vis[s] = true;
	q.push((node){s, dis[s]});
	while (!q.empty())
	{
		node t = q.top();
		q.pop();
		if (dis[t.h] != t.d) continue;
		for (int i = fst[t.h]; i; i = nxt[i])
		{
			int e = add(t.d, w[i]);
			if (!vis[to[i]] || cmp(e, dis[to[i]], 1, V))
			{
				vis[to[i]] = true;
				dis[to[i]] = e;
				pre[to[i]] = i;
				q.push((node){to[i], e});
			}
		}
	}
	if (!vis[t]) { puts("-1"); return 0; }
	int ans = 0, top = 0;
	for (int i = t; i != s; i = to[pre[i] ^ 1])
	{
		st[++top] = i;
		ans = (ans + pw2[w[pre[i]] - 1]) % P;
	}
	st[++top] = s;
	printf("%d\n%d\n", ans, top);
	for (int i = top; i; i--) printf("%d%c", st[i], " \n"[i == 1]);
	return 0;
}