// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100100
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int n,k,a[N];
LL s[N];
int solve( int p ) {
	int l=0,r=p;
	while ( l!=r ) {
		int m=(l+r+1)/2;
		if ( (LL)m*a[p]-(s[p]-s[p-m])<=k ) l=m;
		else r=m-1;
	}
	return l+1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for ( int i=0; i<n; i++ ) scanf("%d",a+i);
	sort(a,a+n);
	for ( int i=0; i<n; i++ ) s[i+1]=s[i]+a[i];
	int ans=0,sol=0;
	for ( int i=0; i<n; i++ ) {
		int now=solve(i);
		if ( now>ans ) ans=now,sol=a[i];
	}
	printf("%d %d\n",ans,sol);
	return 0;
}