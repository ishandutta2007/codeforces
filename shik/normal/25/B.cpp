// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int dig[N];
void go( int n ) {
	if ( n<=3 ) {
		for ( int i=0; i<n; i++ ) printf("%d",dig[i]);
		return;
	}
	go(n-2);
	printf("-%d%d",dig[n-2],dig[n-1]);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%1d",dig+i);
	go(n); puts("");
	return 0;
}