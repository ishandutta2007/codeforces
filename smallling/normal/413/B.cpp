#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,k,a[20001][11],num[11],ans[20001],o,p;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&o,&p);
		num[p]++;
		ans[o]--;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j])ans[i]+=num[j];
	for(int i=1;i<=n;i++)
		printf("%d ",max(ans[i],0));
}