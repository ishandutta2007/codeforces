// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 2010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct R {
	int st,ed;
	void read() {
		int c,r;
		scanf("%d%d",&c,&r);
		st=c-r;
		ed=c+r;
	}
} r[N];
int n;
void input() {
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) r[i].read();
}
int lst[2*N],nl;
int get( int x ) { return lower_bound(lst,lst+nl,x)-lst; }
void lshua() {
	for ( int i=0; i<n; i++ ) {
		lst[nl++]=r[i].st;
		lst[nl++]=r[i].ed;
	}
	sort(lst,lst+nl);
	nl=unique(lst,lst+nl)-lst;
	for ( int i=0; i<n; i++ ) {
		r[i].st=get(r[i].st);
		r[i].ed=get(r[i].ed);
	}
}
int idx[2*N][2*N];
vector<int> v[2*N];
void build() {
	for ( int i=0; i<n; i++ ) idx[r[i].st][r[i].ed]=i+1;
	for ( int i=0; i<n; i++ ) v[r[i].st].push_back(r[i].ed);
}
int dp[2*N][2*N],mid[2*N][2*N];
int go( int L, int R ) {
	if ( dp[L][R]!=-1 ) return dp[L][R];
	if ( L==R ) return 0;
	int ret=go(L+1,R),flg=0;
	FOR(it,v[L]) {
		if ( *it==R ) {
			flg=1;
			continue;
		}
		if ( *it>R ) continue;
		int t=go(L,*it)+go(*it,R);
		if ( t>ret ) {
			ret=t;
			mid[L][R]=*it;
		}
	}
	return dp[L][R]=ret+flg;
}
void output( int L, int R ) {
	if ( L==R ) return;
	if ( idx[L][R] ) printf("%d ",idx[L][R]);
	if ( mid[L][R] ) {
		output(L,mid[L][R]);
		output(mid[L][R],R);
	} else output(L+1,R);
}
void solve() {
	memset(dp,-1,sizeof(dp));
	int ans=go(0,nl-1);
	printf("%d\n",ans);
	output(0,nl-1);
}
int main()
{
	input();
	lshua();
	build();
	solve();
	return 0;
}