// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int a[N],b[N],c[N],w[N],die[N];
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d%d%d%d",a+i,b+i,c+i,w+i);
	for ( int i=1; i<=n; i++ )
		for ( int j=1; j<=n; j++ )
			if ( a[i]<a[j] && b[i]<b[j] && c[i]<c[j] ) die[i]=1;
	int ans=0;
	for ( int i=1; i<=n; i++ )
		if ( !die[i] && (ans==0 || w[i]<w[ans]) ) ans=i;
	printf("%d\n",ans);
	return 0;
}