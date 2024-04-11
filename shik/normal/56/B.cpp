// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
int n,num[N];
bool chk( int l, int r ) {
	reverse(num+l,num+r+1);
	int ret=1;
	for ( int i=1; i<n; i++ )
		if ( num[i]!=num[i-1]+1 ) ret=0;
	reverse(num+l,num+r+1);
	return ret;
}
int main()
{
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) scanf("%d",num+i);
	for ( int i=0; i<n; i++ )
		for ( int j=i+1; j<n; j++ )
			if ( chk(i,j) ) {
				printf("%d %d\n",i+1,j+1);
				return 0;
			}
	puts("0 0");
	return 0;
}