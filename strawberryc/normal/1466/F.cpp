#include <bits/stdc++.h>

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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 5e5 + 5, EI = 1e9 + 7, INF = 0x3f3f3f3f;

int n, m, X[N], Y[N], fa[N], sze[N], res, res2 = 1, mp[N], ans;
bool in[N];

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y, int z)
{
	bool is = x == y;
	x = cx(x); y = cx(y);
	if (x != y) fa[y] = x, sze[x] += sze[y], mp[x] = Min(mp[x], mp[y]);
	if (is) mp[x] = Min(mp[x], z);
}

int main()
{
	int k;
	read(n); read(m); res = m;
	for (int i = 1; i <= m; i++) fa[i] = i, mp[i] = INF;
	for (int i = 1; i <= n; i++)
	{
		read(k);
		if (k == 1) read(X[i]), Y[i] = X[i];
		else read(X[i]), read(Y[i]);
		zm(X[i], Y[i], i);
	}
	for (int i = 1; i <= m; i++) if (fa[i] == i && mp[i] == INF) res--;
	while (res--) res2 = (res2 << 1) % EI;
	for (int i = 1; i <= m; i++) fa[i] = i, mp[i] = INF;
	for (int i = 1; i <= n; i++)
		if (X[i] == Y[i])
		{
			if (mp[cx(X[i])] < INF) continue;
			zm(X[i], Y[i], i); in[i] = 1; ans++;
		}
		else
		{
			if (cx(X[i]) == cx(Y[i])) continue;
			if (mp[cx(X[i])] < INF && mp[cx(Y[i])] < INF) continue;
			zm(X[i], Y[i], i); in[i] = 1; ans++;
		}
	std::cout << res2 << " " << ans << std::endl;
	for (int i = 1; i <= n; i++) if (in[i]) printf("%d ", i);
	return puts(""), 0;
}