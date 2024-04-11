// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int n,a[N];
bool isp( int x ) { 
	if ( x==4 ) return 1;
	for ( int i=2; i*i<=x; i++ )
		if ( x%i==0 ) return 0;
	return 1;
}
bool chk( int p, int d ) {
	int l=n/d;
	for ( int i=0; i<l; i++,p+=d )
		if ( !a[p%n] ) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=3; i<=n; i++ ) {
		if ( n%i!=0 || !isp(i) ) continue;
		for ( int j=0; j<n/i; j++ )
			if ( chk(j,n/i) ) { puts("YES"); return 0; }
	}
	puts("NO");
	return 0;
}