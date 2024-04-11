#include<cstdio>

#define N 1010

#define mo 1000000007

using namespace std;

int n,k;
int ans[N],fac[N],C[N][N],f[N][N][4];

int main()
{
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=mo)C[i][j]-=mo;
		}
	}
	//0 i,i+1;1 i;2 i+1;3 i,i+1 
	f[1][0][0]=1;
	f[1][1][2]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			for(int x=0;x<4;x++)
				if(f[i][j][x])
				{
					if(x%2==0)
					{
						f[i+1][j+1][x>>1]+=f[i][j][x];
						if(f[i+1][j+1][x>>1]>=mo)
							f[i+1][j+1][x>>1]-=mo;
					}
					if(i+2<=n)
					{
						f[i+1][j+1][(x>>1)+2]+=f[i][j][x];
						if(f[i+1][j+1][(x>>1)+2]>=mo)
							f[i+1][j+1][(x>>1)+2]-=mo;
					}
					f[i+1][j][x>>1]+=f[i][j][x];
					if(f[i+1][j][x>>1]>=mo)
						f[i+1][j][x>>1]-=mo;
				}
	}
	for(int i=n;i>=0;i--)
	{
		ans[i]=f[n][i][0]+f[n][i][1];
		if(ans[i]>=mo)ans[i]-=mo;
		ans[i]=1ll*ans[i]*fac[n-i]%mo;
		for(int j=i+1;j<=n;j++)
		{
			ans[i]-=1ll*ans[j]*C[j][i]%mo;
			if(ans[i]<0)ans[i]+=mo;
		}
	}
	printf("%d\n",ans[k]);
}