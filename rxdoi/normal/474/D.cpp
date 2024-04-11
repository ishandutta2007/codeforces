#include<cstdio>
using namespace std;

const int Maxn=1e5+19,Mod=1e9+7;
int F[Maxn][2],C[Maxn],t,k,L,R;
//0 is W,1 is R

int main()
{
	scanf("%d%d",&t,&k);
	F[0][1]=1;
	for (int i=1;i<=1e5;i++) 
	{
		F[i][1]=(F[i-1][0]+F[i-1][1])%Mod;
		if (i>=k) F[i][0]=(F[i-k][0]+F[i-k][1])%Mod;
	}
	for (int i=1;i<=1e5;i++) C[i]=((C[i-1]+F[i][0])%Mod+F[i][1])%Mod;
	while (t--)
	{
		scanf("%d%d",&L,&R);
		printf("%d\n",(C[R]%Mod-C[L-1]%Mod+Mod)%Mod);
	}
}