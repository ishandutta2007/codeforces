// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int n,a[N],s1[N],s2[N],b1[N],b2[N],ans;
int main()
{
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=1; i<=n; i++ ) s1[i]=s1[i-1]+a[i];
	for ( int i=n; i>=1; i-- ) s2[i]=s2[i+1]+a[i];
	for ( int i=1; i<=n; i++ ) b1[i]=max(b1[i-1]+a[i],-s1[i]);
	for ( int i=n; i>=1; i-- ) b2[i]=max(b2[i+1]+a[i],-s2[i]);
	for ( int i=0; i<=n; i++ ) ans=max(ans,b1[i]+b2[i+1]);
	printf("%d\n",ans);
	return 0;
}