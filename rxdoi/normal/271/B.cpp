#include<cstdio>
using namespace std;

const int Maxn=1e5+100+19,N=500+19;
int pp[Maxn],A[N][N],sum[N][N];
int n,m,x,Ans=(1<<30)-1;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=2;i<Maxn;i++)
		if (!pp[i])
			for (long long j=1LL*i*i;j<Maxn;j+=i) pp[j]=1;
	pp[1]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			int y=x;while (pp[y]) y++;y-=x;
			A[i][j]=y;
		}
	for (int i=1;i<=n;i++)
	{
		int tmp=0;
		for (int j=1;j<=m;j++) tmp+=A[i][j];
		if (tmp<Ans) Ans=tmp;
	}
	for (int i=1;i<=m;i++)
	{
		int tmp=0;
		for (int j=1;j<=n;j++) tmp+=A[j][i];
		if (tmp<Ans) Ans=tmp;
	}
	printf("%d\n",Ans);
}