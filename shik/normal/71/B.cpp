// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,t,a[110];
bool chk() {
	int s=0,i;
	for ( i=1; i<=n; i++ ) s+=a[i];
	if ( 1.0*s/(n*k)<=t/100.0 && t/100.0<1.0*(s+1)/(n*k) ) return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&k,&t);
	for ( int i=1; i<=n; i++ )
		for ( int j=0; j<=k; j++ ) {
			a[i]=j;
			if ( chk() ) {
				for ( int x=1; x<=n; x++ ) printf("%d%c",a[x],x==n?'\n':' ');
				return 0;
			}
		}
	return 0;
}