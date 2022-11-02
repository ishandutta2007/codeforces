// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 1010
using namespace std;
typedef long long LL;
struct P {
	int x,y; LL v;
	P(){}
	P( int _x, int _y, LL _v ):x(_x),y(_y),v(_v){}
	void print() { printf("%d %d %I64d\n",x,y,v); }
} p[N*N],sol[N*N];
inline bool operator <( const P &a, const P &b ) {
	if ( a.v!=b.v ) return a.v<b.v;
	if ( a.x!=b.x ) return a.x<b.x;
	return a.y<b.y;
}
void erase( multiset<int> &q, int v ) {
	multiset<int>::iterator it=q.find(v);
	if ( it!=q.end() ) q.erase(it);
}
int n,m,a,b,np,n_sol;
int h[N][N];
void input() {
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			scanf("%d",&h[i][j]);
}
LL sum[N][N];
void build_s() {
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=m; j++ )
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+h[i][j];
}
int mx[N][N];
void build_x() {
	for ( int i=1; i<=n; i++ ) {
		multiset<int> q;
		for ( int j=m; j>=1; j-- ) {
			q.insert(h[i][j]);
			if ( j<=m-b ) erase(q,h[i][j+b]);
			mx[i][j]=*q.begin();
		}
	}
}
int my[N][N];
void build_y() {
	for ( int i=1; i<=m; i++ ) {
		multiset<int> q;
		for ( int j=n; j>=1; j-- ) {
			q.insert(mx[j][i]);
			if ( j<=n-a ) erase(q,mx[j+a][i]);
			my[j][i]=*q.begin();
		}
	}
}
LL get_sum( int x1, int y1, int x2, int y2 ) { return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]; }
void build() {
	build_s();
	build_x();
	build_y();
	for ( int i=1; i<=n-a+1; i++ )
		for ( int j=1; j<=m-b+1; j++ )
			p[np++]=P(i,j,get_sum(i,j,i+a-1,j+b-1)-(LL)a*b*my[i][j]);
	sort(p,p+np);
}
bool vis[N][N];
void clear( int x1, int y1, int x2, int y2 ) {
	if ( x1<1 ) x1=1;
	if ( x2>n ) x2=n;
	if ( y1<1 ) y1=1;
	if ( y2>m ) y2=m;
	for ( int i=x1; i<=x2; i++ )
		for ( int j=y1; j<=y2; j++ )
			vis[i][j]=1;
}
void solve() {
	for ( int i=0; i<np; i++ ) {
		if ( vis[p[i].x][p[i].y] ) continue;
		sol[n_sol++]=p[i];
		clear(p[i].x-a+1,p[i].y-b+1,p[i].x+a-1,p[i].y+b-1);
	}
	printf("%d\n",n_sol);
	for ( int i=0; i<n_sol; i++ ) sol[i].print();
}
int main()
{
	input();
	build();
	solve();
	return 0;
}