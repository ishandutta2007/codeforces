// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,m,up;
	scanf("%d%d%d",&a,&b,&m);
	if ( m<=b ) { puts("2"); return 0; }
	up=min(a,m-1);
	for ( int i=0; i<=up; i++ ) {
		int t=i*1000000000LL%m;
		if ( t>0 && t<m-b ) {
			printf("1 %09d\n",i);
			return 0;
		}
	}
	puts("2");
	return 0;
}