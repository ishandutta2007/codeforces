#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define maxn 1000020
#define mod 1000000007

using namespace std;

long long int cnt[maxn],p[maxn],d[maxn],mi[maxn],a[maxn],n,m,k,ans;

int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++)
	{
	    scanf("%d",&k);
		a[k]++;
	}
	mi[1]=1;
	for (int i=2;i<maxn;i++)
	    mi[i]=(mi[i-1]*2)%mod;
    for (int i=2;i<maxn;i++)
        p[i]=i;
    for (int i=2;i<maxn/2;i++)
        for (int j=2;i*j<maxn;j++)
            p[i*j]-=p[i];
    for (int i=2;i<maxn;i++)
        for (int j=1;i*j<maxn;j++)
            cnt[i]+=a[i*j];
    for (int i=2;i<maxn;i++)
        ans=(ans+(mi[cnt[i]]*cnt[i]%mod)*p[i]%mod)%mod;
    printf("%d\n",ans);
    return 0;
}