#include <cstdio>
using namespace std;
int n,k,i,ans;
bool vis[100005];
int a[100005],g;
int gcd(int u,int v)
{
	return u%v==0?v:gcd(v,u%v);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=k;
		if (a[i]==0)
			a[i]=k;
	}
	g=k;
	for (i=1;i<=n;i++)
		g=gcd(g,a[i]);
	printf("%d\n",k/g);
	for (i=0;i<k;i+=g)
		printf(i+g<k?"%d ":"%d\n",i);
	return 0;
}