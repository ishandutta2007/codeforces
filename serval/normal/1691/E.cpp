#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 2e5 + 5;
const int C = N << 1;

int n;
int c[N], l[N], r[N];
int v[C], cnt;
int f[N], rr[2][N];

vector <int> seg[C], rem[2][C];
set <int> active[2];

int ans;

int getf(int u)
{
	return f[u] ? f[u] = getf(f[u]) : u;
}

int curT;

void merge(int x, int y)
{
	if (getf(x) == getf(y))
		return;
	x = getf(x);
	y = getf(y);
	f[x] = y;
	int lasr[2] = {rr[0][y], rr[1][y]};
	rr[0][y] = max(rr[0][x], rr[0][y]);
	rr[1][y] = max(rr[1][x], rr[1][y]);
	if (lasr[0] < rr[0][y])
		rem[0][rr[0][y]].emplace_back(y);
	if (lasr[1] < rr[1][y])
		rem[1][rr[1][y]].emplace_back(y);
}

void upd(int y)
{
	if (curT <= rr[0][y])
		active[0].insert(y);
	if (curT <= rr[1][y])
		active[1].insert(y);
}

void solve()
{
	scanf("%d", &n);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &c[i], &l[i], &r[i]);
		v[++cnt] = l[i];
		v[++cnt] = r[i];
	}
	sort(v + 1, v + cnt + 1);
	for (int i = 1; i <= cnt; i++)
	{
		seg[i].clear();
		rem[0][i].clear();
		rem[1][i].clear();
	}
	active[0].clear();
	active[1].clear();
	for (int i = 1; i <= n; i++)
	{
		l[i] = lower_bound(v + 1, v + cnt + 1, l[i]) - v;
		r[i] = lower_bound(v + 1, v + cnt + 1, r[i]) - v;
		seg[l[i]].emplace_back(i);
		rem[c[i]][r[i]].emplace_back(i);
		f[i] = 0;
		rr[0][i] = rr[1][i] = 0;
		rr[c[i]][i] = r[i];
	}
	for (int i = 1; i <= cnt; i++)
	{
		curT = i;
		for (auto j : seg[i])
		{
			int curc = c[j];
			for (auto k : active[curc ^ 1])
				merge(k, j);
			active[curc ^ 1].clear();
			upd(getf(j));
		}
		for (auto j : rem[0][i])
			if (rr[0][j] == i)
				active[0].erase(j);
		for (auto j : rem[1][i])
			if (rr[1][j] == i)
				active[1].erase(j);
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (getf(i) == i)
			ans++;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}