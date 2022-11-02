// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
struct P {
	int x,y;
	void read() { scanf("%d%d",&x,&y); }	
} p[N],q[N];
bool cmp( P a, P b ) { return a.x<b.x || (a.x==b.x&&a.y<b.y); }
bool eq( P a, P b ) { return a.x==b.x && a.y==b.y; }
char sol[3][20]={"Grapes","Carrots","Kiwis"}; 
int main()
{
	int n,m,k,t,i,j,pos;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for ( i=0; i<k; i++ ) p[i].read();
	for ( i=0; i<t; i++ ) q[i].read();
	for ( i=0; i<t; i++ ) {
		for ( j=0; j<k; j++ )
			if ( eq(p[j],q[i]) ) {
				puts("Waste");
				break;
			}
		if ( j<k ) continue;
		pos=(q[i].x-1)*m+q[i].y;
		for ( j=0; j<k; j++ )
			if ( cmp(p[j],q[i]) ) pos--;
		puts(sol[pos%3]);
	}
	return 0;
}