#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ans;
int a[10005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	ans=a[n]-a[1];
	for(i=n+1;i<=m;++i)if(a[i]-a[i-n+1]<ans)ans=a[i]-a[i-n+1];
	printf("%d\n",ans);
}