#include<cstdio>

using namespace std;

int i,j,k,l,m,n,o,p,a[100001],ans,b;

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==i)ans++;
		if(a[a[i]]==i&&!b&&a[i]!=i)ans+=2,b=1;
	}
	if(ans<n&&!b)ans++;
	printf("%d",ans);
}