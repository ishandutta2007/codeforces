// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int a[N],b[N];
bool chk( int n, int sml, int m ) {
	for ( int i=0; i<m; i++ ) if ( a[n-m+i]+b[n-i-1]<sml ) return 0;
	return 1;
}
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ ) scanf("%d",b+i);
	sort(a,a+n); sort(b,b+n);
	int s=-1,t=-1,sml=(1<<30);
	for ( int i=0,j=n-1; i<n; i++ ) {
		while ( j>0 && a[i]+b[j-1]>=x ) j--;
		int c=a[i]+b[j];
		if ( x<=c && c<sml ) {
			sml=c;
			s=i; t=j;
		}
	}
	int l=0,r=n;
	while ( l!=r ) {
		int m=(l+r+1)/2;
		if ( chk(n,sml,m) ) l=m;
		else r=m-1;
	}
	printf("%d %d\n",1,l);
	return 0;
}