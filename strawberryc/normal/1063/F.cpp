#include <bits/stdc++.h>

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 5e5 + 7, LogN = 21, L = 2e7 + 5;

int n, f[N], sa[N], rank[N], height[N], w[N], rt[N], ToT, RMQ[N][LogN], Log[N], ans;
char s[N];

void init()
{
	int *x = rank, *y = height, m = 26;
	for (int i = 1; i <= n; i++) w[x[i] = s[i] - 'a' + 1]++;
	for (int i = 2; i <= m; i++) w[i] += w[i - 1];
	for (int i = 1; i <= n; i++) sa[w[x[i]]--] = i;
	for (int k = 1; k < n; k <<= 1, std::swap(x, y))
	{
		int tt = 0;
		for (int i = n - k + 1; i <= n; i++) y[++tt] = i;
		for (int i = 1; i <= n; i++) if (sa[i] > k) y[++tt] = sa[i] - k;
		memset(w, 0, sizeof(w));
		for (int i = 1; i <= n; i++) w[x[i]]++;
		for (int i = 2; i <= m; i++) w[i] += w[i - 1];
		for (int i = n; i >= 1; i--) sa[w[x[y[i]]]--] = y[i];
		m = 0;
		for (int i = 1; i <= n; i++)
		{
			int u = sa[i], v = sa[i - 1];
			y[u] = x[u] != x[v] || x[u + k] != x[v + k] ? ++m : m;
		}
		if (m == n) break;
	}
	for (int i = 1; i <= n; i++) rank[sa[i]] = i;
	for (int i = 1, k = 0; i <= n; i++)
	{
		if (k) k--;
		while (s[i + k] == s[sa[rank[i] - 1] + k]) k++;
		height[rank[i]] = k;
	}
	Log[0] = -1;
	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int i = 2; i <= n; i++) RMQ[i][0] = height[i];
	for (int j = 1; j <= 18; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			RMQ[i][j] = Min(RMQ[i][j - 1], RMQ[i + (1 << j - 1)][j - 1]);
}

int qmin(int l, int r)
{
	int k = Log[r - l + 1];
	return Min(RMQ[l][k], RMQ[r - (1 << k) + 1][k]);
}

struct node
{
	int lc, rc, mx;
} T[L];

void change(int y, int &x, int l, int r, int pos, int val)
{
	T[x = ++ToT] = T[y]; T[x].mx = Max(T[x].mx, val);
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) change(T[y].lc, T[x].lc, l, mid, pos, val);
	else change(T[y].rc, T[x].rc, mid + 1, r, pos, val);
}

int ask(int x, int l, int r, int s, int e)
{
	if (e < l || s > r) return 0;
	if (s <= l && r <= e) return T[x].mx;
	int mid = l + r >> 1;
	return Max(ask(T[x].lc, l, mid, s, e), ask(T[x].rc, mid + 1, r, s, e));
}

int bin1(int pos, int len)
{
	int l = 1, r = pos - 1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (qmin(mid + 1, pos) >= len) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

int bin2(int pos, int len)
{
	int l = pos + 1, r = n;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (qmin(pos + 1, mid) >= len) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}

bool check(int pos, int len)
{
	int k = rank[pos], h = rank[pos + 1];
	return ask(rt[pos + len], 1, n, bin1(k, len - 1), bin2(k, len - 1)) >= len - 1
		|| ask(rt[pos + len], 1, n, bin1(h, len - 1), bin2(h, len - 1)) >= len - 1;
}

int main()
{
	std::cin >> n;
	scanf("%s", s + 1);
	init();
	change(rt[n + 1], rt[n], 1, n, rank[n], ans = f[n] = 1);
	for (int i = n - 1; i >= 1; i--)
	{
		f[i] = f[i + 1] + 1;
		while (!check(i, f[i])) f[i]--;
		ans = Max(ans, f[i]);
		change(rt[i + 1], rt[i], 1, n, rank[i], f[i]);
	}
	return std::cout << ans << std::endl, 0;
}