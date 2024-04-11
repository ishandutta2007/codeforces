#include<cstdio>
#include<algorithm>
using namespace std;

const int Mod=1e9+7;
int g[53][1003][1003],f[53][1003];
int C[1053][53];
int n,k,Q;

int main()
{
	g[0][0][1]=1;
	for (int i=0,Fac=1;i<51;i++,Fac=(1LL*Fac*i)%Mod)
		for (int j=0;j<=1001;j++)
		{
			int _s=0;
			for (int k=1;j+k<=1001;k++) 
			{
				(_s+=g[i][j][k])%=Mod;
				(g[i+1][j+k][k+1]+=_s)%=Mod;
			}
			for (int k=1;k<=1001;k++) (f[i][j]+=g[i][j][k])%=Mod;
			f[i][j]=1LL*f[i][j]*Fac%Mod;
		}
	for (int i=0;i<=1051;i++)
	{
		C[i][0]=1;
		for (int j=1,_=min(51,i);j<=_;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d",&n,&k);
		if (k>51) {puts("0");continue;}
		int Ans=0;
		for (int sum=0;sum<=n;sum++) (Ans+=1LL*f[k][sum]*C[n-sum+k][k]%Mod)%=Mod;
		printf("%d\n",Ans);
	}
}