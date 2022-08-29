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
typedef long long LL;
LL f[1<<18][105];
int tw[19],dig[19];int n,m;LL uk;
inline LL A(LL &x,LL y){x+=y;}
int TW(int x)
{
	int u=0;
	while(x){u++;x/=2;}
	return u-1;
}
int main()
{
	scanf("%I64d",&uk);
	while(uk)
	{
		dig[++n]=uk%10;
		uk/=10;
	}
	scanf("%d",&m);
	tw[0]=1;for(int i=1;i<=n;i++)tw[i]=tw[i-1]*2;
	f[(1<<n)-1][0]=1;
	per(i,((1<<n)-1),1)
	rep(j,0,m-1)
	{
		int u=i;
		while(u)
		{
			int s=TW(u&-u)+1;
			if(dig[s]==0&&i==((1<<n)-1)){u-=(u&-u);continue;}
			A(f[i-(u&-u)][((j*10%m)+dig[s])%m],f[i][j]);
			u-=(u&-u);
		}
	}
	rep(i,0,9)
	{
		int u=0;
		rep(j,1,n)if(dig[j]==i){u++;f[0][0]/=u;}
	}
	printf("%I64d\n",f[0][0]);
}