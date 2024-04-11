#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 2014;

typedef long long ll;

ll d[MAXN][MAXN];
ll nd[MAXN][MAXN];
int n;

vector< vector< int > > g;
vector< pair< ll, pair< int, int > > > sm;

int pr[MAXN], rnk[MAXN];

inline int
getPar(int x)
{
    if (pr[x] != x) {
        pr[x] = getPar(pr[x]);
    }
    return pr[x];
}

void
merge_t(int x, int y)
{
    if (rnk[x] >= rnk[y]) {
        pr[y] = x;
    } else {
        pr[x] = y;
    }
    if (rnk[x] == rnk[y]) {
        ++rnk[x];
    }
}

void
dfs(int v, int x, int par, ll cur_dist)
{
    nd[v][x] = cur_dist;
    for (auto to : g[x]) {
        if (to != par) {
            dfs(v, to, x, cur_dist + d[x][to]);
        }
    }
}

int
main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            scanf("%d", &tmp);
            d[i][j] = tmp;
            if (i < j && d[i][j] != 0) {
                sm.push_back(make_pair(d[i][j], make_pair(i, j)));
            }
        }
    }
    g.clear();
    g.resize(n);
    sort(sm.begin(), sm.end());
    for (int i = 0; i < n; ++i) {
        pr[i] = i;
        rnk[i] = 0;
    }
    for (auto edge : sm) {
        int x = edge.second.first, y = edge.second.second;
        int px = getPar(x), py = getPar(y);
        if (px != py) {
            merge_t(px, py);
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            nd[i][j] = -1LL;
        }
        dfs(i, i, -1, 0);
    }
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        for (int j = 0; j < n && ok; ++j) {
            ok = (d[i][j] == nd[i][j] && d[i][j] == d[j][i]);
        }
    }
    if (ok) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}