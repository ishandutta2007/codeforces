// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int st[N],ed[N];
int main()
{
	int n,p1,p2,p3,t1,t2,ans=0;
	scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
	for ( int i=0; i<n; i++ ) scanf("%d%d",st+i,ed+i);
	ans+=(ed[0]-st[0])*p1;
	for ( int i=1; i<n; i++ ) {
		int d=st[i]-ed[i-1];
		ans+=min(d,t1)*p1;
		d=max(0,d-t1);
		ans+=min(d,t2)*p2;
		d=max(0,d-t2);
		ans+=d*p3;
		ans+=(ed[i]-st[i])*p1;
	}
	printf("%d\n",ans);
	return 0;
}