// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char s[N][N][100];
int big[N];
char* conv( int x, int b ) {
	static char t[100];
	int l=0;
	while ( x ) {
		t[l++]=x%b+'0';
		x/=b;
	}
	reverse(t,t+l);
	t[l]=0;
	return t;
}
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<n; i++ )
		for ( int j=1; j<n; j++ ) 
			strcpy(s[i][j],conv(i*j,n));
	for ( int i=1; i<n; i++ ) for ( int j=1; j<n; j++ ) big[j]=max(big[j],(int)strlen(s[i][j]));
	for ( int i=1; i<n; i++ ) for ( int j=1; j<n; j++ ) printf("%*s%c",big[j],s[i][j],j==n-1?'\n':' ');
	return 0;
}