// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,x[N],y[N];
LL cal( int *s ) {
	LL ret=0,sum=0;
	for ( int i=0; i<n; i++ ) sum+=s[i];
	for ( int i=0; i<n; i++ ) ret+=1LL*(n-1)*s[i]*s[i]-s[i]*(sum-s[i]);
	return ret;
}
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d%d",x+i,y+i);
	printf("%I64d\n",cal(x)+cal(y));
	return 0;
}