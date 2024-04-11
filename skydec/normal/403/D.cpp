#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define jsb 1000000007
int f[55][1005];
int ans[55][1005];
int c[2005][2005];
int fac[2005];
inline void A(int &x,int y){x+=y;if(x>=jsb)x-=jsb;}
void init()
{
	int N=1000;int K=50;c[0][0]=1;
	rep(i,1,N)
	{
		c[i][0]=c[i][i]=1;
		rep(j,1,i-1)A(c[i][j],c[i-1][j-1]),A(c[i][j],c[i-1][j]);
	}
	f[0][0]=1;
	rep(num,0,N)
	per(k,K,1)
	rep(i,num,N)
	if(k!=0)
	A(f[k][i],f[k-1][i-num]);
	fac[0]=1;rep(i,1,N)fac[i]=fac[i-1]*1ll*i%jsb;
	rep(k,1,K)
	rep(i,0,N)
	rep(j,i,N)
	A(ans[k][j],f[k][i]*1ll*c[j-i][k]%jsb);
}
void work()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,k;scanf("%d%d",&n,&k);if(k>50)k=51;
		printf("%d\n",ans[k][n]*1ll*fac[k]%jsb);
	}
}
int main()
{
	init();
	work();
}