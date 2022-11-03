/*
ID: Sfiction
OJ: CF
PROB: 275D
*/
#include <cstdio>
const int MAXN=100000;
struct tree
{
    char vis;
    int nex;
    long long val,pos,neg;
}f[MAXN+1];
int E[MAXN*2+1][2];
void Init()
{
    int t,N,i,u,v;
    scanf("%d",&N);
    for (t=0,i=1;i<N;++i)
    {
        scanf("%d%d",&u,&v);
        ++t;
        E[t][0]=f[u].nex;
        E[t][1]=v;
        f[u].nex=t;
        ++t;
        E[t][0]=f[v].nex;
        E[t][1]=u;
        f[v].nex=t;
    }
    for (i=1;i<=N;++i) scanf("%I64d",&f[i].val);
    return;
}
void DFS(int x)
{
    int i,j;
    f[x].vis=1;
    for (i=f[x].nex;i;i=E[i][0])
    {
        j=E[i][1];
        if (!f[j].vis)
        {
            DFS(j);
            if (f[j].pos>f[x].pos) f[x].pos=f[j].pos;
            if (f[j].neg>f[x].neg) f[x].neg=f[j].neg;
        }
    }
    f[x].val+=f[x].pos;
    f[x].val-=f[x].neg;
    if (f[x].val>0) f[x].neg+=f[x].val;
    else f[x].pos-=f[x].val;
    return;
}
int main()
{
    Init();
    DFS(1);
    printf("%I64d",f[1].pos+f[1].neg);
    return 0;
}