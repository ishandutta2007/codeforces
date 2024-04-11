#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,ans;
int a[100005],f[100005],g[100005];

void Max(int &a,int b){if(b>a)a=b;}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	if(a[i]>a[i-1])f[i]=f[i-1]+1;
	else f[i]=1;
	for(i=n;i>=1;--i)
	if(a[i]<a[i+1])g[i]=g[i+1]+1;
	else g[i]=1;
	ans=1;
	for(i=1;i<=n;++i)
	{
		if(i>1)Max(ans,f[i-1]+1);
		if(i<n)Max(ans,g[i+1]+1);
		if(i>1&&i<n&&a[i-1]+1<a[i+1])Max(ans,f[i-1]+1+g[i+1]);
	}
	printf("%d\n",ans);
}