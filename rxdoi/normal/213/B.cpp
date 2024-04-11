#include<cstdio>
using namespace std;

const int Maxn=100+19,Mod=1e9+7;
int Len,C[Maxn][Maxn],A[10];
long long F[Maxn][10],Ans;

int main()
{
	scanf("%d",&Len);
	for (int i=0;i<=9;i++) scanf("%d",&A[i]);
	for (int L=0;L<=Len;L++)
	{
		C[L][0]=1;
		for (int i=1;i<=L;i++) C[L][i]=(C[L-1][i]+C[L-1][i-1])%Mod;
	}
	for (int L=0;L<=Len;L++)
	{
		F[L][9]=(L>=A[9]);
		for (int i=8;i>=1;i--)
			for (int j=A[i];j<=L;j++)
				(F[L][i]+=1LL*F[L-j][i+1]*C[L][j])%=Mod;
		for (int j=A[0];j<=L;j++)
			(F[L][0]+=1LL*F[L-j][1]*C[L-1][j])%=Mod;
	}
	for (int i=1;i<=Len;i++) (Ans+=F[i][0])%=Mod;
	printf("%I64d\n",Ans);
}