// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#define N 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int h,m,n;
void input() {
	scanf("%d%d%d",&h,&m,&n);
}
set<int> s;
int head[N],tail[N],cnt[N],idx[N],nid;
void build() {
	for ( int i=0; i<h; i++ ) s.insert(i);
	memset(idx,-1,sizeof(idx));
	memset(tail,-1,sizeof(tail));
	for ( int i=0; i<h; i++ ) {
		int st=nid;
		if ( idx[i]==-1 ) for ( int j=i; idx[j]==-1; j=(j+m)%h ) {
			head[j]=st;
			idx[j]=nid++;
		}
		int ed=nid;
		for ( int j=i; tail[j]==-1; j=(j+m)%h ) tail[j]=ed;
	}
	for ( int i=0; i<h; i++ ) cnt[i]=tail[i]-head[i];
}
long long ans;
map<int,int> pos;
void add( int id, int hash ) {
	set<int>::iterator it=s.lower_bound(idx[hash]);
	if ( it==s.end() || *it>=tail[hash] ) it=s.lower_bound(head[hash]);
	ans+=(*it-idx[hash]+cnt[hash])%cnt[hash];
	pos[id]=*it;
	s.erase(*it);
}
void del( int id ) {
	s.insert(pos[id]);
}
void solve() {
	char op; int id,hash;
	while ( n-- ) {
		scanf(" %c%d",&op,&id);
		if ( op=='+' ) {
			scanf("%d",&hash);
			add(id,hash);
		} else if ( op=='-' ) {
			del(id);
		} else puts("QQ");
	}
	printf("%I64d\n",ans);
}
int main()
{
	input();
	build();
	solve();
	return 0;
}