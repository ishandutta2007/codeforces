// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool chk( int h, int m ) {
	return h/10==m%10 && h%10==m/10;
}
void nxt( int &h, int &m ) {
	m++;
	if ( m==60 ) m=0,h++;
	if ( h==24 ) h=0;
}
int main()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	for ( nxt(h,m); !chk(h,m); nxt(h,m) );
	printf("%02d:%02d\n",h,m);
	return 0;
}