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

long long ans[120000],sum[120000];
int a[120000];
int n,m,sc;

bool cmp(int a,int b)
{
    return a>b;
}

void doit(int s)
{
    int e,ls;
    long long ss,t;
    t=1;e=1;ls=0;ss=0;
    while ((long long)e+t-1<=n)
    {
        ss+=(long long)ls*(sum[e+t-1]-sum[e-1]);
        e+=t;
        t=t*(long long)s;
        ++ls;
    }
    if (e<=n) ss+=(long long)ls*(sum[n]-sum[e-1]);
    ans[s]=ss;
}

int main()
{
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    scanf("%d",&m);
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&sc);
        if (ans[sc]==0) doit(sc);
        printf("%I64d ",ans[sc]);
    }
    printf("\n");
    return 0;
}