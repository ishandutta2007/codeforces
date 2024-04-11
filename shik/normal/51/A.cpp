// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
int p[N][4],vis[N];
bool eq( int a[4], int b[4] ) {
	for ( int i=0; i<4; i++ ) {
		int flg=1;
		for ( int j=0; j<4; j++ )
			if ( a[(j+i)%4]!=b[j] ) flg=0;
		if ( flg ) return 1;
	}
	return 0;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) {
		scanf("%1d%1d%1d%1d",p[i],p[i]+1,p[i]+3,p[i]+2);
		if ( i<n-1 ) scanf(" **");
	}
	for ( int i=0; i<n; i++ ) {
		if ( vis[i] ) continue;
		ans++;
		for ( int j=i+1; j<n; j++ )
			if ( !vis[j] && eq(p[i],p[j]) ) vis[j]=1;
	}
	printf("%d\n",ans);
	return 0;
}