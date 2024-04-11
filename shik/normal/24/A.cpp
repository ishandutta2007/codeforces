// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int w[N][N],e[N],vis[N];
int main()
{
	int n,a,b,c,sum=0,now=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%d%d%d",&a,&b,&c);
		sum+=c;
		w[b][a]=c;
		e[a]^=b;
		e[b]^=a;
	}
	e[b]^=a;
	for ( int i=b; e[i]; i=e[i] ) {
		now+=w[i][e[i]];
		e[e[i]]^=i;
	}
	printf("%d\n",min(now,sum-now));
	return 0;
}