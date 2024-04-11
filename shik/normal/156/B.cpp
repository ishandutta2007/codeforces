// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,m,a[N],nx,ny,x[N],y[N],z[N],cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ )
		if ( a[i]>0 ) nx++,x[a[i]]++;
		else ny++,y[-a[i]]++;
	for ( int i=1; i<=n; i++ ) if ( x[i]+ny-y[i]==m ) z[i]=1,cnt++;
	if ( cnt==1 ) {
		for ( int i=1; i<=n; i++ ) {
			if ( a[i]>0 ) puts(z[a[i]]?"Truth":"Lie");
			else puts(z[-a[i]]?"Lie":"Truth");
		}
	} else {
		for ( int i=1; i<=n; i++ ) {
			if ( a[i]>0 ) puts(z[a[i]]?"Not defined":"Lie");
			else if ( a[i]<0 ) puts(z[-a[i]]?"Not defined":"Truth");
		}
	}
	return 0;
}