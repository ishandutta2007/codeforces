#include<algorithm>
#include<string>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
int T,n,a[N];
typedef long long LL;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		LL ans=0;
		rep(i,1,n)
		{
			if(a[i]>=a[i-1]) continue;
			ans+=a[i-1]-a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}