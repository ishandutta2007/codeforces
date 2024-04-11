// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,m,x1,y1,x2,y2;
	scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
	int dx=abs(x1-x2),dy=abs(y1-y2);
	if ( dx>4 || dy>4 ) puts("Second");
	else if ( dx+dy>=7 ) puts("Second");
	else puts("First");
	return 0;
}