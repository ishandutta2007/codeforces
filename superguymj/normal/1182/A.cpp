#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n;
typedef long long LL;

int main()
{
	scanf("%d",&n);
	if(n&1) return puts("0"),0;
	LL ans=1;
	rep(i,1,n/2) ans=ans*2;
	printf("%lld\n",ans);
	return 0;
}