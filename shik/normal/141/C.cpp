// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	char name[20];
	int a;
	double x;
	void read() { scanf("%s %d",name,&a); }
} p[N];
bool cpa( P a, P b ) { return a.a!=b.a?a.a<b.a:a.x<b.x; }
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
	sort(p,p+n,cpa);
	for ( int i=0; i<n; i++ ) {
		if ( p[i].a>i ) { puts("-1"); return 0; }
		if ( i==0 ) p[i].x=1;
		else if ( p[i].a==0 ) p[i].x=p[0].x*2;
		else if ( p[i].a==i ) p[i].x=p[n-1].x/2;
		else p[i].x=(p[p[i].a].x+p[p[i].a-1].x)/2;
		for ( int j=i; j>0&&p[j].x>p[j-1].x; j-- ) swap(p[j],p[j-1]);
		for ( int j=0; j<=i; j++ ) p[j].x=n-j;
	}
	sort(p,p+n,cpa);
	for ( int i=0; i<n; i++ ) printf("%s %.0f\n",p[i].name,p[i].x);
	return 0;
}