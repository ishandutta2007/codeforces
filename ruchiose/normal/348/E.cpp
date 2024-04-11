// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int BIGINT = 0x55555555;
const int MAXN = 100010;
const int MAXE = MAXN << 1;

int N, M;
bool Monastery[MAXN];

int e[MAXE], w[MAXE], head[MAXN], enxt[MAXE], ec;
int anyMonastery;

void regi(int u, int v, int w)
{
    e[++ec] = v; ::w[ec] = w;
    enxt[ec] = head[u]; head[u] = ec;
}

int diameter[2];
int dist[MAXN];

#include<vector>
#include<queue>

void BFS(int x)
{
    int i;
    fortodo(i, 1, N) dist[i] = BIGINT;
    dist[x] = 0;
    queue<int> Q;
    while (Q.size()) Q.pop();
    Q.push(x);
    while (Q.size())
        {
            int u = Q.front(); Q.pop();
            for (int E = head[u]; E; E = enxt[E])
                if (dist[e[E]] == BIGINT)
                    {
                        dist[e[E]] = dist[u] + w[E];
                        Q.push(e[E]);
                    }
        }
}

int farthestMonastery()
{
    int ret = anyMonastery;
    int i;
    fortodo(i, 1, N)
        if ((Monastery[i]) && (dist[i] > dist[ret]))
            ret = i;
    return ret;
}

vector<int> Diameter;

void makeDiameter()
{
    Diameter.clear();
    Diameter.push_back(diameter[1]);
    while (Diameter.back() != diameter[0])
        for (int E = head[Diameter.back()]; E; E = enxt[E])
            if (dist[Diameter.back()] - dist[e[E]] == w[E])
                {
                    Diameter.push_back(e[E]);
                    break;
                }
    reverse(Diameter.begin(), Diameter.end());
}

int project[MAXN];

void Project()
{
    int i;
    queue<int> Q;
    while (Q.size()) Q.pop();
    fortodo(i, 1, N) project[i] = 0;
    for (vector<int>::iterator it = Diameter.begin(); it != Diameter.end(); it++)
        {
            project[*it] = *it;
            Q.push(*it);
        }
    while (Q.size())
        {
            int u = Q.front(); Q.pop();
            for (int E = head[u]; E; E = enxt[E])
                if (project[e[E]] == 0)
                    {
                        project[e[E]] = project[u];
                        Q.push(e[E]);
                    }
        }
}

int core[2];

void makeCore()
{
    core[0] = diameter[0];
    core[1] = diameter[1];
    int i;
    fortodo(i, 1, N)
        if (Monastery[i])
            {
                if ((dist[project[i]] * 2 <= dist[diameter[1]]) && (dist[project[i]] * 2 == dist[i]) && (dist[core[0]] < dist[project[i]]))
                    core[0] = project[i];
                if ((dist[project[i]] * 2 >= dist[diameter[1]]) && (dist[i] == dist[diameter[1]]) && (dist[core[1]] > dist[project[i]]))
                    core[1] = project[i];
            }
}

int dep[MAXN], ance[MAXN][17];

void DFS_makeAncestors(int cur, int f, int dep)
{
    ::dep[cur] = dep;
    ance[cur][0] = f;
    for (int i = 1; i <= 16; i++) ance[cur][i] = ance[ance[cur][i - 1]][i - 1];
    for (int E = head[cur]; E; E = enxt[E])
        if (e[E] != f)
            DFS_makeAncestors(e[E], cur, dep + 1);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    while (dep[u] - dep[v]) u = ance[u][__builtin_ctz(dep[u] - dep[v])];
    if (u == v) return u;
    for (int lv = 31 - __builtin_clz(dep[u]); lv >= 0; lv--)
        if (ance[u][lv] != ance[v][lv])
            {
                u = ance[u][lv];
                v = ance[v][lv];
            }
    return ance[u][0];
}

int val[MAXN];

void attChain(int u, int v)
{
    int z = lca(u, v);
    val[u]++;
    val[v]++;
    val[z]--;
    val[ance[z][0]]--;
}

void DFS_makeAnswer(int cur)
{
    for (int E = head[cur]; E; E = enxt[E])
        if (dep[e[E]] > dep[cur])
            {
                DFS_makeAnswer(e[E]);
                val[cur] += val[e[E]];
            }
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N) Monastery[i] = false;
    fortodo(i, 1, M)
        {
            int u;
            scanf("%d", &u);
            Monastery[u] = true;
            anyMonastery = u;
        }
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 2, N)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            regi(u, v, w);
            regi(v, u, w);
        }
    BFS(anyMonastery);
    diameter[0] = farthestMonastery();
    BFS(diameter[0]);
    diameter[1] = farthestMonastery();
    makeDiameter();
    Project();
    makeCore();
    fortodo(i, 0, 16) ance[0][i] = 0;
    DFS_makeAncestors(1, 0, 0);
    fortodo(i, 1, N) val[i] = 0;
    fortodo(i, 1, N)
        if (Monastery[i])
            {
                if (dist[project[i]] * 2 < dist[diameter[1]])
                    attChain(i, core[1]);
                if (dist[project[i]] * 2 == dist[diameter[1]])
                    attChain(i, project[i]);
                if (dist[project[i]] * 2 > dist[diameter[1]])
                    attChain(i, core[0]);
            }
    DFS_makeAnswer(1);
    int ans = 0, cnt = 0;
    fortodo(i, 1, N)
        if (!Monastery[i])
            {
                if (val[i] > ans)
                    {
                        ans = val[i];
                        cnt = 0;
                    }
                if (val[i] == ans)
                    cnt++;
            }
    printf("%d %d\n", ans, cnt);
}