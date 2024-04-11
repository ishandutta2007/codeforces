#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int Maxn=1000+19;
int F[Maxn],L[6][Maxn],A[6][Maxn],n,k,Ans;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++) 
		{
			scanf("%d",&A[i][j]);
			L[i][A[i][j]]=j;
		}
	for (int i=1;i<=n;i++)
	{
		int x=A[1][i];
		F[x]=1;
		for (int j=1;j<i;j++)
		{
			int y=A[1][j],Flag=1;
			if (F[y]+1<=F[x]) continue;
			for (int p=2;p<=k;p++)
				if (L[p][y]>L[p][x]) Flag=0;
			if (Flag) F[x]=F[y]+1;
		}
		if (F[x]>Ans) Ans=F[x];
	}
	printf("%d\n",Ans);
}