#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int M, K, P, i, j, u, v, e[200001][2], enxt[200001], head[100001], ec;
int maxdep, lyr[100001], vis[100001];
int used[100001], totuse, prevuse, cost, ans;

void REGI(int u, int v)
{
    ec++;
    e[ec][0] = u; e[ec][1] = v;
    enxt[ec] = head[u]; head[u] = ec;
}

void dfs(int Nid, int Dep)
{
    if (Dep > maxdep) lyr[++maxdep] = 0;
    lyr[Dep]++;
    vis[Nid] = 1;
    for (int E = head[Nid]; E; E = enxt[E])
        if (!vis[e[E][1]])
            dfs(e[E][1], Dep + 1);
}

int main()
{
    scanf("%d%d%d", &M, &K, &P);
    fortodo(i, 1, M) head[i] = 0; ec = 0;
    fortodo(i, 2, M)
        {
            scanf("%d%d", &u, &v);
            REGI(u, v); REGI(v, u);
        }
    maxdep = -1;
    fortodo(i, 1, M) vis[i] = 0;
    dfs(1, 0);
    ans = totuse = cost = 0;
    fortodo(i, 1, maxdep) used[i] = 0;
    prevuse = maxdep;
    for (i = maxdep; i; i--)
        {
            while (prevuse)
                {
                    int increment = min(lyr[prevuse] - used[prevuse], K - totuse);
                    if (i != prevuse)
                        increment = min(increment, (P - cost) / (i - prevuse));
                    if (increment == 0) break;
                    cost += (i - prevuse) * increment;
                    used[prevuse] += increment;
                    //printf("increase %d * [%d]\n", increment, prevuse);
                    totuse += increment;
                    if (lyr[prevuse] == used[prevuse]) prevuse--;
                }
            ans = max(ans, totuse);
            //if (used[i])
            //  printf("remove %d * [%d]\n", used[i], i);
            totuse -= used[i]; used[i] = 0;
            cost -= totuse;
            if (prevuse == i) prevuse--;
        }
    printf("%d\n", ans);
}