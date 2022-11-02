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

int n,m,xc,yc,zc;
int f[305][305],a[305][305];

int main()
{
    scanf("%d %d",&n,&m);
    memset(f,127,sizeof(f));
    memset(a,127,sizeof(a));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&xc,&yc,&zc);
        f[xc][yc]=zc;
        f[yc][xc]=zc;
        a[xc][yc]=zc;
        a[yc][xc]=zc;
    }
    for (int i=1;i<=n;i++)
        f[i][i]=0;
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if ((f[i][k]!=biglongint)&&(f[k][j]!=biglongint))
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    double ans=1e10,maxc;
    for (int i=1;i<=n;i++)
    {
        maxc=0;
        for (int j=1;j<=n;j++)
            maxc=max(maxc,double(f[i][j]));
        ans=min(ans,maxc);
    }
    double ttj;
    int maxj[10005];
    PII e[10005];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=biglongint)
            {
                for (int k=1;k<=n;k++)
                    e[k]=m_p(f[k][i],f[k][j]);
                sort(e+1,e+n+1);
                maxj[n+1]=0;
                for (int k=n;k>=1;k--)
                    maxj[k]=max(maxj[k+1],e[k].w2);
                for (int k=1;k<=n;k++)
                {
                    ttj=double(e[k].w1+maxj[k+1]+a[i][j])/2;
                    if ((ttj-e[k].w1>0)&&(ttj-e[k].w1<a[i][j]))
                        ans=min(ans,double(e[k].w1+maxj[k+1]+a[i][j])/2);
                    ans=min(ans,double(max(e[k].w1,maxj[k+1]))+a[i][j]);
                }
            }
    printf("%.20lf\n",ans);

    return 0;
}