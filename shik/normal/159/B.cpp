// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[1010][1010],b[1010],u[N],v[N];
int main()
{
	int n,m,x,y,p=0,q=0;
	scanf("%d%d",&n,&m);
	while ( n-- ) {
		scanf("%d%d",&x,&y);
		a[x][y]++;
		b[y]++;
	}
	for ( int i=0; i<m; i++ ) {
		scanf("%d%d",u+i,v+i);
		if ( a[u[i]][v[i]]>0 ) a[u[i]][v[i]]--,b[v[i]]--,i--,m--,p++,q++;
	}
	for ( int i=0; i<m; i++ ) if ( b[v[i]]>0 ) b[v[i]]--,p++;
	printf("%d %d\n",p,q);
	return 0;
}