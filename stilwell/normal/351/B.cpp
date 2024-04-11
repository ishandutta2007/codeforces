#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,p[3005],ans;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&p[i]);
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	if(p[i]>p[j])++ans;
	if(ans&1)ans=ans*2-1;
	else ans=ans*2;
	printf("%d\n",ans);
}