#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=505;
typedef long long LL;
int n,m,mod;
LL c[N][N],f1[N],f2[N],f3[N][N],f4[N][N];

void dp()
{
	f1[0]=f3[0][0]=1;
	rep(i,1,n)
	{
		rep(j,1,i)
		{
			f1[i]=(f1[i]+f1[j-1]*f1[i-j]%mod*c[i-1][j-1]%mod*(i+1))%mod;
			f2[i]=(f2[i]+(f2[j-1]*f1[i-j]+f2[i-j]*f1[j-1])%mod*(i+1)%mod*c[i-1][j-1])%mod;
			f2[i]=(f2[i]+(c[j][2]+c[i-j+1][2])*f1[j-1]%mod*f1[i-j]%mod*c[i-1][j-1])%mod;
		}
		f3[i][0]=1,f3[i][i]=f1[i],f4[i][i]=f2[i];
		rep(j,1,i-1)
		{
			f3[i][j]=f3[i-1][j];
			f4[i][j]=f4[i-1][j];
			rep(l,1,j)
			{
				f3[i][j]=(f3[i][j]+f1[l]*f3[i-l-1][j-l]%mod*c[j][l])%mod;
				f4[i][j]=(f4[i][j]+(f1[l]*f4[i-l-1][j-l]+f2[l]*f3[i-l-1][j-l])%mod*c[j][l])%mod;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	rep(i,0,n) c[i][0]=c[i][i]=1;
	rep(i,1,n) rep(j,1,i-1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	dp();
	printf("%lld\n",f4[n][m]);
	return 0;
}