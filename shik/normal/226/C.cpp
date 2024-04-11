// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL m;
void mul( LL A[2][2], LL B[2][2], LL C[2][2] ) {
	LL tC[2][2]={};
	for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) for ( int k=0; k<2; k++ ) tC[i][j]+=A[i][k]*B[k][j];
	for ( int i=0; i<2; i++ ) for ( int j=0; j<2; j++ ) C[i][j]=tC[i][j]%m;
}
LL A[2][2]={{0,1},{1,1}},B[2][2]={{1,0},{0,1}};
int main()
{
	LL l,r,k;
	cin>>m>>l>>r>>k;
	LL p=1;
	for ( int i=1; i<=1000000; i++ ) {
		LL j=r/i;
		if ( i>p && r/i-(l-1)/i>=k ) p=i;
		if ( j>p && r/j-(l-1)/j>=k ) p=j;
	}
	while ( p ) {
		if ( p&1 ) mul(A,B,B);
		p>>=1;
		mul(A,A,A);
	}
	cout<<B[0][1]<<endl;
	return 0;
}