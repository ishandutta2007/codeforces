// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
typedef long long LL;
LL cal( LL n ) { return n*(n-1)/2; }
int id[N];
void output( int a, int b ) { printf("%d %d\n",id[a],id[b]); }
int main()
{
	int n,m,v,i,j;
	scanf("%d%d%d",&n,&m,&v);
	if ( cal(n-1)+1<m || m<n-1 ) puts("-1");
	else {
		for ( i=1; i<=n; i++ ) id[i]=i;
		swap(id[v],id[n-1]);
		for ( i=1; i<n; i++ ) output(i,i+1);
		m-=n-1;
		for ( i=1; i<=n-1&&m>0; i++ )
			for ( j=i+2; j<=n-1&&m>0; j++ ) {
				output(i,j);
				m--;
			}
	}
	return 0;
}