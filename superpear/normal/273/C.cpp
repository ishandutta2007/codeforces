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

const int maxn=300005;

int m,n,xc,yc,rc,fc,cs,t1;
vector<int> f[maxn];
int biao[maxn],u[maxn];

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(biao,0,sizeof(biao));
    for (int i=1;i<=n;i++)
        if (biao[i]==0)
        {
            rc=1;fc=1;u[rc]=i;
            biao[i]=1;
            while (rc<=fc)
            {
                for (int j=0;j<f[u[rc]].size();j++)
                {
                    cs=f[u[rc]][j];
                    if (biao[cs]==0)
                    {
                        biao[cs]=3-biao[u[rc]];
                        ++fc;u[fc]=cs;
                    }
                }
                ++rc;
            }
        }
    for (int tt=1;tt<=10;tt++)
    {
        for (int i=1;i<=n;i++)
            if (f[i].size()==3)
            {
                t1=0;
                if (biao[i]==biao[f[i][0]]) ++t1;
                if (biao[i]==biao[f[i][1]]) ++t1;
                if (biao[i]==biao[f[i][2]]) ++t1;
                if (t1>1) biao[i]=3-biao[i];
            }
    }
    for (int i=1;i<=n;i++) printf("%d",biao[i]-1);cout<<endl;

    return 0;
}