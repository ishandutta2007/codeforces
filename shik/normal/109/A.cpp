// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,a=514514514,b=514514514;
	scanf("%d",&n);
	for ( int i=0; 4*i<=n; i++ ) {
		if ( (n-4*i)%7!=0 ) continue;
		int j=(n-4*i)/7;
		if ( i+j<a+b || (i+j==a+b&&i>a) ) a=i,b=j;
	}
	if ( a==514514514 ) puts("-1");
	else {
		while ( a-- ) putchar('4');
		while ( b-- ) putchar('7');
		puts("");
	}
	return 0;
}