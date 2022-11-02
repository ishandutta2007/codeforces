#include<cstdio>

using namespace std;

int ans,i,j,k,l,m,n,o,p;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&o);
		if(i==j)ans^=o;
	}
	scanf("%d",&p);
	for(i=1;i<=p;i++)
	{
		scanf("%d",&l);
		if(l==1||l==2)
		{
			scanf("%d",&o);
			ans^=1;
		}
		else printf("%d",ans);
	}
}