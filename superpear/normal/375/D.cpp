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
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;
const int size=700;

struct four
{
    int l,r,kth,where;
} q[maxn],ls[maxn];

int N,M,o,xc,yc,nowans,dc,cs;
int lc[maxn],rc[maxn],biao[maxn],g[maxn],hash[maxn],color[maxn],ans[maxn];
vector<int> f[maxn];

four make_query(int a,int b,int c,int d)
{
    four s;
    s.l=a,s.r=b,s.kth=c,s.where=d;
    return s;
}

void dfs(int s,int father)
{
    ++o;
    lc[s]=o;
    biao[o]=s;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=father)
            dfs(f[s][i],s);
    rc[s]=o;
}

bool cmp(four a,four b)
{
    return a.l>b.l;
}

void mplus(int s,int num)
{
    while (s<=N)
    {
        g[s]+=num;
        s+=s&(-s);
    }
}

int getsum(int s)
{
    int ans=0;
    while (s>0)
    {
        ans+=g[s];
        s-=s&(-s);
    }
    return ans;
}

void plusit(int cc)
{
    if (hash[cc]!=0) mplus(hash[cc],-1);
    ++hash[cc];
    mplus(hash[cc],1);
}

int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;i++) scanf("%d",&color[i]);
    for (int i=1;i<N;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(lc,0,sizeof(lc));
    memset(rc,0,sizeof(rc));
    o=0;
    dfs(1,0);
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d",&xc,&yc);
        q[i]=make_query(lc[xc],rc[xc],yc,i);
    }
    for (int i=1;i<=M;i++) ans[i]=-1;
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=M;i++)
        if (q[i].r-q[i].l<=size)
        {
            nowans=0;
            for (int j=q[i].l;j<=q[i].r;j++)
            {
                cs=color[biao[j]];
                ++hash[cs];
                if (hash[cs]==q[i].kth) ++nowans;
            }
            ans[q[i].where]=nowans;
            for (int j=q[i].l;j<=q[i].r;j++) --hash[color[biao[j]]];
        }
    dc=(N-1)/size+1;
    for (int i=1;i<=dc;i++)
    {
        o=0;
        for (int j=1;j<=M;j++)
            if (q[j].r-q[j].l>size)
                if ((q[j].l>(i-1)*size)&&(q[j].l<=i*size))
                    ++o,ls[o]=q[j];
        sort(ls+1,ls+o+1,cmp);
        memset(hash,0,sizeof(hash));
        memset(g,0,sizeof(g));
        ls[0].l=ls[1].l;
        ls[0].r=ls[0].l-1;
        for (int j=1;j<=o;j++)
        {
            for (int k=ls[j-1].l-1;k>=ls[j].l;k--)
                plusit(color[biao[k]]);
            for (int k=ls[j-1].r+1;k<=ls[j].r;k++)
                plusit(color[biao[k]]);
            ans[ls[j].where]=getsum(N)-getsum(ls[j].kth-1);
        }
    }
    for (int i=1;i<=M;i++) printf("%d\n",ans[i]);

    return 0;
}