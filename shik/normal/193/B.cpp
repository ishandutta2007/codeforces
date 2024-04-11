// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 30
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,u,r,a[N],b[N],k[N],p[N],s[N+2][N];
LL ans=-(1LL<<60);
void go( int v ) {
	int *x=s[v],*y=s[v+1],*z=s[v+2];
	if ( (u-v)%2==0 ) {
		LL now=0;
		for ( int i=0; i<n; i++ ) now+=1LL*x[i]*k[i];
		ans=max(ans,now);
	} else {
		LL now=0;
		for ( int i=0; i<n; i++ ) now+=1LL*(x[i]^b[i])*k[i];
		ans=max(ans,now);
	}
	if ( v==u ) return;
	for ( int i=0; i<n; i++ ) y[i]=x[p[i]]+r;
	go(v+1);
	if ( v+1==u ) return;
	for ( int i=0; i<n; i++ ) y[i]=x[i]^b[i];
	for ( int i=0; i<n; i++ ) z[i]=y[p[i]]+r;
	go(v+2);
}
int main()
{
	scanf("%d%d%d",&n,&u,&r);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<n; i++ ) scanf("%d",b+i);
	for ( int i=0; i<n; i++ ) scanf("%d",k+i);
	for ( int i=0; i<n; i++ ) scanf("%d",p+i);
	for ( int i=0; i<n; i++ ) p[i]--;
	for ( int i=0; i<n; i++ ) s[0][i]=a[i];
	go(0);
	cout<<ans<<endl;
	return 0;
}