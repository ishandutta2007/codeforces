// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 100010
using namespace std;
long long c[N];
queue<long long> q[3];
int main()
{
	int n,t[3],k[3],i,j; long long ans=0;
	for ( i=0; i<3; i++ ) scanf("%d",k+i);
	for ( i=0; i<3; i++ ) scanf("%d",t+i);
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) scanf("%I64d",c+i);
	for ( i=0; i<3; i++ )
		for ( j=0; j<min(100000,k[i]); j++ )
			q[i].push(0);
	for ( i=0; i<n; i++ ) {
		q[0].push(max(c[i],q[0].front())+t[0]); q[0].pop();
		q[1].push(max(q[0].back(),q[1].front())+t[1]); q[1].pop();
		q[2].push(max(q[1].back(),q[2].front())+t[2]); q[2].pop();
		ans=max(ans,q[2].back()-c[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}