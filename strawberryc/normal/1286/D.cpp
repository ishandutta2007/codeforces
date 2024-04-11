#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 1e5 + 5, M = N << 1, L = M << 2, rqy = 998244353, I = 828542813;

int n, X[N], V[N], P[N], m, ans;

struct elem
{
	int x, y, i, ty;
} a[M];

inline bool comp(elem a, elem b)
{
	return 1ll * a.x * b.y < 1ll * a.y * b.x;
}

struct matrix
{
	int a[2][2];
	
	friend inline matrix operator * (matrix a, matrix b)
	{
		matrix res;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
			res.a[i][j] = (1ll * a.a[i][0] * b.a[0][j] +
				1ll * a.a[i][1] * b.a[1][j]) % rqy;
		return res;
	}
} T[L];

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % rqy;
		a = 1ll * a * a % rqy;
		b >>= 1;
	}
	return res;
}

void build(int l, int r, int p)
{
	if (l == r)
	{
		T[p].a[0][0] = T[p].a[0][1] = 1ll * (rqy + 1 - P[l + 1]) % rqy;
		T[p].a[1][0] = T[p].a[1][1] = P[l + 1];
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	T[p] = T[p3] * T[p2];
}

void clear(int l, int r, int pos, int x, int y, int p)
{
	if (l == r) return (void) (T[p].a[x][y] = 0);
	int mid = l + r >> 1;
	if (pos <= mid) clear(l, mid, pos, x, y, p2);
	else clear(mid + 1, r, pos, x, y, p3);
	T[p] = T[p3] * T[p2];
}

int calc() {return (1ll * P[1] * (T[1].a[0][1] + T[1].a[1][1])
	+ 1ll * (rqy + 1 - P[1]) * (T[1].a[0][0] + T[1].a[1][0])) % rqy;}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(X[i]), read(V[i]), read(P[i]),
		P[i] = 1ll * P[i] * I % rqy;
	for (int i = 1; i < n; i++)
	{
		a[++m] = (elem) {X[i + 1] - X[i], V[i] + V[i + 1], i, 0};
		if (V[i] < V[i + 1]) a[++m] = (elem) {X[i + 1] - X[i], V[i + 1] - V[i], i, 1};
		if (V[i] > V[i + 1]) a[++m] = (elem) {X[i + 1] - X[i], V[i] - V[i + 1], i, 2};
	}
	std::sort(a + 1, a + m + 1, comp);
	if (n > 1) build(1, n - 1, 1);
	for (int i = 1, pb = 1; i <= m; i++)
	{
		int val = 1ll * a[i].x * qpow(a[i].y, rqy - 2) % rqy, npb;
		if (a[i].ty == 0) clear(1, n - 1, a[i].i, 0, 1, 1);
		else if (a[i].ty == 1) clear(1, n - 1, a[i].i, 0, 0, 1);
		else clear(1, n - 1, a[i].i, 1, 1, 1);
		ans = (1ll * val * (pb - (npb = calc()) + rqy) + ans) % rqy;
		pb = npb;
	}
	return std::cout << ans << std::endl, 0;
}