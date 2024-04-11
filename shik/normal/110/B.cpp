// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,app[130]={};
	scanf("%d",&n);
	for ( int i=1,j; i<=n; i++ ) {
		for ( j='a'; j<='z'; j++ )
			if ( app[j]==0 || (i-app[j])%4==0 || (i-app[j])%7==0 ) break;
		if ( j>'z' ) puts("QQ");
		putchar(j);
		app[j]=i;
	}
	puts("");
	return 0;
}