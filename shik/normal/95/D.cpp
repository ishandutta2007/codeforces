// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3010
#define M 1000000007
using namespace std;
typedef long long LL;
int k;
LL dp[2][N][N];
LL go( int f, int p, int q ) {
	if ( dp[f][p][q]!=-1 ) return dp[f][p][q];
	if ( q==0 ) return f;
	LL r=0;
	for ( int i=0; i<10; i++ )
		if ( i==4 || i==7 ) r+=go(f|(p<=k),1,q-1);
		else r+=go(f,p+1,q-1);
	return dp[f][p][q]=r%M;
}
LL cal( char *s ) {
	LL r=0;
	int n=strlen(s),i,j,f=0,d=k+1;
	for ( i=0; i<n; i++ ) {
		for ( j=0; j<s[i]-'0'; j++ )
			if( j==4 || j==7 ) r+=go(f|(d<=k),1,n-i-1);
			else r+=go(f,d+1,n-i-1);
		if ( s[i]=='4' || s[i]=='7' ) {
			f|=(d<=k);
			d=1;
		} else d++;
	}
	return r%M;
}
bool chk( char *s, int d=k+1 ) {
	if ( *s==0 ) return 0;
	if ( *s=='4' || *s=='7' ) return d<=k||chk(s+1,1);
	return chk(s+1,d+1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int t;
	char L[N],R[N];
	scanf("%d%d",&t,&k);
	while ( t-- ) {
		scanf("%s%s",L,R);
		printf("%I64d\n",((cal(R)-cal(L)+chk(R))%M+M)%M);
	}
	return 0;
}