#include<cstdio>
#define _new(x) ((x)+10000)
using namespace std;

const int Maxn=1000+19,Len=10000+19,Mod=1e9+7;
int F[Maxn][Len*2],A,n,Ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&A);
		F[i][_new(A)]=F[i][_new(-A)]=1;
		for (int j=-10000;j<=10000;j++)
		{
			(F[i][_new(j+A)]+=F[i-1][_new(j)])%=Mod;
			(F[i][_new(j-A)]+=F[i-1][_new(j)])%=Mod;
		}
		(Ans+=F[i][_new(0)])%=Mod;
	}
	printf("%d\n",Ans);
}