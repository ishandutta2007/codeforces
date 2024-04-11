#include <bits/stdc++.h>

// 0830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, LogN = 20;

int n, q, k, l, a[N], b[N], sa[N], rank[N], height[N], Log[N], RMQ[N][LogN],
w[N], u[N], v[N], cnt[N], val[N], top;
char s[N];
bool vis[N];

void init()
{
	int m = 26, *x = rank, *y = height;
	for (int i = 1; i <= n; i++) w[x[i] = s[i] - 'a' + 1]++;
	for (int i = 2; i <= m; i++) w[i] += w[i - 1];
	for (int i = 1; i <= n; i++) sa[w[x[i]]--] = i;
	for (int k = 1; k < n; k <<= 1, Swap(x, y))
	{
		int tt = 0;
		for (int i = n - k + 1; i <= n; i++) y[++tt] = i;
		for (int i = 1; i <= n; i++)
			if (sa[i] > k) y[++tt] = sa[i] - k;
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
		for (int i = 2; i + (1 << j) - 1 <= n; i++)
			RMQ[i][j] = Min(RMQ[i][j - 1], RMQ[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r)
{
	int k = Log[r - l + 1];
	return Min(RMQ[l][k], RMQ[r - (1 << k) + 1][k]);
}

ll calc(int n, int m, int *a, int *b)
{
	for (int i = 1; i <= n; i++) u[i] = rank[a[i]];
	for (int i = 1; i <= m; i++) v[i] = rank[b[i]] + 1;
	std::sort(u + 1, u + n + 1);
	std::sort(v + 1, v + m + 1);
	top = 0; ll res = 0, ans = 0;
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		int np = 0;
		while (top && query(u[i - 1] + 1, u[i]) <= val[top])
			res -= 1ll * cnt[top] * val[top], np += cnt[top--];
		if (np) cnt[++top] = np, res += 1ll * np *
			(val[top] = query(u[i - 1] + 1, u[i]));
		while (p <= m && v[p] <= u[i])
			cnt[++top] = 1, res += (val[top] = query(v[p], u[i])), p++;
		ans += res;
	}
	return ans;
}

int main()
{
	n = read(); q = read();
	scanf("%s", s + 1);
	init();
	while (q--)
	{
		k = read(); l = read();
		for (int i = 1; i <= k; i++) a[i] = read();
		for (int i = 1; i <= l; i++) b[i] = read();
		for (int i = 1; i <= k; i++) vis[a[i]] = 1;
		ll res = 0;
		for (int i = 1; i <= l; i++)
			if (vis[b[i]]) res += n - b[i] + 1;
		for (int i = 1; i <= k; i++) vis[a[i]] = 0;
		printf("%lld\n", res + calc(k, l, a, b) + calc(l, k, b, a));
	}
	return 0;
}