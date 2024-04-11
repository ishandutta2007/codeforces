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

LL fib[105];
int use[105],pre[105];
LL f[105],g[105];
int tt,last;
LL n;

int main()
{
    fib[1]=1;
    fib[2]=2;
    for (int i=3;i<=91;i++) fib[i]=fib[i-1]+fib[i-2];
    scanf("%d",&tt);
    for (int gb=1;gb<=tt;gb++)
    {
        scanf("%I64d",&n);
        memset(use,0,sizeof(use));
        memset(pre,0,sizeof(pre));
        last=0;
        for (int i=91;i>=1;i--)
            if (n>=fib[i]) use[i]=1,pre[last]=i,last=i,n-=fib[i];
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        if (use[1]==1) f[1]=1; else g[1]=1;
        if (use[2]==1) f[2]=1; else g[2]=1;
        for (int i=3;i<=91;i++)
        {
            if (use[i]==1)
            {
                f[i]=g[i-1];
                g[i]=0;
                for (int j=2;j<=100;j+=2)
                    if (i-j>=pre[i]) g[i]+=g[i-j];
            }
            else
            {
                f[i]=0;
                g[i]=g[i-1]+f[i-1];
            }
        }
        printf("%I64d\n",f[91]+g[91]);
    }

    return 0;
}