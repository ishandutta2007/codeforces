// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int a,x,y,h;
	scanf("%d%d%d",&a,&x,&y); a*=2; x*=2; y*=2;
	h=y/a+1;
	if ( y%a==0 ) puts("-1");
	else if ( h==1 ) {
		if ( x<=-a/2 || x>=a/2 ) puts("-1");
		else puts("1");
	} else if ( h%2==0 ) {
		if ( x<=-a/2 || x>=a/2 ) puts("-1");
		else printf("%d\n",2+(h/2-1)*3);
	} else {
		if ( x<=-a || x>=a || x==0 ) puts("-1");
		else if ( x<0 ) printf("%d\n",(h-1)/2*3);
		else printf("%d\n",(h-1)/2*3+1);
	}
	return 0;
}