// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k,b[1010];
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) scanf("%d",b+i);
	for ( int i=1; i<=n; i++ ) {
		int p=find(b+1,b+n+1,0)-b;
		printf("%d%c",p,i==n?'\n':' ');
		b[p]=-1;
		for ( int j=p-k; j>0; j-- ) b[j]--;
	}
	return 0;
}