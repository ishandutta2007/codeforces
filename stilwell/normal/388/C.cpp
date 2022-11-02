#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,tot,i,j,k,sum,ans;
int a[1005],b[1005];

inline bool cmp(const int &a,const int &b){return a>b;}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&m);
		for(j=1;j<=m;++j)scanf("%d",&a[j]);
		for(j=1;j<=m;++j)sum+=a[j];
		for(j=m/2;j>=1;--j)ans+=a[j];
		if(m%2)b[++tot]=a[m/2+m%2];
	}
	sort(b+1,b+tot+1,cmp);
	for(i=1;i<=tot;++i)if(i%2)ans+=b[i];
	printf("%d %d\n",ans,sum-ans);
}