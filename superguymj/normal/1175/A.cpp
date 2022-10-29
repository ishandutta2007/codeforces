#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int T;
long long n,k,ans;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		while(n) ans+=(n%k)+1,n/=k;
		printf("%lld\n",ans-1),ans=0;
	}
	return 0;
}