#include <iostream>
#define mod 998244353
using namespace std;
int a[30],F[405][205][2][2],f[405][205][205][3][3];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	long long ans=26*26;
	for(int i=1;i<=n-2;i++) ans=ans*25%mod;
	F[2][2][1][1]=1;
	F[2][1][0][1]=25;
	F[2][1][1][0]=25;
	F[2][0][0][0]=625;
	int X=min(n/2+2,n);
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int l=0;l<=X;l++)
				{
					if(j) F[i][l][k][0]=(F[i][l][k][0]+(long long)F[i-1][l][j][k]*25)%mod;
					else
					{
						F[i][l][k][0]=(F[i][l][k][0]+(long long)F[i-1][l][j][k]*24)%mod;
						F[i][l+1][k][1]=(F[i][l+1][k][1]+F[i-1][l][j][k])%mod;
					}
				}
			}
		}
	}
	f[2][2][0][1][1]=1;
	f[2][0][2][2][2]=1;
	f[2][1][1][1][2]=1;
	f[2][1][1][2][1]=1;
	f[2][1][0][0][1]=24;
	f[2][1][0][1][0]=24;
	f[2][0][1][0][2]=24;
	f[2][0][1][2][0]=24;
	f[2][0][0][0][0]=576;
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			for(int k=0;k<=2;k++)
			{
				for(int l=0;l<=X;l++)
				{
					for(int m=0;m<=X;m++)
					{
						if(j==0) f[i][l][m][k][0]=(f[i][l][m][k][0]+(long long)f[i-1][l][m][j][k]*23)%mod,
						f[i][l+1][m][k][1]=(f[i][l+1][m][k][1]+f[i-1][l][m][j][k])%mod,
						f[i][l][m+1][k][2]=(f[i][l][m+1][k][2]+f[i-1][l][m][j][k])%mod;
						if(j==1) f[i][l][m][k][0]=(f[i][l][m][k][0]+(long long)f[i-1][l][m][j][k]*24)%mod,
						f[i][l][m+1][k][2]=(f[i][l][m+1][k][2]+f[i-1][l][m][j][k])%mod;
						if(j==2) f[i][l][m][k][0]=(f[i][l][m][k][0]+(long long)f[i-1][l][m][j][k]*24)%mod,
						f[i][l+1][m][k][1]=(f[i][l+1][m][k][1]+f[i-1][l][m][j][k])%mod;
					}
				}
			}
		}
	}
	for(int i=1;i<=26;i++)
		cin >> a[i];
	for(int i=1;i<=26;i++)
	{
		for(int j=a[i]+1;j<=X;j++)
			ans-=(long long)F[n][j][0][0]+F[n][j][0][1]+F[n][j][1][0]+F[n][j][1][1];
	}
	for(int i=1;i<=26;i++)
	{
		for(int k=i+1;k<=26;k++)
		{
			for(int j=a[i]+1;j<=X;j++)
				for(int l=a[k]+1;l<=X;l++)
					ans+=(long long)f[n][j][l][0][0]+f[n][j][l][0][1]+f[n][j][l][0][2],
					ans+=(long long)f[n][j][l][1][0]+f[n][j][l][1][1]+f[n][j][l][1][2],
					ans+=(long long)f[n][j][l][2][0]+f[n][j][l][2][1]+f[n][j][l][2][2],ans%=mod;
		}
	}
	ans%=mod,ans+=mod,ans%=mod;
	cout << ans;
	return 0;
}