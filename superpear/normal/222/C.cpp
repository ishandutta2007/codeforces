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

#define maxlongint 2147483647
#define biglongint 2139062143


using namespace std;

const int maxn=3500;

int prime[maxn],p[maxn],a[120000],b[120000],f[10000005],g[10000005];
int m,n,o,e,sc;

int main()
{
    //freopen("C.in","r",stdin);
    memset(prime,0,sizeof(prime));
    prime[1]=1;
    for (int i=2;i<=maxn;i++)
        if (prime[i]==0)
            for (int j=i;i*j<=maxn;j++)
                prime[i*j]=1;
    o=0;
    for (int i=1;i<=maxn;i++)
        if (prime[i]==0)
        {
            ++o;
            p[o]=i;
        }
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        e=a[i];sc=1;
        while ((sc<=o)&&(e>1))
        {
            while (e%p[sc]==0)
            {
                ++f[p[sc]];e/=p[sc];
            }
            ++sc;
        }
        if (e>1) ++f[e];
    }
    memset(g,0,sizeof(g));
    for (int i=1;i<=m;i++)
    {
        e=b[i];sc=1;
        while ((sc<=o)&&(e>1))
        {
            while (e%p[sc]==0)
            {
                ++g[p[sc]];e/=p[sc];
            }
            ++sc;
        }
        if (e>1) ++g[e];
    }
    for (int i=1;i<=10000000;i++)
    {
        f[i]=min(f[i],g[i]);g[i]=f[i];
    }
    for (int i=1;i<=n;i++)
    {
        e=a[i];sc=1;
        while ((sc<=o)&&(e>1))
        {
            while (e%p[sc]==0)
            {
                e/=p[sc];
                if (f[p[sc]]>0)
                {
                    --f[p[sc]];
                    a[i]/=p[sc];
                }
            }
            ++sc;
        }
        if (e>1)
        {
            if (f[e]>0)
            {
                --f[e];
                a[i]/=e;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        e=b[i];sc=1;
        while ((sc<=o)&&(e>1))
        {
            while (e%p[sc]==0)
            {
                e/=p[sc];
                if (g[p[sc]]>0)
                {
                    --g[p[sc]];
                    b[i]/=p[sc];
                }
            }
            ++sc;
        }
        if (e>1)
        {
            if (g[e]>0)
            {
                --g[e];
                b[i]/=e;
            }
        }
    }
    printf("%d %d\n",n,m);
    for (int i=1;i<n;i++) printf("%d ",a[i]);printf("%d\n",a[n]);
    for (int i=1;i<m;i++) printf("%d ",b[i]);printf("%d\n",b[m]);

    return 0;
}