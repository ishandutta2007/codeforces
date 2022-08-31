#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
#define MAXN 1005
int n,m;
LL djx[2*MAXN][2*MAXN],lk[MAXN][MAXN],ks[MAXN][MAXN],flow[MAXN][MAXN],sum[MAXN][MAXN];
struct Worker
{
	LL a[MAXN][MAXN];
	LL f[MAXN][MAXN];
	int k;
	void init()
	{
		memset(djx,0,sizeof djx);
		memset(lk,0,sizeof lk);
		memset(ks,0,sizeof ks);
		memset(flow,0,sizeof flow);
		memset(f,0,sizeof f);
		memset(sum,0,sizeof sum);
	}
	void getdjx()
	{
		for(int i=1;i<=n+m;i++)
		for(int j=1;j<i&&j<=n;j++)
		if(i-j<=m&&i-j>0)
		djx[i][j]=djx[i][j-1]+a[j][i-j];
	}
	void getks()
	{
		rep(i,1,n)
		{
			rep(j,1,k)ks[i][k]+=a[i][j];
			rep(j,k+1,m)ks[i][j]=ks[i][j-1]+a[i][j]-a[i][j-k];
		}
	}
	void getlk()
	{
		rep(i,1,n)
		{
			rep(j,1,k)lk[i][k]+=j*1ll*a[i][j];
			rep(j,k+1,m)lk[i][j]=lk[i][j-1]-ks[i][j-1]+k*1ll*a[i][j];
		}
	}
	void getsum(){rep(i,1,n)rep(j,1,m)sum[i][j]=sum[i][j-1]+a[i][j];}
	void getflow()
	{
		rep(j,k,m)
		{
			rep(i,1,k)flow[k][j]+=sum[i][j]-sum[i][j-i];
			rep(i,k+1,n)flow[i][j]=flow[i-1][j]-(djx[i-k+j][i-1]-djx[i-k+j][i-k-1])+ks[i][j];
		}
	}
	void getf()
	{
		rep(j,k,m)
		{
			rep(i,1,k)f[k][j]+=i*1ll*(djx[i+j][k]-djx[i+j][i-1]);
			rep(i,k+1,n)f[i][j]=f[i-1][j]-flow[i-1][j]+lk[i][j];
		}
	}
	void work()
	{
		init();
		getdjx();
		getks();
		getlk();
		getsum();
		getflow();
		getf();
	}
}dp1,dp2,dp3,dp4;
int k;
LL a[MAXN][MAXN];
void tp1()
{
	int x,y;LL ans;ans=-1;
	rep(i,1,n)rep(j,1,m)if(a[i][j]>ans){ans=a[i][j];x=i;y=j;}
	printf("%d %d\n",x,y);
}
void tp2()
{
	int x,y;LL ans;ans=-1;
	rep(i,2,n-1)rep(j,2,m-1)if(a[i][j]*2+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1]>ans){ans=a[i][j]*2+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1];x=i;y=j;}
	printf("%d %d\n",x,y);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)rep(j,1,m)scanf("%I64d",&a[i][j]);
	if(k==1){tp1();return 0;}
	if(k==2){tp2();return 0;}
	rep(i,1,n)rep(j,1,m)dp1.a[i][j]=a[i][j];dp1.k=k;dp1.work();
	rep(i,1,n)rep(j,1,m)dp2.a[i][m+1-j]=a[i][j];dp2.k=k-1;dp2.work();
	rep(i,1,n)rep(j,1,m)dp3.a[n-i+1][m+1-j]=a[i][j];dp3.k=k-2;dp3.work();
	rep(i,1,n)rep(j,1,m)dp4.a[n-i+1][j]=a[i][j];dp4.k=k-1;dp4.work();
	LL ans=-1;int x,y;
	rep(i,k,n-k+1)rep(j,k,m-k+1)
	{
		LL res=0;
		res+=dp1.f[i][j];
		res+=dp2.f[i][m+1-(j+1)];
		res+=dp3.f[n+1-(i+1)][m+1-(j+1)];
		res+=dp4.f[n+1-(i+1)][j];
		if(res>ans)ans=res,x=i,y=j;
	}
	printf("%d %d\n",x,y);
	return 0;
}