#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,p,g,tot,i,j,k,ans;
int d[100005],a[100005],b[100005],f[100005];
bool use[100005];

int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int Power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(long long)ans*a%p;
		a=(long long)a*a%p;
		b>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(g=p-1,i=1;i<=m;++i)scanf("%d",&k),g=gcd(k,g);
	for(i=1;i*i<p;++i)
	if((p-1)%i==0)
	{
		d[++tot]=i;
		if((p-1)/i!=i)d[++tot]=(p-1)/i;
	}
	sort(d+1,d+tot+1);
	for(i=1;i<=tot;++i)
	{
		f[i]=d[i];
		for(j=1;j<i;++j)if(d[i]%d[j]==0)f[i]-=f[j];
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=tot;++j)
	if(Power(a[i],(long long)g*d[j]%(p-1))==1)
	{
		use[j]=true;
		break;
	}
	for(i=1;i<=tot;++i)
	if(use[i])
	for(j=1;j<i;++j)
	if(d[i]%d[j]==0)
	use[j]=true;
	for(i=1;i<=tot;++i)if(use[i])ans+=f[i];
	printf("%d\n",ans);
}