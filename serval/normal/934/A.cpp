#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,avoid;
long long a[100],b[100];
long long prod[5005];
int pos[5005];
long long ans;
bool cmp(int x,int y)
{
	return prod[x]>prod[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for (i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			prod[++k]=a[i]*b[j];
			pos[k]=k;
		}
	sort(pos+1,pos+n*m+1,cmp);
	avoid=(pos[1]-1)/m+1;
	ans=(2ll<<31)<<31;
	for (i=1;i<=n;i++)
		if (i!=avoid)
			for (j=1;j<=m;j++)
				if (a[i]*b[j]>ans)
					ans=a[i]*b[j];
	printf("%I64d\n",ans);
	return 0;
}