// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#define M 55
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
inline int idx( char c ) {
	if ( islower(c) ) return c-'a';
	else return c-'A'+26;
}
int m;
LL c[M][M];
void mul( LL a[M][M], LL b[M][M] ) {
	memset(c,0,sizeof(c));
	for ( int i=0; i<m; i++ ) for ( int j=0; j<m; j++ ) for ( int k=0; k<m; k++ ) c[i][j]=(a[i][k]*b[k][j]+c[i][j])%MOD;
	for ( int i=0; i<m; i++ ) for ( int j=0; j<m; j++ ) a[i][j]=c[i][j];
}
LL A[M][M],X[M][M];
int main()
{
	LL n;
	int k;
	cin>>n>>m>>k; n--;
	for ( int i=0; i<m; i++ ) for ( int j=0; j<m; j++ ) X[i][j]=1;
	while ( k-- ) {
		char a,b;
		scanf(" %c%c",&a,&b);
		X[idx(a)][idx(b)]=0;
	}
	for ( int i=0; i<m; i++ ) A[i][i]=1;
	for ( LL i=1; i<=n; i*=2 ) {
		if ( n&i ) mul(A,X);
		mul(X,X);
	}
	LL ans=0;
	for ( int i=0; i<m; i++ ) for ( int j=0; j<m; j++ ) ans+=A[i][j];
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}