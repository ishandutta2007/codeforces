// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void input( int &x, int &y ) {
	char c;
	scanf(" %c%d",&c,&y);
	x=c-'a'+1;
}
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
bool chk_rook( int x1, int y1, int x2, int y2 ) {
	if ( x1==x2 || y1==y2 ) return 0;
	for ( int i=0; i<8; i++ )
		if ( x1==x2+dx[i] && y1==y2+dy[i] ) return 0;
	return 1;
}
bool chk_knight( int x1, int y1, int x2, int y2 ) {
	if ( x1==x2 && y1==y2 ) return 0;
	for ( int i=0; i<8; i++ )
		if ( x1==x2+dx[i] && y1==y2+dy[i] ) return 0;
	return 1;
}
int main()
{
	int x1,y1,x2,y2,ans=0;
	input(x1,y1);
	input(x2,y2);
	for ( int i=1; i<=8; i++ )
		for ( int j=1; j<=8; j++ )
			if ( chk_rook(x1,y1,i,j) && chk_knight(x2,y2,i,j) ) ans++;
	printf("%d\n",ans);
	return 0;
}