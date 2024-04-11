// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	int n,k,l,c,d,p,nl,np,ans=99999;
	scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
	ans=min(ans,k*l/(n*nl));
	ans=min(ans,c*d/n);
	ans=min(ans,p/(n*np));
	printf("%d\n",ans);
	return 0;
}