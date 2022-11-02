#include<cstdio>

#define N 2010
#define mo 1000000007

using namespace std;

int n,m,ans,nowsum;
int f[N][N],sf[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int j=0;j<=m-2;j++)
			f[1][j]=1;
	for(int i=2;i<=n;i++)
	{
		nowsum=0;
		for(int j=0;j<=m-2;j++)
		{
			nowsum+=f[i-1][j];
			if(nowsum>=mo)nowsum-=mo;
			f[i][j]=f[i][j-1]+nowsum;
			if(f[i][j]>=mo)f[i][j]-=mo;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m-2;j++)
		{
			sf[i][j]=sf[i-1][j]+f[i][j];
			if(sf[i][j]>=mo)sf[i][j]-=mo;
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m-2;j++)
		{
			ans+=1ll*sf[i][j]*f[n-i+1][j]%mo*(m-j-1)%mo;
			if(ans>=mo)ans-=mo;
		}
	printf("%d",ans);
}