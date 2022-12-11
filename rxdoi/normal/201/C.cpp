#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;
const LL Maxn=1e5+19;
LL A[Maxn],B[Maxn],F[Maxn][2][2];
LL n,Ans;

int main()
{
	scanf("%I64d",&n);n--;
	for (LL i=1;i<=n;i++) scanf("%I64d",&A[i]),B[i]=A[i];
	for (LL i=1;i<=n+1;i++)
	{
		if (!A[i-1]) continue;
		if (A[i-1]%2==0) 
		{
			F[i][0][1]=F[i-1][0][1]+A[i-1];
			F[i][0][0]=F[i-1][0][0]+A[i-1]-1;
		} else
		{
			F[i][0][1]=(A[i-1]==1?0:F[i-1][0][1]+A[i-1]-1);
			F[i][0][0]=F[i-1][0][0]+A[i-1];
		}
		F[i][0][0]=max(F[i][0][0],F[i][0][1]);
	}
	for (LL i=n+1;i>=1;i--)
	{
		if (!A[i]) continue;
		if (A[i]%2==0) 
		{
			F[i][1][1]=F[i+1][1][1]+A[i];
			F[i][1][0]=F[i+1][1][0]+A[i]-1;
		} else
		{
			F[i][1][1]=(A[i]==1?0:F[i+1][1][1]+A[i]-1);
			F[i][1][0]=F[i+1][1][0]+A[i];
		}
		F[i][1][0]=max(F[i][1][0],F[i][1][1]);
	}
	for (LL i=1;i<=n+1;i++)
	{
		Ans=max(Ans,F[i][0][1]+F[i][1][0]);
		Ans=max(Ans,F[i][1][1]+F[i][0][0]);
	}
	printf("%I64d\n",Ans);
}