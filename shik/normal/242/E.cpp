// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline int bit( int x, int i ) { return (x>>i)&1; }
typedef long long LL;
struct Seg {
	int val[4*N];
	bool rev[4*N];
	void init( int id, int l, int r, int *b ) {
		rev[id]=0;
		if ( l==r ) {
			val[id]=b[l];
			return;
		}
		int m=(l+r)/2;
		init(id*2,l,m,b);
		init(id*2+1,m+1,r,b);
		val[id]=val[id*2]+val[id*2+1];
	}
	int get( int id, int l, int r ) {
		if ( !rev[id] ) return val[id];
		else return (r-l+1)-val[id];
	}
	void push( int id, int l, int r ) {
		if ( !rev[id] ) return;
		rev[id*2]^=1;
		rev[id*2+1]^=1;
		rev[id]=0;
	}
	void pull( int id, int l, int r ) {
		int m=(l+r)/2;
		val[id]=get(id*2,l,m)+get(id*2+1,m+1,r);
	}
	int get( int id, int l, int r, int ql, int qr ) {
		if ( qr<l || ql>r ) return 0;
		if ( ql<=l && r<=qr ) return get(id,l,r);
		push(id,l,r);
		int m=(l+r)/2,ret=0;
		ret+=get(id*2,l,m,ql,qr);
		ret+=get(id*2+1,m+1,r,ql,qr);
		pull(id,l,r);
		return ret;
	}
	void chg( int id, int l, int r, int ql, int qr ) {
		if ( qr<l || ql>r ) return;
		if ( ql<=l && r<=qr ) {
			rev[id]^=1;
			return;
		}
		push(id,l,r);
		int m=(l+r)/2;
		chg(id*2,l,m,ql,qr);
		chg(id*2+1,m+1,r,ql,qr);
		pull(id,l,r);
	}

} seg[22];
int n,a[N],b[N];
void solve_1() {
	int l,r;
	scanf("%d%d",&l,&r);
	LL ans=0;
	for ( int i=0; i<20; i++ ) ans+=(1LL<<i)*seg[i].get(1,1,n,l,r);
	cout<<ans<<endl;
}
void solve_2() {
	int l,r,x;
	scanf("%d%d%d",&l,&r,&x);
	for ( int i=0; i<20; i++ ) if ( bit(x,i) ) seg[i].chg(1,1,n,l,r);
}
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=0; i<20; i++ ) {
		for ( int j=1; j<=n; j++ ) b[j]=bit(a[j],i);
		seg[i].init(1,1,n,b);
	}
	int m,t;
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d",&t);
		if ( t==1 ) solve_1();
		else solve_2();
	}
	return 0;
}