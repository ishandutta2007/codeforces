// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	n+=n%3;
	printf("%d %d\n",n/36,n%36/3);
	return 0;
}