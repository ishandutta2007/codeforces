// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 200010
#define SN 4*N
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int le[SN],me[SN],re[SN];
void init( int id, int l, int r ) {
	le[id]=me[id]=re[id]=r-l+1;
	if ( l==r ) return;
	int m=(l+r)/2;
	init(id*2,l,m);
	init(id*2+1,m+1,r);
}
void add( int id, int l, int r, int p, int v ) {
	if ( l==r ) {
		le[id]=re[id]=me[id]+=v;
		return;
	}
	int m=(l+r)/2;
	if ( p<=m ) add(id*2,l,m,p,v);
	else add(id*2+1,m+1,r,p,v);
	me[id]=max(max(me[id*2],me[id*2+1]),re[id*2]+le[id*2+1]);
	le[id]=le[id*2]+(le[id*2]==m-l+1?le[id*2+1]:0);
	re[id]=re[id*2+1]+(re[id*2+1]==r-m?re[id*2]:0);
}
int st,ed;
inline bool eq( int a, int b ) { return (a+1)/2 == (b+1)/2; }
int ask( int id, int l, int r ) {
	if ( l==r ) return st=ed=l;
	int m=(l+r)/2;
	if ( eq(me[id],me[id*2]) ) return ask(id*2,l,m);
	if ( eq(me[id],re[id*2]+le[id*2+1]) ) {
		st=m-re[id*2]+1;
		ed=m+le[id*2+1];
		return (st+ed)/2;
	}
	return ask(id*2+1,m+1,r);
}
int pos[1000010];
set<int> in;
int main()
{
	int n,m,t,x;
	scanf("%d%d",&n,&m);
	init(1,1,n);
	while ( m-- ) {
		scanf("%d%d",&t,&x);
		if ( t==1 ) {
			int s1=in.empty()?n:*in.begin()-1;
			int t2=ask(1,1,n),s2=(ed-st)/2+1;
			int s3=in.empty()?n:n-*in.rbegin();
			int s=max(s1,max(s2,s3));
			if ( s1==s && s1>=s3 ) pos[x]=1;
			else if ( s2==s ) pos[x]=t2;
			else pos[x]=n;
			in.insert(pos[x]);
			add(1,1,n,pos[x],-1);
			printf("%d\n",pos[x]);
		} else {
			in.erase(pos[x]);
			add(1,1,n,pos[x],1);
		}
	}
	return 0;
}