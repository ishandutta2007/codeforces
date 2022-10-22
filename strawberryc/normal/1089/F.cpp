#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int n, S, m, a[N], b[N], sts[N], tot, X[N], Y[N], dis[N], pre[N], eg[N],
Tot, ans, ansa[N], ansb[N];
bool vis[N];

struct node
{
	int u, dis;
	
	friend inline bool operator < (node a, node b)
	{
		return a.dis > b.dis;
	}
};

struct xfrac
{
	int cnt, fra;
} rp[N];

inline bool comp(xfrac a, xfrac b)
{
	return a.fra < b.fra;
}

std::priority_queue<node> pq;

int main()
{
	int i, j;
	std::cin >> n; S = sqrt(n);
	For (i, 1, S)
	{
		if (n % i) continue;
		a[++m] = i;
		if (i * i != n) a[++m] = n / i;
	}
	if (m == 2) return puts("NO"), 0;
	m -= 2;
	For (i, 1, m) a[i] = a[i + 2];
	For (i, 1, m) b[i] = n / a[i];
	std::sort(b + 1, b + m + 1);
	std::sort(a + 1, a + m + 1);
	memset(sts, INF, sizeof(sts));
	For (i, 1, m) sts[b[i] % b[1]] = Min(sts[b[i] % b[1]], b[i]);
	For (i, 0, b[1] - 1) if (sts[i] != INF)
		X[++tot] = i, Y[tot] = sts[i];
	memset(dis, INF, sizeof(dis));
	pq.push((node) {0, dis[0] = 0});
	while (!pq.empty())
	{
		node x = pq.top(); pq.pop();
		if (vis[x.u]) continue; vis[x.u] = 1;
		For (i, 1, tot)
		{
			int v = (x.u + X[i]) % b[1];
			if (dis[x.u] + Y[i] < dis[v])
				pq.push((node) {v, dis[v] = dis[x.u] + Y[i]}),
				pre[v] = x.u, eg[v] = n / Y[i];
		}
	}
	int u = (n - 1) % b[1];
	if (dis[u] >= n) return puts("NO"), 0;
	while (u) rp[++Tot] = (xfrac) {1, eg[u]}, u = pre[u];
	rp[++Tot] = (xfrac) {(n - dis[(n - 1) % b[1]]) / b[1], n / b[1]};
	std::sort(rp + 1, rp + Tot + 1, comp);
	i = 1;
	while (i <= Tot)
	{
		j = i; int cnt = 0;
		while (j <= Tot && rp[j].fra == rp[i].fra)
			cnt += rp[j].cnt, j++;
		if (cnt) ansa[++ans] = cnt, ansb[ans] = rp[i].fra;
		i = j;
	}
	puts("YES");
	std::cout << ans << std::endl;
	For (i, 1, ans) printf("%d %d\n", ansa[i], ansb[i]);
	return 0;
}