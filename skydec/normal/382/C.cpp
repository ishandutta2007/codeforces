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
#define MAXN 110000
int a[MAXN];
int n;
int ans[MAXN];
bool same(){rep(i,2,n)if(a[i]!=a[i-1])return 0;return 1;}
bool deltasame(){rep(i,3,n)if(a[i]-a[i-1]!=a[i-1]-a[i-2])return 0;return 1;}
void work()
{
	int Min,Max;Min=2100000000;Max=-2100000000;int c1,c2;c1=c2=0;
	rep(i,2,n)
	{
		Min=min(Min,a[i]-a[i-1]);
		Max=max(Max,a[i]-a[i-1]);
	}
	rep(i,2,n)
	if(a[i]-a[i-1]==Min)c1++;
	else if(a[i]-a[i-1]==Max)c2++;
	else {printf("0\n");return;}
	if(c1!=1&&c2!=1)
	{
		printf("0\n");
		return;
	}
	if(c1==1)
	{
		if(Max*2!=Min){a[0]=1;}else
		{
			printf("1\n");rep(i,2,n)if(a[i]-a[i-1]==Min)printf("%d\n",(a[i]+a[i-1])/2);
			return;
		}
	}
	if(c2==1)
	{
		if(Min*2!=Max){printf("0\n");return;}
		printf("1\n");rep(i,2,n)if(a[i]-a[i-1]==Max)printf("%d\n",(a[i]+a[i-1])/2);
		return;
	}
	printf("0\n");
}
int main()
{
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);sort(a+1,a+1+n);
	if(n==1){printf("-1");return 0;}
	if(same())
	{
		printf("%d\n%d\n",1,a[1]);
		return 0;
	}
	if(n==2&&((a[1]+a[2])%2==0))
	{
		ans[1]=(a[1]+a[2])/2;
		ans[2]=2*a[1]-a[2];
		ans[3]=2*a[2]-a[1];
		sort(ans+1,ans+1+3);
		printf("3\n");
		rep(i,1,3)printf("%d ",ans[i]);
		return 0;
	}
	if(deltasame())
	{
		printf("%d\n%d %d\n",2,min(2*a[1]-a[2],a[n]*2-a[n-1]),max(2*a[1]-a[2],a[n]*2-a[n-1]));
		return 0;
	}
	work();
	return 0;
}