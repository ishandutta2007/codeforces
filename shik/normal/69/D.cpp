// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define N 20
#define H 643204
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,d,dx[N],dy[N];
bool out( int x, int y ) { return x*x+y*y>d*d; }
struct S {
	bool a,b; short x,y;
	S( int _a=0, int _b=0, int _x=0, int _y=0 ):a(_a),b(_b),x(_x),y(_y) {  }
	int h() const { return ((b*2+a)*401+(x+200))*401+y+200; }
	vector<S> nxt() {
		vector<S> ret;
		if ( a==0 ) ret.push_back(S(b,1,y,x));
		if ( b==0 ) ret.push_back(S(1,a,y,x));
		for ( int i=0; i<n; i++ ) if ( !out(x+dx[i],y+dy[i]) ) ret.push_back(S(b,a,x+dx[i],y+dy[i]));
		sort(ret.begin(),ret.end());
		ret.erase(unique(ret.begin(),ret.end()),ret.end());
		return ret;
	}
};
inline bool operator ==( const S &a, const S &b ) { return a.h()==b.h(); }
inline bool operator <( const S &a, const S &b ) { return a.h()<b.h(); }
int dp[H],cnt[H];
vector<S> pre[H],nxt[H];
queue<S> q;
int main()
{
	int sx,sy;
	scanf("%d%d%d%d",&sx,&sy,&n,&d);
	for ( int i=0; i<n; i++ ) scanf("%d%d",dx+i,dy+i);
	for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) for ( int k=-d; k<=d; k++ ) for ( int l=-d; l<=d; l++ ) if ( !out(k,l) ) {
		S now=S(i,j,k,l);
		nxt[now.h()]=now.nxt();
		cnt[now.h()]=nxt[now.h()].size();
		FOR(it,nxt[now.h()]) pre[it->h()].push_back(now);
		if ( cnt[now.h()]==0 ) q.push(now);
	}
	while ( !q.empty() ) {
		S p=q.front(); q.pop(); dp[p.h()]=2;
		FOR(it,nxt[p.h()]) if ( dp[it->h()]==2 ) { dp[p.h()]=1; break; }
		FOR(it,pre[p.h()]) if ( --cnt[it->h()]==0 ) q.push(*it);
	}
	puts(dp[S(0,0,sx,sy).h()]==1?"Anton":"Dasha");
	return 0;
}