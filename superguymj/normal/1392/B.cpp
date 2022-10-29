#include<algorithm>
#include<string>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,T;
typedef long long LL;
LL k,a[200005];
const LL INF=10000000000ll;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k),--k;
		rep(i,1,n) scanf("%lld",&a[i]);
		LL mx=-INF;
		rep(i,1,n) mx=max(mx,a[i]);
		rep(i,1,n) a[i]=mx-a[i];
		if(k&1)
		{
			mx=-INF;
			rep(i,1,n) mx=max(mx,a[i]);
			rep(i,1,n) a[i]=mx-a[i];
		}
		rep(i,1,n) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}