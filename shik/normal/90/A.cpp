// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int r,g,b,t=0;
	scanf("%d%d%d",&r,&g,&b);
	if ( r ) t=max(t,(r-1)/2*3+30);
	if ( g ) t=max(t,(g-1)/2*3+31);
	if ( b ) t=max(t,(b-1)/2*3+32);
	printf("%d\n",t);
	return 0;
}