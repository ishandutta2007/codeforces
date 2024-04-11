#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
 
using namespace std;
 
const int N = 55;
const int M = 11111;
 
struct node {
    int u, v;
    int next;
} edge[N * N];
 
int n, k, num;
int head[N];
int g[N][N];
int mx;
int All[M][N], Some[M][N], None[M][N];
 
void addedge(int u, int v)
{
    edge[num].u = u;
    edge[num].v = v;
    edge[num].next = head[u];
    head[u] = num++;
}
 
void init()
{
    mx = 0;
    num = 0;
    memset(head, -1, sizeof(head));
    memset(g, 0, sizeof(g));
}
 
void BronKerbosch(int id, int lenAll, int lenSome, int lenNone)
{
//  cout<<"id: "<<id<<" lenAll: "<<lenAll<<" lenSome: "<<lenSome<<" lenNone: "<<lenNone<<endl;
    if(lenSome==0 && lenNone==0)
    {
        if(lenAll > mx)
            mx=lenAll;
        return ;
    }
    if(lenSome == 0)
        return;

    int i, j, u, v, tid, tlenAll, tlenSome, tlenNone;
    u = Some[id][1]; tid = id+1;

    for(i = 1; i <= lenSome; i++)
    {
        v = Some[id][i];
        if(g[u][v]) continue;
        tlenAll = lenAll + 1;
        for(j = 1; j <= lenAll; j++)
            All[tid][j] = All[id][j];
        All[tid][tlenAll]=v;
        tlenSome = 0;
        for(j = 1; j <= lenSome; j++)
            if(g[v][Some[id][j]])
                Some[tid][++tlenSome] = Some[id][j];
        tlenNone = 0;
        for(j = 1; j <= lenNone; j++)
            if(g[v][None[id][j]])
                None[tid][++tlenNone] = None[id][j];
        BronKerbosch(tid, tlenAll, tlenSome, tlenNone);
    }
}
 
void solve()
{
    int i, j;
    for(i = 1; i <= n; i ++)
        Some[0][i] = i;
    BronKerbosch(0, 0, n, 0);
}
 
int main()
{
    int i, j;
    init();
    scanf("%d %d", &n, &k);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
            if(g[i][j]==1)
                addedge(i,j);
        }
    }
    
    solve();
    double ans=1.0*(mx-1)*mx/2*(1.0*k/mx)*(1.0*k/mx);
    printf("%.10lf\n",ans);
    return 0;
}