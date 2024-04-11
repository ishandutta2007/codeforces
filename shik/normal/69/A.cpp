// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,y,z,sx=0,sy=0,sz=0;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d%d%d",&x,&y,&z);
		sx+=x;
		sy+=y;
		sz+=z;
	}
	puts(sx==0&&sy==0&&sz==0?"YES":"NO");
	return 0;
}