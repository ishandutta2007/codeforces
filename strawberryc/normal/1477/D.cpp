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
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 5e5 + 5;

int n, m, f[N][3], to[N], p[N], q[N], tot;
bool is[N];
std::vector<int> eg[N], son[N], oz[N], oy[N];
std::set<int> vis;

void dfstree(int u)
{
	int v;
	std::set<int>::iterator tmp; f[u][0] = 0; f[u][1] = f[u][2] = -1;
	for (int i = 0; i < eg[u].size(); i++) is[eg[u][i]] = 1;
	for (std::set<int>::iterator it = vis.begin(); it != vis.end();)
	{
		tmp = it; tmp++;
		if (!is[*it]) son[u].push_back(*it), vis.erase(it);
		it = tmp;
	}
	for (int i = 0; i < eg[u].size(); i++) is[eg[u][i]] = 0;
	for (int i = 0; i < son[u].size(); i++)
	{
		dfstree(v = son[u][i]);
		f[u][0] += Max(f[v][0], Max(f[v][1], f[v][2]));
	}
	int md = -9999999, mt, ms = -9999999, mv;
	if (!son[u].empty()) f[u][1] = f[u][0] + 1;
	for (int i = 0; i < son[u].size(); i++)
	{
		v = son[u][i]; int t1 = f[v][0] + 1 - Max(f[v][0], Max(f[v][1], f[v][2])),
			t2 = f[v][1] - Max(f[v][0], Max(f[v][1], f[v][2]));
		if (t1 > md) md = t1, mt = v;
		if (t1 > 0) oz[u].push_back(v), f[u][1] += t1;
		if (f[v][1] >= 0 && t2 > ms) ms = t2, mv = v;
	}
	if (!son[u].empty() && oz[u].empty()) oz[u].push_back(mt), f[u][1] += md;
	for (int i = 0; i < oz[u].size(); i++) is[oz[u][i]] = 1;
	for (int i = 0; i < son[u].size(); i++) if (!is[son[u][i]])
		oy[u].push_back(son[u][i]);
	for (int i = 0; i < oz[u].size(); i++) is[oz[u][i]] = 0;
	if (ms > -9999999) f[u][2] = f[u][0] + ms + 1, to[u] = mv;
}

void getans(int u, int op)
{
	if (op == -1)
	{
		if (f[u][0] >= f[u][1] && f[u][0] >= f[u][2]) return getans(u, 0);
		if (f[u][1] >= f[u][0] && f[u][1] >= f[u][2]) return getans(u, 1);
		if (f[u][2] >= f[u][0] && f[u][2] >= f[u][1]) return getans(u, 2);
	}
	if (op == 0)
	{
		p[u] = q[u] = ++tot;
		for (int i = 0; i < son[u].size(); i++) getans(son[u][i], -1);
		return;
	}
	if (op == 1)
	{
		int tmp = tot;
		for (int i = 0; i < oz[u].size(); i++) p[oz[u][i]] = ++tot,
			q[oz[u][i]] = tot + 1;
		p[u] = ++tot; q[u] = tmp + 1;
		for (int i = 0; i < oz[u].size(); i++)
			for (int j = 0; j < son[oz[u][i]].size(); j++)
				getans(son[oz[u][i]][j], -1);
		for (int i = 0; i < oy[u].size(); i++) getans(oy[u][i], -1);
		return;
	}
	int tmp = tot;
	for (int i = 0; i < oz[to[u]].size(); i++) p[oz[to[u]][i]] = ++tot,
		q[oz[to[u]][i]] = tot + 1;
	p[u] = ++tot; q[u] = tot + 1; p[to[u]] = ++tot; q[to[u]] = tmp + 1;
	for (int i = 0; i < oz[to[u]].size(); i++)
		for (int j = 0; j < son[oz[to[u]][i]].size(); j++)
			getans(son[oz[to[u]][i]][j], -1);
	for (int i = 0; i < oy[to[u]].size(); i++) getans(oy[to[u]][i], -1);
	for (int i = 0; i < son[u].size(); i++) if (son[u][i] != to[u])
		getans(son[u][i], -1);
}

void work()
{
	int x, y; std::set<int>::iterator it;
	read(n); read(m); vis.clear(); tot = 0;
	for (int i = 1; i <= n; i++) eg[i].clear(), son[i].clear(),
		oz[i].clear(), oy[i].clear(), vis.insert(i);
	while (m--) read(x), read(y), eg[x].push_back(y), eg[y].push_back(x);
	std::vector<int> roots;
	for (int i = 1; i <= n; i++) if ((it = vis.find(i)) != vis.end())
		vis.erase(it), dfstree(i), roots.push_back(i);
	for (int i = 0; i < roots.size(); i++) getans(roots[i], -1);
	for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	puts("");
	for (int i = 1; i <= n; i++) printf("%d ", q[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}