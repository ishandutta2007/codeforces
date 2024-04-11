// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int v[100010];
int main()
{
	int a,b,m,r,t=0;
	scanf("%d%d%d%d",&a,&b,&m,&r);
	while ( !v[r] ) {
		v[r]=t++;
		r=(a*r+b)%m;
	}
	printf("%d\n",t-v[r]);
	return 0;
}