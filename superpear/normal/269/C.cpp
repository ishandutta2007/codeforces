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

const int maxn=200005;

int n,m,rc,fc,all[maxn],x[maxn],y[maxn],w[maxn],use[maxn],u[maxn],ans[maxn];
PII sc;
vector<PII> f[maxn];

int main()
{
    scanf("%d %d",&n,&m);
    memset(all,0,sizeof(all));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&w[i]);
        f[x[i]].p_b(m_p(y[i],i));
        f[y[i]].p_b(m_p(x[i],i));
        all[x[i]]+=w[i];
        all[y[i]]+=w[i];
    }
    memset(ans,0,sizeof(ans));
    memset(use,0,sizeof(use));
    rc=1;fc=1;u[rc]=1;
    use[1]=1;use[n]=1;
    while (rc<=fc)
    {
        for (int i=0;i<f[u[rc]].size();i++)
        {
            sc=f[u[rc]][i];
            if (ans[sc.w2]==0)
            {
                if (x[sc.w2]==u[rc]) ans[sc.w2]=-1; else ans[sc.w2]=1;
                all[sc.w1]-=w[sc.w2]*2;
                if (all[sc.w1]==0)
                {
                    if (use[sc.w1]==0)
                    {
                        use[sc.w1]=1;
                        ++fc,u[fc]=sc.w1;
                    }
                }
            }
        }
        ++rc;
    }
    for (int i=1;i<=m;i++)
        if (ans[i]==-1) printf("0\n"); else printf("1\n");

    return 0;
}