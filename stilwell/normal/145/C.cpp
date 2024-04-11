#include <stdio.h>
#include <stdlib.h>
#include <map>
#define p 1000000007
using namespace std;

int n,m,i,j,k,tot;
int a[100005],b[100005];
long long fac[100005],fac_inv[100005],f[100005],ans;

map<int,int> Hash;

void dfs(int x,int y)
{
	if(y)Hash[x]=++tot;
	if(y==9)return;
	dfs(x*10+4,y+1);
	dfs(x*10+7,y+1);
}

int calc(int x)
{
	for(int y=x;y;y/=10)
	if(y%10!=4&&y%10!=7)
	return 0;
	return Hash[x];
}

long long Power(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b%2)ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}

int main()
{
	dfs(0,0);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i]=calc(a[i]);
		++b[a[i]];
	}
	f[0]=1;
	for(i=1;i<=tot;++i)
	for(j=i;j>=1;--j)
	f[j]=(f[j]+f[j-1]*b[i])%p;
	fac[0]=fac_inv[0]=1;
	for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%p,fac_inv[i]=Power(fac[i],p-2);
	for(i=0;i<=tot&&i<=m;++i)
	if(b[0]>=m-i)ans=(ans+f[i]*fac[b[0]]%p*fac_inv[m-i]%p*fac_inv[b[0]-m+i]%p)%p;
	printf("%I64d\n",ans);
}