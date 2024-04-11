// by shik
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,vis[18][1<<18];
double a[18][18],p[18][1<<18];
double go( int x, int s ) {
	if ( vis[x][s] ) return p[x][s];
	vis[x][s]=1;
	if ( ((s>>x)&1)==0 ) return p[x][s]=0;
	if ( s==(1<<x) ) return p[x][s]=1;
	int i,j,k=0,lst[18]; double r=0;
	for ( i=0; i<n; i++ )
		if ( (s>>i)&1 ) lst[k++]=i;
	for ( i=0; i<k; i++ )
		for ( j=i+1; j<k; j++ )
			r+=a[lst[i]][lst[j]]*go(x,s-(1<<lst[j]))+a[lst[j]][lst[i]]*go(x,s-(1<<lst[i]));
	return p[x][s]=r/(k*(k-1)/2);
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for ( i=0; i<n; i++ )
		for ( j=0; j<n; j++ )
			scanf("%lf",&a[i][j]);
	for ( i=0; i<n; i++ ) printf("%.6f%c",go(i,(1<<n)-1),i==n-1?'\n':' ');
	return 0;
}