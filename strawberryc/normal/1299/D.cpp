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

const int N = 1e5 + 5, M = N << 1, E = 380, rqy = 1e9 + 7;

int n, m, ecnt, nxt[M], adj[N], go[M], val[M], tot, a[E][5], tmp[5], tr[E][32],
tx[E][E], cn, ut[N], fa[N], dep[N], dis[N], f[N][E], v1[N], ans;
bool vis[N];

std::vector<int> v2[N];

std::map<std::vector<int>, int> orz;

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

void D(int dep)
{
	if (dep == 5)
	{
		for (int i = 0; i < 5; i++)
			for (int j = i + 1; j < 5; j++)
				if (tmp[i] != -1 && tmp[j] != -1 && ((tmp[j] >> i) & 1))
					return;
		std::vector<int> t;
		for (int i = 0; i < 5; i++) t.push_back(tmp[i]);
		orz[t] = ++tot;
		for (int i = 0; i < 5; i++) a[tot][i] = tmp[i];
		return;
	}
	tmp[dep] = -1; D(dep + 1);
	for (int i = (1 << dep); i < (1 << dep + 1); i++)
		tmp[dep] = i, D(dep + 1);
}

void dfs(int u, int fu, int c)
{
	vis[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]])
		{
			fa[v] = u; dis[v] = dis[u] ^ val[e]; dep[v] = dep[u] + 1;
			dfs(v, u, c ? c : v);
			if (u == 1) ut[++cn] = v;
		}
		else if (dep[v] > dep[u])
		{
			if (u == 1) v1[fa[v]] = dis[u] ^ dis[v] ^ val[e];
			else v2[c].push_back(dis[u] ^ dis[v] ^ val[e]);
		}
}

int main()
{
	int x, y, z;
	memset(v1, -1, sizeof(v1));
	D(0);
	for (int I = 1; I <= tot; I++)
		for (int x = 0; x < 32; x++)
		{
			for (int i = 0; i < 5; i++) tmp[i] = a[I][i];
			int t = x; bool is = 0;
			for (int i = 4; i >= 0; i--)
			{
				if (!((t >> i) & 1)) continue;
				if (tmp[i] == -1) {tmp[i] = t; is = 1; break;}
				else t ^= tmp[i];
			}
			for (int i = 4; i >= 0; i--) if (tmp[i] != -1)
				for (int j = i + 1; j < 5; j++)
					if (tmp[j] != -1 && ((tmp[j] >> i) & 1))
						tmp[j] ^= tmp[i];
			std::vector<int> ti;
			for (int i = 0; i < 5; i++) ti.push_back(tmp[i]);
			if (is) tr[I][x] = orz[ti];
		}
	for (int I = 1; I <= tot; I++)
		for (int J = 1; J <= tot; J++)
		{
			int S = I;
			for (int i = 0; i < 5; i++) if (a[J][i] != -1)
				S = tr[S][a[J][i]];
			tx[I][J] = S;
		}
	read(n); read(m);
	while (m--) read(x), read(y), read(z), add_edge(x, y, z);
	dfs(1, 0, 0);
	f[0][1] = 1;
	for (int i = 1; i <= cn; i++)
	{
		int u = ut[i], Si = 1;
		for (int i = 0; i < v2[u].size(); i++)
			Si = tr[Si][v2[u][i]];
		for (int S = 1; S <= 374; S++) f[i][S] = f[i - 1][S];
		for (int S = 1; S <= 374; S++)
		{
			int T = tx[S][Si];
			f[i][T] = (f[i][T] + f[i - 1][S]) % rqy;
			if (v1[u] != -1)
			{
				f[i][T] = (f[i][T] + f[i - 1][S]) % rqy;
				int R = tr[T][v1[u]];
				f[i][R] = (f[i][R] + f[i - 1][S]) % rqy;
			}
		}
	}
	for (int S = 1; S <= 374; S++) ans = (ans + f[cn][S]) % rqy;
	return std::cout << ans << std::endl, 0;
}