// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 200010
using namespace std;
struct P {
	int a,b,c;
	P(){}
	P( int _a, int _b, int _c ):a(_a),b(_b),c(_c){}
	void print() { printf("%d %d\n",a,b); }
};
bool operator <( P a, P b ) {
	if ( a.c!=b.c ) return a.c>b.c;
	return a.a>b.a;
}
int n;
char sex[N];
int val[N];
void input() {
	scanf("%d %s",&n,sex+1);
	for ( int i=1; i<=n; i++ ) scanf("%d",val+i);
}
int pre[N],nxt[N],vis[N];
priority_queue<P> q;
void build() {
	for ( int i=1; i<=n; i++ ) pre[i]=i-1;
	for ( int i=1; i<=n; i++ ) nxt[i]=i+1;
	for ( int i=1; i<n; i++ )
		if ( sex[i]!=sex[i+1] ) q.push(P(i,i+1,abs(val[i]-val[i+1])));
}
void del( int a, int b ) {
	vis[a]=vis[b]=1;
	int x=pre[a];
	int y=nxt[b];
	nxt[x]=y;
	pre[y]=x;
	if ( x>=1 && y<=n && sex[x]!=sex[y] ) q.push(P(x,y,abs(val[x]-val[y])));
}
void solve() {
	vector<P> sol;
	while ( !q.empty() ) {
		P p=q.top(); q.pop();
		if ( vis[p.a] || vis[p.b] ) continue;
		sol.push_back(p);
		del(p.a,p.b);
	}
	printf("%d\n",(int)sol.size());
	for ( int i=0; i<(int)sol.size(); i++ ) sol[i].print();
}
int main()
{
	input();
	build();
	solve();
	return 0;
}