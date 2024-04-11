// m(_ _)m
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
#define N 100010
struct P {
	int id,x,y; double d;
	P(){}
	P( int _x, int _y ):x(_x),y(_y){}
	void read() {
		scanf("%d%d",&x,&y);
	}
	int len2() { return x*x+y*y; }
	double len() { return sqrt(len2()); }
} p[N],q[N];
P operator -( P a, P b ) { return P(a.x-b.x,a.y-b.y); }
int n;
void input() {
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
}
bool cp( P a, P b ) { return a.d<b.d; }
inline double dis( P a, P b ) { return (a-b).len(); }
int tmt( P a, P b ) {
	if ( a.x==b.x && a.y==b.y ) return 1;
	if ( a.x==-b.x && a.y==b.y ) return 2;
	if ( a.x==b.x && a.y==-b.y ) return 3;
	if ( a.x==-b.x && a.y==-b.y ) return 4;
	puts("QQ");
	return -1;
}
void build() {
	for ( int i=0; i<n; i++ ) q[i]=P(abs(p[i].x),abs(p[i].y));
	for ( int i=0; i<n; i++ ) q[i].d=q[i].len();
	for ( int i=0; i<n; i++ ) q[i].id=i;
	sort(q,q+n,cp);
	double sml=1e100;
	int a=-1,b=-1;
	for ( int i=0; i<n; i++ ) {
		for ( int j=i+1; j<n&&q[j].d-q[i].d<sml+1e-6; j++ ) {
			if ( dis(q[i],q[j])<sml ) {
				sml=dis(q[i],q[j]);
				a=i; b=j;
			}
		}
	}
	printf("%d %d %d %d\n",q[a].id+1,5-tmt(p[q[a].id],q[a]),q[b].id+1,tmt(p[q[b].id],q[b]));
}
void solve() {

}
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	input();
	build();
	solve();
	return 0;
}