#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 500100;

int n, q, m;
int par[MAXN], rnk[MAXN];
int h[MAXN];
vector< vector< int > > g;
bool used[MAXN];
int id[MAXN];
int mark[MAXN];
int colId[MAXN];
vector< vector< int > > allCol;

pair< int, int > 
getDist(int x, int par)
{
    pair< int, int > res = make_pair(0, x);
    for (auto nextV : g[x]) {
        if (nextV == par) {
            continue;
        }
        auto cand = getDist(nextV, x);
        cand.first++;
        if (cand > res) {
            res = cand;
        }
    }
    return res;
}

void
dfs(int x, int par, int cl)
{
    id[x] = cl;
    allCol[cl].push_back(x);
    used[x] = true;
    for (auto nextV : g[x]) {
        if (nextV != par) {
            dfs(nextV, x, cl);
        }
    }
}

void
markAll(int x, int par, int leftD, int val)
{
    if (leftD == 0) {
        mark[x] |= val;
        return;
    }
    for (auto nextV : g[x]) {
        if (nextV != par) {
            markAll(nextV, x, leftD - 1, val);
        }
    }
}

int
getPar(int x)
{
    if (par[x] != x) par[x] = getPar(par[x]);
    return par[x];
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    g.clear();
    g.resize(n + 5);
    allCol.resize(1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        used[i] = false;
        rnk[i] = 0, par[i] = i;
        mark[i] = 0;
    }
    int color = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ++color;
            allCol.push_back(vector< int >{});
            dfs(i, -1, color);
            int firstV = getDist(i, -1).second;
            auto resS = getDist(firstV, -1);
            int secondV = resS.second, dist = resS.first;
            markAll(firstV, -1, dist / 2, 1);
            markAll(secondV, -1, (dist + 1) / 2, 2);
            int ind = -1;
            for (auto v : allCol[color]) {
                if (mark[v] == 3) {
                    assert(ind == -1);
                    ind = v;
                    break;
                }
            }
            assert(ind != -1);
            colId[color] = ind;
            rnk[ind] = dist;
        }
    }
    for (int i = 0; i < q; ++i) {
        int type, x, y;
        cin >> type >> x;
        if (type == 1) {
            cout << rnk[getPar(colId[id[x]])] << '\n';
        } else {
            cin >> y;
            x = colId[id[x]];
            y = colId[id[y]];
            x = getPar(x), y = getPar(y);
            if (x != y) {
                int d1 = (rnk[x] + 1) / 2, d2 = (rnk[y] + 1) / 2;
                rnk[x] = max(rnk[x], max(rnk[y], d1 + d2 + 1));
                par[y] = x;
            }
        }
    }
    return 0;
}