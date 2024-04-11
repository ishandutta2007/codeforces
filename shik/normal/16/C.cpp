// by shik
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,x,y,r,g;
	scanf("%d%d%d%d",&a,&b,&x,&y);
	g=__gcd(x,y);
	x/=g; y/=g;
	//if ( x>y && a<b ) swap(a,b);
	//if ( x<y && a>b ) swap(a,b);
	r=min(a/x,b/y);
	printf("%d %d\n",x*r,y*r);
	return 0;
}