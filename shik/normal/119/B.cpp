// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k,a[110],v[110]={};
	scanf("%d%d",&n,&k);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	int q,c=0,x[110],mx=0,mi=100000;
	scanf("%d",&q);
	while ( q-- ) {
		for ( int i=0; i<n/k; i++ ) scanf("%d",x+i);
		if ( !v[x[0]] ) c++;
		for ( int i=0; i<n/k; i++ ) v[x[i]]=1;
		int s=0;
		for ( int i=0; i<n/k; i++ ) s+=a[x[i]];
		mx=max(mx,s);
		mi=min(mi,s);
	}
	if ( c==k ) {
		printf("%f %f\n",1.0*mi/(n/k),1.*mx/(n/k));
		return 0;
	}
	int l[110],nl=0;
	for ( int i=1; i<=n; i++ )
		if ( !v[i] ) l[nl++]=a[i];
	if ( nl<n/k ) {
		printf("%f %f\n",1.0*mi/(n/k),1.*mx/(n/k));
		return 0;
	}
	sort(l,l+nl);
	int s=0;
	for ( int i=0; i<(n/k); i++ ) s+=l[i];
	mi=min(mi,s);
	s=0;
	for ( int i=0; i<(n/k); i++ ) s+=l[nl-i-1];
	mx=max(mx,s);
	printf("%f %f\n",1.*mi/(n/k),1.*mx/(n/k));
	return 0;
}