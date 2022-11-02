// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	printf("%d\n",max(0,(n*y+99)/100-x));
	return 0;
}