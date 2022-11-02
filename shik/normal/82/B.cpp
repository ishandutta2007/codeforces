// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int w[210][210],vis[210],fa[210],cnt[210],app[210];
int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
void Union( int a, int b ) { fa[Find(b)]=Find(a); }
int main()
{
	int n,i,m,a[210],j,k;
	scanf("%d",&n);
	if ( n==2 ) {
		scanf("%d",&m);
		for ( i=0; i<m; i++ ) scanf("%d",a+i);
		printf("1 %d\n",a[0]);
		printf("%d ",m-1);
		for ( i=1; i<m; i++ ) printf("%d%c",a[i],i==m-1?'\n':' ');
		return 0;
	}
	for ( i=0; i<n*(n-1)/2; i++ ) {
		scanf("%d",&m);
		for ( j=0; j<m; j++ ) scanf("%d",a+j);
		for ( j=0; j<m; j++ ) app[a[j]]++;
		for ( j=0; j<m; j++ )
			for ( k=0; k<m; k++ )
				if ( j!=k ) w[a[j]][a[k]]++;
	}
	for ( i=1; i<=200; i++ ) fa[i]=i;
	for ( i=1; i<=200; i++ )
		for ( j=1; j<=200; j++ )
			if ( w[i][j]==n-1 ) Union(i,j);
	for ( i=1; i<=200; i++ ) cnt[Find(i)]++;
	for ( i=1; i<=200; i++ )
		if ( !vis[i] && app[i]>0 ) {
			printf("%d",cnt[Find(i)]);
			for ( j=1; j<=200; j++ )
				if ( Find(j)==Find(i) ) {
					printf(" %d",j);
					vis[j]=1;
				}
			puts("");
		}
	return 0;
}