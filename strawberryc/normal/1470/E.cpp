#include <bits/stdc++.h>
#define mp std::make_pair

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

typedef long long ll;
typedef std::pair<int, ll> P;

const int N = 3e4 + 5;
const ll INF = 1e18;

int n, c, q, p[N];
ll f[N][5], g[5][N], s[5][N][17];
std::vector<P> orz[5][N];

int jjd(int x, ll y)
{
	int i = 1, cur = c;
	while (i <= n)
	{
		int nxt = i;
		for (int j = 15; j >= 0; j--)
			if (nxt + (1 << j) - 1 <= n &&
				s[cur][nxt][j] < y && y <= s[cur][nxt][j]
					+ g[cur][nxt + (1 << j) - 1])
						y -= s[cur][nxt][j], nxt += 1 << j;
		if (i <= x && x < nxt) return p[x];
		i = nxt;
		for (int j = 0; j < orz[cur][i].size(); j++)
			if (y <= orz[cur][i][j].second)
			{
				if (i <= x && x <= orz[cur][i][j].first)
					return p[i + orz[cur][i][j].first - x];
				int tc = cur; cur -= orz[tc][i][j].first - i;
				i = orz[tc][i][j].first + 1; break;
			}
			else y -= orz[cur][i][j].second;
	}
	return -1;
}

void work()
{
	int x; ll y;
	read(n); read(c); read(q);
	for (int i = 1; i <= n; i++) read(p[i]);
	for (int i = 0; i <= c; i++) f[n + 1][i] = !i;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j <= c; j++) f[i][j] = 0;
		for (int j = i; j <= n && j - i <= c; j++)
			for (int k = j - i; k <= c; k++)
			{
				f[i][k] += f[j + 1][k - j + i];
				if (f[i][k] > INF) f[i][k] = INF;
			}
	}
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= c; j++)
			f[i][j] += f[i][j - 1];
	for (int d = 0; d <= c; d++)
		for (int i = n; i >= 1; i--)
		{
			orz[d][i].clear(); g[d][i] = s[d][i][0] = 0;
			for (int j = i; j <= n && j - i <= d; j++)
				orz[d][i].push_back(mp(j, f[j + 1][d - j + i]));
			std::sort(orz[d][i].begin(), orz[d][i].end(), [&](P x, P y)
				{return p[x.first] < p[y.first];});
			for (int j = 0; j < orz[d][i].size(); j++)
			{
				if (orz[d][i][j].first == i)
					{g[d][i] = orz[d][i][j].second; break;}
				s[d][i][0] += orz[d][i][j].second;
				if (s[d][i][0] > INF) s[d][i][0] = INF;
			}
			for (int j = 0; j < 15; j++)
			{
				s[d][i][j + 1] = s[d][i][j];
				if (i + (1 << j) <= n) s[d][i][j + 1]
					+= s[d][i + (1 << j)][j];
				if (s[d][i][j + 1] > INF) s[d][i][j + 1] = INF;
			}
		}
	while (q--)
	{
		read(x); read(y);
		if (y > f[1][c]) puts("-1");
		else printf("%d\n", jjd(x, y));
	}
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}