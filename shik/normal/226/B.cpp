// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int a[N];
LL s[N];
int main()
{
	int n,q,k;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	for ( int i=1; i<=n; i++ ) s[i]=s[i-1]+a[i];
	LL ans1=0;
	for ( int i=1; i<=n; i++ ) ans1+=(i-1LL)*a[i];
	scanf("%d",&q);
	while ( q-- ) {
		scanf("%d",&k);
		LL ans=0,p=1,x=1;
		if ( k>1 ) {
			for ( int i=1; x<n; i++ ) {
				LL t=min(x+(p*=k),(LL)n);
				ans+=i*(s[t]-s[x]);
				x=t;
			}
		} else ans=ans1;
		cout<<ans<<(q==0?'\n':' ');
	}
	return 0;
}