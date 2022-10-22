#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 3e4 + 5;

int n, m, tot, p[N], c[N], d, k[N], ecnt, nxt[N], adj[N], go[N], ans[N],
QAQ, vis[N], my[N], now;
bool del[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

bool dfs(int u)
{
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (vis[v] < QAQ)
		{
			vis[v] = QAQ;
			if (my[v] == -1 || dfs(my[v]))
				return my[v] = u, 1;
		}
	return 0;
}

bool find_match(int x)
{
	QAQ++; return dfs(x);
}

int main()
{
	memset(my, -1, sizeof(my));
	n = read(); m = read();
	for (int i = 1; i <= n; i++) tot = Max(tot, p[i] = read());
	for (int i = 1; i <= n; i++) c[i] = read();
	d = read();
	for (int i = 1; i <= d; i++) del[k[i] = read()] = 1;
	for (int i = 1; i <= n; i++) if (!del[i]) add_edge(p[i], tot + c[i]);
	for (int i = d; i >= 1; i--)
	{
		while (now <= tot && find_match(now)) now++;
		ans[i] = now;
		add_edge(p[k[i]], tot + c[k[i]]);
	}
	for (int i = 1; i <= d; i++) printf("%d\n", ans[i]);
	return 0;
}
//