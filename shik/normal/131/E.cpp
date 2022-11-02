// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	int x,y,id;
	P(){}
	P( int _x, int _y, int _id ):x(_x),y(_y),id(_id){}
	void read( int _id ) { id=_id; scanf("%d%d",&x,&y); }
} p[N];
int n,cnt[N];
bool cp( P a, P b ) { return a.x!=b.x?a.x<b.x:a.y<b.y; }
void cal() {
	sort(p,p+n,cp);
	for ( int i=1; i<n; i++ ) if ( p[i].x==p[i-1].x ) cnt[p[i].id]++;
}
int main()
{
	scanf("%*d%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read(i);
	cal();
	for ( int i=0; i<n; i++ ) p[i].y*=-1;
	cal();
	for ( int i=0; i<n; i++ ) swap(p[i].x,p[i].y);
	cal();
	for ( int i=0; i<n; i++ ) p[i].y*=-1;
	cal();
	for ( int i=0; i<n; i++ ) p[i]=P(p[i].x+p[i].y,p[i].x-p[i].y,p[i].id);
	cal();
	for ( int i=0; i<n; i++ ) p[i].y*=-1;
	cal();
	for ( int i=0; i<n; i++ ) swap(p[i].x,p[i].y);
	cal();
	for ( int i=0; i<n; i++ ) p[i].y*=-1;
	cal();
	for ( int i=0; i<n; i++ ) p[i]=P(p[i].x+p[i].y,p[i].x-p[i].y,p[i].id);
	int ans[9]={};
	for ( int i=0; i<n; i++ ) ans[cnt[i]]++;
	for ( int i=0; i<9; i++ ) printf("%d%c",ans[i],i==8?'\n':' ');
	return 0;
}