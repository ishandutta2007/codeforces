// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 8
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
double ans;
int n,m,A,b[N],l[N];
int bit( int x, int i ) { return (x>>i)&1; }
void cal() {
	double now=0;
	for ( int i=0; i<(1<<n); i++ ) {
		int cnt=0;
		double p=1,B=0;
		for ( int j=0; j<n; j++ )
			if ( bit(i,j) ) {
				cnt++;
				p*=l[j]/100.0;
			} else {
				B+=b[j];
				p*=(100-l[j])/100.0;
			}
		if ( 2*cnt>n ) now+=p;
		else now+=p*A/(A+B);
	}
	ans=max(ans,now);
}
void go( int p, int r ) {
	if ( p==n ) { cal(); return; }
	for ( int i=0; i<=r && l[p]+i*10<=100; i++ ) {
		l[p]+=i*10;
		go(p+1,r-i);
		l[p]-=i*10;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&A);
	for ( int i=0; i<n; i++ ) scanf("%d%d",b+i,l+i);
	go(0,m);
	printf("%.9f\n",ans);
	return 0;
}