#include <cstdio>
using namespace std;
int n,i,j,s,f,ans,ret;
int a[200005];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=n+1;i<=n+n;i++)
		a[i]=a[i-n];
	for (i=1;i<=n+n;i++)
		a[i]+=a[i-1];
	scanf("%d%d",&s,&f);
	j=f-s;
	for (i=1;i<=n+n-j+1;i++)
		if (a[i+j-1]-a[i-1]>ans||(a[i+j-1]-a[i-1]==ans&&(s-i+n+n)%n+1<ret))
		{
			ans=a[i+j-1]-a[i-1];
			ret=(s-i+n+n)%n+1;
		}
	printf("%d\n",ret);
	return 0;
}