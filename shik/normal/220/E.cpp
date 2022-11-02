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
struct BIT {
	int dat[N];
	void add( int x, int v ) {
		for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
	}
	int ask( int x ) {
		int r=0;
		for ( int i=x; i; i-=i&-i ) r+=dat[i];
		return r;
	}
} b1,b2;
int a[N],b[N];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; LL k;
	cin>>n>>k;
	for ( int i=0; i<n; i++ ) cin>>a[i];
	for ( int i=0; i<n; i++ ) b[i]=a[i];
	sort(b,b+n);
	for ( int i=0; i<n; i++ ) a[i]=lower_bound(b,b+n,a[i])-b+1;
	LL now=0,ans=0;
	for ( int i=0; i<n; i++ ) {
		b1.add(N-a[i],1);
		now+=b1.ask(N-a[i]-1);
	}
	for ( int i=n-1,j=n; i>=0; i-- ) {
		while ( j-1>i ) {
			int cl=b1.ask(N-a[j-1]-1);
			int cr=b2.ask(a[j-1]-1);
			int c=cl+cr;
			if ( now+c>k ) break;
			now+=c;
			b2.add(a[j-1],1);
			j--;
		}
		ans+=n-j;
		b1.add(N-a[i],-1);
		now-=b1.ask(N-a[i]-1);
		now-=b2.ask(a[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}