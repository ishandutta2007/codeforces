// by shik
#include <cstdio>
#include <algorithm>
using namespace std;
bool f( long long n, long long m, long long k ) {
	if ( k==1 ) return n%2==0 || m%2==0;
	return (n+m+min(n/(k+1),m/(k+1)))%2 || min(n,m)%(k+1)==0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,k,n,m;
	scanf("%d%d",&t,&k);
	while ( t-- ) {
		scanf("%d%d",&n,&m);
		putchar(f(n,m,k)?'+':'-');
		putchar('\n');
	}
	return 0;
}