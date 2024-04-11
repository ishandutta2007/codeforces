// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 400010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N];
struct Seg {
	int cnt[N];
	void push( int id, int l, int m, int r ) {
		if ( cnt[id]==0 ) cnt[id*2]=cnt[id*2+1]=0;
		else if ( cnt[id]==r-l+1 ) {
			cnt[id*2]=m-l+1;
			cnt[id*2+1]=r-m;
		}
	}
	void pull( int id ) {
		cnt[id]=cnt[id*2]+cnt[id*2+1];
	}
	void init( int id, int l, int r, char c ) {
		if ( l==r ) {
			cnt[id]=(s[l]==c);
			return;
		}
		int m=(l+r)/2;
		init(id*2,l,m,c);
		init(id*2+1,m+1,r,c);
		pull(id);
	}
	int get( int id, int l, int r, int ql, int qr ) {
    	if ( r<ql || l>qr ) return 0;
		if ( ql<=l && r<=qr ) return cnt[id];
		int m=(l+r)/2;
		push(id,l,m,r);
		return get(id*2,l,m,ql,qr)+get(id*2+1,m+1,r,ql,qr);
	}
	void set( int id, int l, int r, int ql, int qr, int v ) {
		if ( r<ql || l>qr ) return;
		if ( ql<=l && r<=qr ) {
			cnt[id]=(v==0?0:r-l+1);
			return;
		}
		int m=(l+r)/2;
		push(id,l,m,r);
		set(id*2,l,m,ql,qr,v);
		set(id*2+1,m+1,r,ql,qr,v);
		pull(id);
	}
} seg[26];
int n,m,ret[26];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for ( int i=0; i<26; i++ ) seg[i].init(1,1,n,'a'+i);
	while ( m-- ) {
		int l,r,c=0,w=-1;
		scanf("%d%d",&l,&r);
		for ( int i=0; i<26; i++ ) ret[i]=seg[i].get(1,1,n,l,r);
		for ( int i=0; i<26; i++ ) if ( ret[i]%2==1 ) c++,w=i;
		if ( c>1 ) continue;
		for ( int i=0; i<26; i++ ) seg[i].set(1,1,n,l,r,0);
		int p=l;
		for ( int i=0; i<26; i++ ) if ( ret[i] ) {
			seg[i].set(1,1,n,p,p+ret[i]/2-1,1);
			p+=ret[i]/2;
		}
		if ( w!=-1 ) {
			seg[w].set(1,1,n,p,p,1);
			p++;
		}
		for ( int i=25; i>=0; i-- ) if ( ret[i] ) {
			seg[i].set(1,1,n,p,p+ret[i]/2-1,1);
			p+=ret[i]/2;
		}
	}
	for ( int i=0; i<26; i++ ) for ( int j=1; j<=n; j++ ) if ( seg[i].get(1,1,n,j,j) ) s[j]='a'+i;
	puts(s+1);
	return 0;
}