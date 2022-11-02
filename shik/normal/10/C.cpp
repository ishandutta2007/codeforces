// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,c[9]={};
	long long ans=0;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) c[i%9]++;
	for ( int i=0; i<9; i++ ) for ( int j=0; j<9; j++ ) ans+=1LL*c[i]*c[j]*c[i*j%9];
	for ( int i=1; i<=n; i++ ) ans-=n/i;
	printf("%I64d\n",ans);
	return 0;
}