// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>
#define MP make_pair
#define N 200010
#define INF 1514514514
using namespace std;
typedef pair<int,int> PII;
struct Q {
	char op[10];
	int x,y;
	void read() { scanf("%s %d %d",op,&x,&y); }
	void solve();
	void add();
	void del();
	void find();
} q[N];
int n,ny,ys[N];
void input() {
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) q[i].read();
	for ( int i=1; i<=n; i++ ) ys[i]=q[i].y;
	sort(ys+1,ys+n+1);
	ny=unique(ys+1,ys+n+1)-(ys+1);
	for ( int i=1; i<=n; i++ ) q[i].y=lower_bound(ys+1,ys+ny+1,q[i].y)-ys;
}
set<PII> BIT[N];
void Q::add() { for ( int i=N-y; i<N; i+=i&-i ) BIT[i].insert(MP(x,y)); }
void Q::del() { for ( int i=N-y; i<N; i+=i&-i ) BIT[i].erase(MP(x,y)); }
void Q::find() {
	PII ans(INF,INF);
	for ( int i=N-y-1; i; i-=i&-i ) {
		set<PII>::iterator it=BIT[i].lower_bound(MP(x+1,y));
		if ( it!=BIT[i].end() ) ans=min(ans,*it);
	}
	if ( ans==MP(INF,INF) ) puts("-1");
	else printf("%d %d\n",ans.first,ys[ans.second]);
}
void Q::solve() {
	if ( op[0]=='a' ) add();
	else if ( op[0]=='r' ) del();
	else find();
}
void solve() { for ( int i=1; i<=n; i++ ) q[i].solve(); }
int main()
{
	input();
	solve();
	return 0;
}