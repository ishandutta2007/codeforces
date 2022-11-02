#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
vector < int > g[maxN];
bool used[maxN];
int timer, tin[maxN], fup[maxN];
set < pair < int, int > > bridges;

int n, m, k;
int x[maxN], y[maxN];
 
void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p) continue;
		if (used[to]) {
			fup[v] = min(fup[v], tin[to]);
		} else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				bridges.insert(make_pair(v, to));
				bridges.insert(make_pair(to, v));
			}
		}
	}
}
 
void find_bridges() {
	timer = 0;
	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs (i);
}

vector < int > ng[maxN];
int color[maxN], ver;

vector < pair < int, int > > h[maxN];

void dfs2(int v, int cur_color) {
	if (color[v] != 0) return ;
	color[v] = cur_color;

	for (int i = 0; i < ng[v].size(); ++i)
		dfs2(ng[v][i], cur_color);
}

void compress() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < g[i].size(); ++j) {
			if (bridges.find(make_pair(i, g[i][j])) == bridges.end()) {
				ng[i].push_back(g[i][j]);
			}
		}
	for (int i = 0; i < n; ++i)
		if (!color[i]) {
			++ver;
			dfs2(i, ver);
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < g[i].size(); ++j)
			if (color[i] != color[g[i][j]]) {
				h[color[i]].push_back(make_pair(color[g[i][j]], 1));
			}
}

int order[maxN * 8];
int a[maxN * 8], t[maxN * 8], num[maxN * 8];
int first[maxN], d[maxN];

void dfs3(int v)
{
    if (used[v]) return;

    used[v] = true; m ++;
    order[m] = v, first[v] = m;

    for (int i = 0; i < h[v].size(); i ++)
        if (!used[h[v][i].first])
        {
            d[h[v][i].first] = d[v] + h[v][i].second;
            dfs3(h[v][i].first);
            m ++; order[m] = v;
        }
}

void build(int i = 1, int l = 1, int r = m)
{
    if (l == r) {t[i] = a[l]; num[i] = order[l]; return;}
    build(2 * i, l, (l + r) / 2);
    build(2 * i + 1, (l + r) / 2 + 1, r);
    if (t[2 * i] < t[2 * i + 1]) 
        t[i] = t[2 * i], num[i] = num[2 * i]; else
        t[i] = t[2 * i + 1], num[i] = num[2 * i + 1];
}

pair < int, int > lmin(int cl, int cr, int i = 1, int l = 1, int r = m)
{
    if (cl == l && cr == r) return make_pair(t[i], num[i]);
    if (cl > (l + r) / 2) return lmin(cl, cr, 2 * i + 1, (l + r) / 2 + 1, r);
    if (cr <= (l + r) / 2) return lmin(cl, cr, 2 * i, l, (l + r) / 2);

    return min(lmin(cl, (l + r) / 2, 2 * i, l, (l + r) / 2), lmin((l + r) / 2 + 1, cr, 2 * i + 1, (l + r) / 2 + 1, r));
}

void solve(int u, int v) {
	pair < int, int > p = (first[u] < first[v] ? lmin(first[u], first[v]) : lmin(first[v], first[u]));
    printf("%d\n", d[u] + d[v] - 2 * d[p.second]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		--x[i], --y[i];
	}

	find_bridges();
	compress();

	m = 0;
	memset(used, 0, sizeof(used));
	dfs3(1);
    for (int i = 1; i <= m; i ++) a[i] = d[order[i]];
    build();

	for (int i = 0; i < k; ++i)
		solve(color[x[i]], color[y[i]]);

	return 0;
}