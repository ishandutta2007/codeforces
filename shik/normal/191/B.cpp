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
int a[N],s[N],v[N];
bool cp( int x, int y ) { return a[x]>a[y]; }
int main()
{
	int n,k; LL b;
	cin>>n>>k>>b;
	for ( int i=1; i<=n; i++ ) cin>>a[i];
	for ( int i=1; i<n; i++ ) s[i]=i;
	sort(s+1,s+n,cp);
	LL now=0;
	for ( int i=1; i<k; i++ ) {
		now+=a[s[i]];
		v[s[i]]=1;
	}
	if ( now+a[s[k]]<=b ) {
		printf("%d\n",n);
		return 0;
	}
	for ( int i=1; i<n; i++ ) if ( v[i] || now+a[i]>b ) {
		printf("%d\n",i);
		return 0;
	}
	printf("%d\n",n);
	return 0;
}