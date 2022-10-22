#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

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

const int N = 77, M = 205;

int n, k, ecnt, nxt[M], adj[N], go[M], typ[M];
ll f[N][N];
char s[4];

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; typ[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; typ[ecnt] = 6 - w;
}

bool check(int l, int r, int x, int y)
{
	for (int e = adj[x], v = go[e]; e; e = nxt[e], v = go[e])
	{
		if (typ[e] == 3 && v != x && v != y) return 0;
		if (typ[e] == 1 && (v < l || v > r || v == x || v == y)) return 0;
		if (typ[e] == 5 && l <= v && v <= r) return 0;
		if (typ[e] == 2 && (v < l || v > r)) return 0;
		if (typ[e] == 4 && l <= v && v < r && v != x && v != y) return 0;
	}
	for (int e = adj[y], v = go[e]; e; e = nxt[e], v = go[e])
	{
		if (typ[e] == 3 && v != x && v != y) return 0;
		if (typ[e] == 1 && (v < l || v > r || v == x || v == y)) return 0;
		if (typ[e] == 5 && l <= v && v <= r) return 0;
		if (typ[e] == 2 && (v < l || v > r)) return 0;
		if (typ[e] == 4 && l <= v && v < r && v != x && v != y) return 0;
	}
	return 1;
}

int main()
{
	int x, y;
	n = read() << 1; k = read();
	while (k--)
	{
		x = read(); scanf("%s", s + 1); y = read();
		int len = strlen(s + 1);
		if (len == 1)
		{
			if (s[1] == '<') add_edge(x, y, 1);
			else if (s[1] == '>') add_edge(x, y, 5);
			else add_edge(x, y, 3);
		}
		else if (s[1] == '<') add_edge(x, y, 2);
		else add_edge(x, y, 4);
	}
	for (int i = 1; i < n; i++) f[i][i + 1] = check(i, i + 1, i, i + 1);
	for (int l = n - 3; l >= 1; l--)
		for (int r = l + 3; r <= n; r += 2)
		{
			if (check(l, r, l, r)) f[l][r] += f[l + 1][r - 1];
			if (check(l, r, l, l + 1)) f[l][r] += f[l + 2][r];
			if (check(l, r, r - 1, r)) f[l][r] += f[l][r - 2];
		}
	std::cout << f[1][n] << std::endl;
	return 0;
}