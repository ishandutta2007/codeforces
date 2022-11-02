#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
using namespace std;

int a[5005],b[5005],c[5005];
int n,m,i,j,k,ans,S,g,flag;

map <int,bool> Hash;

int calc(int k)
{
	int i,j,S,ans=0;
	S=(int)sqrt(k);
	for(j=2;j<=S;++j)
	while(k%j==0)
	{
		
		k/=j;
		if(Hash[j])--ans;
		else ++ans;
	}
	if(k!=1)
	{
		if(Hash[k])--ans;
		else ++ans;
	}
	return ans;
}
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=m;++i)scanf("%d",&b[i]),Hash[b[i]]=true;
	for(i=1;i<=n;++i)ans+=calc(a[i]);
	for(i=1;i<=n;++i)
	{
		g=gcd(a[i],g);
		c[i]=-calc(g);
	}
	for(i=n;i>=1;--i)
	{
		c[i]-=flag;
		if(c[i]>0)ans+=c[i]*i,flag+=c[i];
	}
	printf("%d\n",ans);
}