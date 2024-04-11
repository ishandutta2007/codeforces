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

int f[maxn],ans[maxn],a[maxn],oc[maxn];
PIII t[maxn];
vector<int> g[maxn];
int n,m,ec,xc,yc;

void mplus(int s,int c)
{
    while (s<=n)
    {
        f[s]+=c;
        s+=s&(-s);
    }
}

int getsum(int s)
{
    int e=0;
    while (s>0)
    {
        e+=f[s];
        s-=s&(-s);
    }
    return e;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) oc[a[i]]=i;
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        for (int j=2;j<=n/a[i];j++)
            g[i].p_b(oc[a[i]*j]);
        for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0)
            {
                g[i].p_b(oc[j]);
                if (a[i]/j!=j)
                    g[i].p_b(oc[a[i]/j]);
            }
        //for (int j=0;j<g[i].size();j++) cout<<g[i][j]<<" ";cout<<endl;
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<g[i].size();j++)
            if (g[i][j]>=i) mplus(g[i][j],1);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        t[i]=m_p(xc,m_p(yc,i));
    }
    sort(t+1,t+m+1);
    ec=1;
    for (int i=1;i<=m;i++)
    {
        while (ec<t[i].w1)
        {
            for (int j=0;j<g[ec].size();j++)
                if (g[ec][j]>=ec) mplus(g[ec][j],-1);
            ++ec;
        }
        ans[t[i].w2.w2]=getsum(t[i].w2.w1)-getsum(t[i].w1-1);
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);

    return 0;
}