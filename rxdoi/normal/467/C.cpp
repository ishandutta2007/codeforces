#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
const int Maxn=5000+19;
int n,m,k;
LL A[Maxn],F[Maxn][Maxn],G[Maxn],Ans;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%I64d",&A[i]),A[i]+=A[i-1];
	for (int i=1;i<=k;i++)
	{
		for (int j=n;j>=i*m;j--) F[i][j]=G[j-m]+A[j]-A[j-m];
		for (int j=1;j<=n;j++) G[j]=max(G[j-1],F[i][j]);
	}
	for (int i=1;i<=n;i++) Ans=max(Ans,F[k][i]);
	printf("%I64d\n",Ans);
}