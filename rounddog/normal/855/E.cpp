#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 500500
#define inf 1000000020

using namespace std;
typedef long long ll;

ll l,r,n,p[100],a[11][100][1024],s,query,w,c,ii;

ll cnt(ll x,ll y)
{
    if (!x) return 0;
    int m=0;
    while (x)
    {
        p[m++]=x%y;
        x/=y;
    }
    w=0;c=0;
    for (int j=1;j<m;j++)
        for (int k=1;k<y;k++)
            c+=a[y][j-1][(1<<k)];
    for (int i=m-1;i>=0;i--)
    {
        if (i==m-1) ii=1; else ii=0;
        for (int j=ii;j<p[i];j++) c+=a[y][i][w^(1<<j)];
        w^=(1<<p[i]);
    }
    if (!w) c++;
    return c;
}

int main()
{
    memset(a,0,sizeof(a));
    for (int k=2;k<11;k++)
    {
        a[k][0][0]=1;s=1;
        for (int i=0;s<1e18;i++)
        {
            s=s*k;
            for (int j=0;j<(1<<k);j++)
                for (int d=0;d<k;d++)
                    a[k][i+1][j^(1<<d)]+=a[k][i][j];
        }
    }
    scanf("%d",&query);
    while (query--)
    {
        scanf("%I64d%I64d%I64d",&n,&l,&r);
        printf("%I64d\n",cnt(r,n)-cnt(l-1,n));
    }
    return 0;
}