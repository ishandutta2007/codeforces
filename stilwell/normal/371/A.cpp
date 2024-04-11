#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int a[100005];
int b[100005][3];
int n,k,i,j,ans;

int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)++b[i%k][a[i]];
	for(i=0;i<k;++i)ans+=min(b[i][1],b[i][2]);
	printf("%d\n",ans);
}