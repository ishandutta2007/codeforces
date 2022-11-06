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

const int MAXN = 100010;
const int MAXM = 300010;
const int MAXK = 100010;
const int MAXE = (MAXM + MAXK) << 1;

int N, M, K;
int e[MAXE], l[MAXE], enxt[MAXE], head[MAXN], ec;

void regi(int u, int v, int w)
{
    ec++;
    e[ec] = v; l[ec] = w;
    enxt[ec] = head[u]; head[u] = ec;
}

#include<set>

i64 dist[MAXN];
bool vis[MAXN];

bool operator < (pair<i64,int> lhs, pair<i64,int> rhs)
{
    return (lhs.first == rhs.first) ? (lhs.second < rhs.second) : (lhs.first < rhs.first);
}

set<pair<i64,int> > cand;

void dijkstra()
{
    int i;
    fortodo(i, 1, N)
        dist[i] = 1ll << 60;
    dist[1] = 0;
    cand.clear();
    fortodo(i, 1, N) cand.insert(make_pair(dist[i], i));
    while (cand.size())
        {
            int u = cand.begin()->second;
            cand.erase(cand.begin());
            for (int E = head[u]; E; E = enxt[E])
                if (dist[e[E]] > dist[u] + l[E])
                    {
                        cand.erase(make_pair(dist[e[E]], e[E]));
                        dist[e[E]] = dist[u] + l[E];
                        cand.insert(make_pair(dist[e[E]], e[E]));
                    }
        }
}

#include<vector>

void shuffle_edges(int u)
{
    vector<int> es;
    es.clear();
    for (int E = head[u]; E; E = enxt[E]) es.push_back(E);
    random_shuffle(es.begin(), es.end());
    int esz = es.size();
    int i;
    head[u] = 0;
    fortodo(i, 0, esz - 1)
        {
            enxt[es[i]] = head[u];
            head[u] = es[i];
        }
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    int i;
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 1, M)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            regi(u, v, w);
            regi(v, u, w);
        }
    fortodo(i, 1, K)
        {
            int s, y;
            scanf("%d%d", &s, &y);
            regi(1, s, y);
            regi(s, 1, y);
        }
    dijkstra();
    int ans = 0;
    fortodo(i, 2, N)
        {
            int dah = 0, src = 0, dahsrc = 0;
            for (int E = head[i]; E; E = enxt[E])
                {
                    if (dist[e[E]] + l[E] == dist[i]) src++;
                    if (E > M * 2) dah++;
                    if ((dist[e[E]] + l[E] == dist[i]) && (E > M * 2)) dahsrc++;
                }
            if (src != dahsrc)
                ans += dah;
            else
                ans += dah - 1;
        }
    printf("%d\n", ans);
}