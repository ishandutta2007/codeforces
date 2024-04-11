// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int p[1000],q[1000];
int main()
{
	int x,t,a,b,da,db;
	scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db);
	for ( int i=0; i<t; i++ ) p[i]=a-i*da;
	for ( int i=0; i<t; i++ ) q[i]=b-i*db;
	p[t]=q[t]=0;
	for ( int i=0; i<=t; i++ ) for ( int j=0; j<=t; j++ ) if ( p[i]+q[j]==x ) return puts("YES"),0;
	puts("NO");
	return 0;
}