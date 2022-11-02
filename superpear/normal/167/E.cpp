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

const int maxn=605;

vector<int> a[maxn];
int n,m,bigp,xc,yc,o,xx,yy,ans,cs,ct,e,mk;
int inp[maxn],outp[maxn],tyc[maxn],ls[maxn],p[maxn],use[maxn],b[maxn][maxn],f[maxn][maxn];

int powc(int a,int b,int bigp)
{
    if (b==0) return 1;
    int d=powc(a,b/2,bigp);
    d=(LL)d*d%bigp;
    if (b%2==1) d=(LL)d*a%bigp;
    return d;
}

int main()
{
    scanf("%d %d %d",&n,&m,&bigp);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        ++inp[yc],++outp[xc];
        a[xc].p_b(yc);
    }
    memset(tyc,0,sizeof(tyc));
    for (int i=1;i<=n;i++)
    {
        if (inp[i]==0) tyc[i]=1;
        if (outp[i]==0) tyc[i]=2;
        if (inp[i]+outp[i]==0) tyc[i]=3;
    }
    o=0;
    memset(p,0,sizeof(p));
    memset(use,0,sizeof(use));
    for (int i=1;i<=n;i++)
    {
        mk=-1;
        for (int j=1;j<=n;j++)
            if ((use[j]==0)&&(inp[j]==0))
            {
                mk=j;
                break;
            }
        use[mk]=1;
        ++o,p[o]=mk;
        for (int j=0;j<a[mk].size();j++)
            --inp[a[mk][j]];
    }
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
        if (tyc[i]>=2)
        {
            memset(ls,0,sizeof(ls));
            ls[i]=1;
            for (int j=n;j>=1;j--)
                for (int k=0;k<a[p[j]].size();k++)
                    ls[p[j]]=(ls[p[j]]+ls[a[p[j]][k]])%bigp;
            for (int j=1;j<=n;j++)
                b[j][i]=ls[j];
        }
    memset(f,0,sizeof(f));
    xx=0;
    for (int i=1;i<=n;i++)
        if ((tyc[i]==1)||(tyc[i]==3))
        {
            ++xx;
            yy=0;
            for (int j=1;j<=n;j++)
                if (tyc[j]>=2)
                {
                    ++yy;
                    f[xx][yy]=b[i][j];
                }
        }
    n=xx;
    ans=1;
    for (int i=1;i<=n;i++)
    {
        if (f[i][i]==0)
        {
            ans*=-1;
            e=i;
            for (int j=i+1;j<=n;j++)
                if (f[j][i]!=0)
                {
                    e=j;
                    break;
                }
            for (int j=1;j<=n;j++) swap(f[i][j],f[e][j]);
        }
        cs=powc(f[i][i],bigp-2,bigp);
        for (int j=i+1;j<=n;j++)
            if (f[j][i]!=0)
            {
                ct=(LL)f[j][i]*cs%bigp;
                for (int k=i;k<=n;k++)
                    f[j][k]=(f[j][k]-(LL)f[i][k]*ct%bigp+bigp)%bigp;
            }
    }
    for (int i=1;i<=n;i++) ans=(LL)ans*f[i][i]%bigp;
    ans=(ans+bigp)%bigp;
    printf("%d\n",ans);

    return 0;
}