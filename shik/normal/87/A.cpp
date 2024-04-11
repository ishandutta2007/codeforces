// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	int a,b;
	LL now,x,y,ca,cb;
	scanf("%d%d",&a,&b);
	//if ( abs(a-b)<=1 ) puts("Equal");
	//else puts(a<b?"Dasha":"Masha");
	now=ca=cb=0;
	x=a;
	y=b;
	while ( x!=y ) {
		if ( x<y || (x==y&&a>b) ) {
			ca+=x-now;
			now=x;
			x+=a;
		} else {
			cb+=y-now;
			now=y;
			y+=b;
		}
	}
	if ( a>b ) ca+=x-now;
	else cb+=y-now;
	if ( ca==cb ) puts("Equal");
	else puts(ca>cb?"Dasha":"Masha");
	return 0;
}