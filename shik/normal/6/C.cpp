// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int n,s[N];
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",s+i);
	int a=1,b=n;
	while ( a<b-1 )
		if ( s[a]<=s[b] ) s[b]-=s[a++];
		else s[a]-=s[b--];
	printf("%d %d\n",a,n-a);
	return 0;
}