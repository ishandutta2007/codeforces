// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void get( int &x, int &y ) {
	char c;
	scanf(" %c%d",&c,&y);
	x=c-'a'+1;
}
int mid( int a, int b, int c ) {
	int s[3]={a,b,c};
	sort(s,s+3);
	return s[1];
}
int main()
{
	int rx1,ry1,rx2,ry2,wx,wy,bx,by;
	get(rx1,ry1);
	get(rx2,ry2);
	get(wx,wy);
	get(bx,by);
	for ( int i=-1; i<=1; i++ ) for ( int j=-1; j<=1; j++ ) {
		int x=bx+i,y=by+j;
		if ( x<1||x>8||y<1||y>8 ) continue;
		if ( x==rx1 && y!=ry1 && (wx!=x||mid(wy,y,ry1)!=wy) ) continue;
		if ( y==ry1 && x!=rx1 && (wy!=y||mid(wx,x,rx1)!=wx) ) continue;
		if ( x==rx2 && y!=ry2 && (wx!=x||mid(wy,y,ry2)!=wy) ) continue;
		if ( y==ry2 && x!=rx2 && (wy!=y||mid(wx,x,rx2)!=wx) ) continue;
		if ( abs(x-wx)<=1 && abs(y-wy)<=1 && (x!=wx||y!=wy) ) continue;
		return puts("OTHER"),0;
	}
	puts("CHECKMATE");
	return 0;
}