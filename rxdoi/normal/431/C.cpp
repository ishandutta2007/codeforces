#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=300+19,Mod=1000000007;
int n,k,d,Ans=0,F[Maxn][Maxn];

int main()
{
	scanf("%d%d%d",&n,&k,&d);
	F[0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<=k;j++)
			for (int L=1;L<=k;L++)
				F[i+L][max(j,L)]+=F[i][j],F[i+L][max(j,L)]%=Mod;
	for (int i=d;i<=k;i++)
		Ans+=F[n][i],Ans%=Mod;
	printf("%d\n",Ans);
	return 0;
}