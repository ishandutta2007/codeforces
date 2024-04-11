// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	if ( (x==n/2||x==n/2+1) && (y==n/2||y==n/2+1) ) puts("NO");
	else puts("YES");
	return 0;

}
/*
   OOOOOO
   OOOOOO
   OOXOOO
   OOOOOO
   OOOOOO
   OOOOOO
*/