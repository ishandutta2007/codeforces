#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define maxn 1005

struct Field
{
    char a[10][15];
};

int res;
int n, m, k, w;
int dist[maxn][maxn];
vector< pair< int, int > > edges, ans;
Field sm[maxn];
int par[maxn], rn[maxn];
vector< vector< int > > g;
int used[maxn];

inline bool
cmp(const pair< int, int > &a, const pair< int, int > &b)
{
    return dist[a.first][a.second] < dist[b.first][b.second];
}

void
input_field(Field &cur)
{
    for (int i = 0; i < n; ++i) {
        scanf(" %s", cur.a[i]);
    }
}

int
diff(Field &a, Field &b)
{
    int eres = 0;
    for (int i = 0; i < n; ++i) {
        char *aa = a.a[i], *bb = b.a[i];
        for (int j = 0; j < m; ++j, ++aa, ++bb) {
            eres += (*aa != *bb);
        }
    }
    return eres * w;
}

inline int
getPar(int x)
{
    if (par[x] != x) par[x] = getPar(par[x]);
    return par[x];
}

void
link_v(int x, int y)
{
    if (rn[x] >= rn[y]) {
        par[y] = x;
    } else {
        par[x] = y;
    }
    if (rn[x] == rn[y]) ++rn[x];
}

void
union_v(int x, int y)
{
    link_v(getPar(x), getPar(y));
}

void
dfs(int x, int pr)
{
    ans.push_back(make_pair(x + 1, pr + 1));
    if (pr == -1) {
        res += n * m;
    } else {
        res += dist[x][pr];
    }
    used[x] = 1;
    for (int i = 0; i < int(g[x].size()); ++i) {
        int to = g[x][i];
        if (!used[to]) {
            dfs(to, x);
        }
    }
}

bool
calc()
{
    if (scanf("%d%d%d%d", &n, &m, &k, &w) != 4) {
        return false;
    }
    for (int i = 0; i < k; ++i) {
        input_field(sm[i]);
    }
    edges.clear();
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            dist[i][j] = dist[j][i] = diff(sm[i], sm[j]);
            if (dist[i][j] < n * m) {
                //printf("add %d %d\n", i, j);
                edges.push_back(make_pair(i, j));
            }
        }
    }
    stable_sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < k; ++i) {
        par[i] = i;
        rn[i] = 0;
    }
    g.clear();
    g.resize(k + 5);
    for (vector< pair< int, int > >::iterator it = edges.begin(); it != edges.end(); ++it) {
        int a = it->first, b = it->second;
        int aa = getPar(a), bb = getPar(b);
        if (aa != bb) {
            //printf("add %d %d with dist %d\n", a, b, dist[a][b]);
            link_v(aa, bb);
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    res = 0;
    memset(used, 0, sizeof(used));
    ans.clear();
    for (int i = 0; i < k; ++i) {
        if (!used[i]) {
            //printf("dfs %d\n", i);
            dfs(i, -1);
        }
    }
    printf("%d\n", res);
    for (int i = 0; i < k; ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return true;
}

int
main()
{
/*#ifdef _DEBUG
    while (calc()) {puts("");}
#else*/
    calc();
//#endif
    return 0;
}