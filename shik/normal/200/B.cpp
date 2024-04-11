// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,s=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%d",&x);
		s+=x;
	}
	double ans=1.0*s/n;
	printf("%.9f\n",ans);
	return 0;
}