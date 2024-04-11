// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL f( LL a, LL b, LL c ) {
	if ( (b+c)%2==1 ) return a+b+c-1;
	return max(b,c);
}
int main()
{
	LL a,b,c;
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	LL ans=a+b+c-1;
	ans=min(ans,f(a,b,c));
	ans=min(ans,f(b,a,c));
	ans=min(ans,f(c,a,b));
	printf("%I64d\n",ans);
	return 0;
}