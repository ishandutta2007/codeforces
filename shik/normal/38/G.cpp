// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,val[N],root,ch[N][2],sz[N],big[N];
void pull( int x ) {
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	big[x]=max(val[x],max(big[ch[x][0]],big[ch[x][1]]));
}
void rotate( int &x, int d ) {
	int y=ch[x][d];
	ch[x][d]=ch[y][!d];
	ch[y][!d]=x;
	pull(x); pull(y); x=y;
}
void ins( int &x, int p, int c ) {
	if ( x==0 ) x=p;
	else {
		int d=(val[p]>max(val[x],big[ch[x][1]]) && c>sz[ch[x][1]]);
		if ( d ) ins(ch[x][0],p,c-sz[ch[x][1]]-1);
		else ins(ch[x][1],p,c);
		rotate(x,!d);
	}
}
void output( int x ) {
	if ( !x ) return;
	output(ch[x][0]);
	printf("%d ",x);
	output(ch[x][1]);
}
int main()
{
	scanf("%d",&n);
	for ( int i=1,c; i<=n; i++ ) {
		scanf("%d%d",val+i,&c);
		ins(root,i,c);
	}
	output(root);
	return 0;
}