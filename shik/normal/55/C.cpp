// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,k,x,y,flg=0;
	scanf("%d%d%d",&n,&m,&k);
	while ( k-- ) {
		scanf("%d%d",&x,&y);	
		if ( x<=5 || y<=5 || n-x<=4 || m-y<=4 ) flg=1;
	}
	if ( flg ) puts("YES");
	else puts("NO");
	return 0;
}