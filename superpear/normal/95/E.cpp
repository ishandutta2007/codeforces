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
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

vector<int> f[maxn];
int a[maxn],use[maxn],u[maxn],v[maxn],w[maxn],dat[maxn];
int n,m,xc,yc,rc,fc,cs,t,o,tys,ee,ans;

bool lucky(int s)
{
    while (s>0)
    {
        if ((s%10!=4)&&(s%10!=7)) return false;
        s/=10;
    }
    return true;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    o=0;
    memset(use,0,sizeof(use));
    for (int i=1;i<=n;i++)
        if (use[i]==0)
        {
            rc=1,fc=1,u[rc]=i,use[i]=1;
            while (rc<=fc)
            {
                for (int j=0;j<f[u[rc]].size();j++)
                {
                    cs=f[u[rc]][j];
                    if (use[cs]==0)
                    {
                        use[cs]=1;
                        ++fc,u[fc]=cs;
                    }
                }
                ++rc;
            }
            ++o,dat[o]=fc;
        }
    sort(dat+1,dat+o+1);
    t=0;
    for (int i=1;i<=o;i++)
        if ((i==1)||(dat[i]!=dat[i-1]))
        {
            cs=i;
            while ((cs<o)&&(dat[cs]==dat[cs+1])) ++cs;
            tys=cs-i+1;
            ee=1;
            while (tys>=ee)
            {
                ++t,v[t]=dat[i]*ee,w[t]=ee;
                tys-=ee;
                ee*=2;
            }
            if (tys>0) ++t,v[t]=dat[t]*tys,w[t]=tys;
        }

    memset(a,127,sizeof(a));
    a[0]=0;
    for (int i=1;i<=t;i++)
        for (int j=77777;j>=v[i];j--)
            if (a[j-v[i]]+w[i]<=a[j]) a[j]=a[j-v[i]]+w[i];
    ans=maxlongint;
    for (int i=1;i<=n;i++)
        if (lucky(i)) ans=min(ans,a[i]);
    if (ans>=biglongint) ans=-1; else --ans;
    printf("%d\n",ans);

    return 0;
}