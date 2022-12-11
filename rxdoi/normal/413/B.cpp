#include<cstdio>
using namespace std;

const int Maxn=2*10000+19,M=10+19;
int n,m,k,x,y;
int A[Maxn][M],cnt[M],Ans[Maxn];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for (int i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		cnt[y]++;
		Ans[x]--;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) if (A[i][j]) Ans[i]+=cnt[j];
		printf("%d ",Ans[i]);
	}
	printf("\n");
	return 0;
}