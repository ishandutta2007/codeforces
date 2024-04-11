// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,p=1;
	scanf("%d",&n);
	for ( int i=1; i<n; i++ ) {
		p=(p+i)%n;
		if ( p==0 ) p=n;
		printf("%d%c",p,i==n-1?'\n':' ');
	}
	return 0;
}