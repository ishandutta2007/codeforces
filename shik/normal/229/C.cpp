// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 1000010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
long long d[N];
int main()
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d",&a,&b);
		d[a]++; d[b]++;
	}
	long long ans=1LL*n*(n-1)*(n-2)/6,tmt=0;
	for ( int i=1; i<=n; i++ ) tmt+=d[i]*(n-d[i]-1);
	ans-=tmt/2;
	cout<<ans<<endl;
	return 0;
}