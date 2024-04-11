#include <bits/stdc++.h>

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

const int N = 305;

struct point
{
	int x, y;
	
	friend inline point operator - (point a, point b)
	{
		return (point) {b.x - a.x, b.y - a.y};
	}
	
	friend inline ll operator * (point a, point b)
	{
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}
	
	inline double theta()
	{
		return atan2(y, x);
	}
} a[N];

int n, I, pt[N][N], tot, p[N], cnt[N][N], pts[N << 1];
bool vis[N];
ll ans;

inline bool comp(int x, int y)
{
	return (a[I] - a[x]).theta() < (a[I] - a[y]).theta();
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
	for (I = 1; I <= n; I++)
	{
		for (int i = 1; i < n; i++)
			pt[I][i] = i < I ? i : i + 1;
		std::sort(pt[I] + 1, pt[I] + n, comp);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		tot = 0;
		for (int j = 1; j < n; j++)
			if (a[pt[i][j]].y > a[i].y || (a[pt[i][j]].y == a[i].y
				&& a[pt[i][j]].x > a[i].x)) vis[p[++tot] = pt[i][j]] = 1;
		for (int j = 1; j <= tot; j++)
		{
			int u = p[j], kt = n - 1 << 1, c = 0;
			for (int k = 1; k < n; k++)
				pts[k] = pts[k + n - 1] = pt[u][k];
			for (int k = (n - 1 << 1); k >= 1; k--)
			{
				if (vis[pts[k]] && (a[i] - a[pts[k]]) * (a[i] - a[u]) > 0) c++;
				while (kt == k + n || (kt > k &&
				(a[u] - a[pts[k]]) * (a[u] - a[pts[kt]]) < 0))
				{
					if (vis[pts[kt]] && (a[i] - a[pts[kt]]) * (a[i] - a[u]) > 0) c--;
					kt--;
				}
				if (k < n && vis[pts[k]] && (a[i] - a[pts[k]]) * (a[i] - a[u]) < 0)
					cnt[u][pts[k]] = c;
			}
		}
		for (int j = 1; j <= tot; j++)
		{
			int u = p[j], kt = 1, c = 0;
			for (int k = 1; k < n; k++)
				pts[k] = pts[k + n - 1] = pt[u][k];
			for (int k = 1; k <= (n - 1 << 1); k++)
			{
				if (vis[pts[k]] && (a[i] - a[pts[k]]) * (a[i] - a[u]) < 0) c++;
				while (kt == k - n || (kt < k &&
				(a[u] - a[pts[k]]) * (a[u] - a[pts[kt]]) > 0))
				{
					if (vis[pts[kt]] && (a[i] - a[pts[kt]]) * (a[i] - a[u]) < 0) c--;
					kt++;
				}
				if (k >= n && vis[pts[k]] && (a[i] - a[pts[k]]) * (a[i] - a[u]) > 0)
					cnt[u][pts[k]] = c;
			}
		}
		for (int j = 1; j <= tot; j++)
			for (int k = j + 1; k <= tot; k++)
				ans += cnt[p[j]][p[k]] * cnt[p[k]][p[j]]; 
	}
	return std::cout << ans << std::endl, 0;
}