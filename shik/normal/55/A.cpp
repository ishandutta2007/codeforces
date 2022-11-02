// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2010
using namespace std;
int vis[N];
int main()
{
	int n,now,i,cnt=0;
	scanf("%d",&n);
	now=0;
	for ( i=0; i<N; i++ ) {
		vis[now]=1;
		now=(now+i)%n;	
	}
	for ( i=0; i<n; i++ )
		if ( vis[i] ) cnt++;
	puts(cnt==n?"YES":"NO");
	return 0;
}