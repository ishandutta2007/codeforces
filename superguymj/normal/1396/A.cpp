#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n;
LL a[N],ans1[N],ans2[N];

void exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) {y=0,x=1; return;}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	if(n==1)
	{
		printf("%d %d\n",1,1);
		printf("%lld\n",-a[1]);
		printf("%d %d\n",1,1);
		printf("%lld\n",-1ll);
		printf("%d %d\n",1,1);
		printf("%lld\n",1ll);
		return 0;
	}
	rep(i,1,n-1)
	{
		exgcd(n,n-1,ans1[i],ans2[i]);
		ans1[i]*=a[i]*n,ans2[i]*=a[i]*(n-1);
	}
	printf("%d %d\n",1,n);
	rep(i,1,n) printf("%lld ",-ans1[i]);
	puts("");
	printf("%d %d\n",1,n-1);
	rep(i,1,n-1) printf("%lld ",-ans2[i]);
	puts("");
	printf("%d %d\n",n,n);
	printf("%lld\n",-a[n]);
	return 0;
}