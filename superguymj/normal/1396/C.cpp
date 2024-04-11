#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<queue>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=1000005;
const LL INF=1000000000000000000ll;
int n;
LL r1,r2,r3,d,a[N],f[N][4];
LL p1[N],p2[N],ans;

LL query1(LL x)
{
	return r3+r1*x;
}

LL query2(LL x)
{
	return min(r2+r1,r1*(x+2));
}

int main()
{
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,n) p1[i]=query1(a[i]),p2[i]=query2(a[i]);
	f[1][1]=0;
	f[1][2]=INF;
	f[1][3]=INF;
	rep(i,2,n)
	{
		f[i][1]=min(f[i-1][1]+p1[i-1],f[i-1][3]+p2[i-1])+d;
		f[i][2]=min(f[i-1][1]+p2[i-1],f[i-1][2]+p2[i-1])+2*d;
		f[i][3]=min(f[i-1][1]+p2[i-1],f[i-1][3]+p2[i-1])+3*d;
	}	
	ans=min(f[n][1]+p1[n],min(f[n][2]+p1[n],f[n][3]+p2[n]));
	printf("%lld\n",ans);
	return 0;
}