#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=200005;

int x[maxn],y[maxn],z[maxn],use[maxn],depth[maxn],fa[maxn],hash[maxn];
int mulfa[maxn][19],maxf[maxn][19];
vector<PII> f[maxn];
int M,N,xc,yc,zc,uu,uc,diff,Q;
PIII ls[maxn];

void dfs(int s,int father,int ss)
{
    mulfa[s][0]=father;
    maxf[s][0]=ss;
    depth[s]=depth[father]+1;
    for (int i=1;i<=17;i++)
    {
        mulfa[s][i]=mulfa[mulfa[s][i-1]][i-1];
        maxf[s][i]=max(maxf[s][i-1],maxf[mulfa[s][i-1]][i-1]);
    }
    for (int i=0;i<f[s].size();i++)
        if (f[s][i].w1!=father)
            dfs(f[s][i].w1,s,f[s][i].w2);
}

int LCA(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=17;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y]) x=mulfa[x][i];
    if (x==y) return y;
    for (int i=17;i>=0;i--)
        if (mulfa[x][i]!=mulfa[y][i]) x=mulfa[x][i],y=mulfa[y][i];
    return mulfa[x][0];
}

int getmax(int x,int y)
{
    int maxc=0;
    for (int i=17;i>=0;i--)
        if (depth[mulfa[x][i]]>=depth[y])
        {
            maxc=max(maxc,maxf[x][i]);
            x=mulfa[x][i];
        }
    return maxc;
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&M);
    for (int i=1;i<=M;i++)
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
    for (int i=1;i<=M;i++)
        ls[i]=m_p(z[i],m_p(x[i],y[i]));
    sort(ls+1,ls+M+1);
    for (int i=1;i<=M;i++)
    {
        x[i]=ls[i].w2.w1;
        y[i]=ls[i].w2.w2;
        z[i]=ls[i].w1;
    }
    LL ansc=0;
    for (int i=1;i<=N;i++) fa[i]=i;
    memset(use,0,sizeof(use));
    for (int i=1;i<=M;i++)
    {
        xc=x[i],yc=y[i];
        while (fa[xc]!=xc) xc=fa[xc];
        while (fa[yc]!=yc) yc=fa[yc];
        if (xc!=yc)
        {
            use[i]=1;
            ansc+=z[i];
            fa[xc]=yc;
            uu=x[i];
            while (fa[uu]!=yc)
            {
                uc=fa[uu];
                fa[uu]=yc;
                uu=uc;
            }
            uu=y[i];
            while (fa[uu]!=yc)
            {
                uc=fa[uu];
                fa[uu]=yc;
                uu=uc;
            }
        }
    }
    memset(hash,0,sizeof(hash));
    diff=0;
    for (int i=1;i<=N;i++)
    {
        xc=i;
        while (fa[xc]!=xc) xc=fa[xc];
        if (hash[xc]==0) ++diff;
        hash[xc]=1;
    }
    scanf("%d",&Q);
    if (diff>2)
    {
        for (int i=1;i<=Q;i++) printf("-1\n");
        return 0;
    }
    if (diff==2)
    {
        for (int i=1;i<=Q;i++)
        {
            scanf("%d %d",&xc,&yc);
            while (fa[xc]!=xc) xc=fa[xc];
            while (fa[yc]!=yc) yc=fa[yc];
            if (xc==yc) printf("-1\n"); else printf("%I64d\n",ansc);
        }
    }
    else
    {
        for (int i=1;i<=M;i++)
            if (use[i]==1)
            {
                f[x[i]].p_b(m_p(y[i],z[i]));
                f[y[i]].p_b(m_p(x[i],z[i]));
            }
        memset(depth,0,sizeof(depth));
        memset(mulfa,0,sizeof(mulfa));
        dfs(1,0,0);
        for (int i=1;i<=Q;i++)
        {
            scanf("%d %d",&xc,&yc);
            zc=LCA(xc,yc);
            printf("%I64d\n",ansc-max(getmax(xc,zc),getmax(yc,zc)));
        }
    }

    return 0;
}