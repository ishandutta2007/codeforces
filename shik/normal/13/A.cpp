// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cal( int n, int b ) {
	int r=0;
	while ( n ) {
		r+=n%b;
		n/=b;
	}
	return r;
}
int main()
{
	int n,cnt=0,tmt;
	scanf("%d",&n); tmt=n-2;
	for ( int i=2; i<n; i++ ) cnt+=cal(n,i);
	int g=__gcd(cnt,tmt);
	printf("%d/%d\n",cnt/g,tmt/g);
	return 0;
}