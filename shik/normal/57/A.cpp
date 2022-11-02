// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x1,y1,x2,y2,p1,p2;
	scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
	if ( y1==0 ) p1=x1;
	else if ( x1==n ) p1=n+y1;
	else if ( y1==n ) p1=n+n+n-x1;
	else p1=n+n+n+n-y1;
	if ( y2==0 ) p2=x2;
	else if ( x2==n ) p2=n+y2;
	else if ( y2==n ) p2=n+n+n-x2;
	else p2=n+n+n+n-y2;
	printf("%d\n",min(abs(p1-p2),4*n-abs(p1-p2)));
	return 0;
}