#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <string>
#include <iostream>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const ld eps = 1e-12;

int ni, n, ci, cj;
ld A[1010][1010];
ld b[1010];
ld x[1010];

void fillmatr()
{
	A[0][0] = 1.0/3.0 - 1;
	A[0][1] = 1.0/3.0;
	b[0] = -1 - 1.0/3.0*x[0];
	
	A[n-1][n-1] = 1.0/3.0 - 1;
	A[n-1][n-2] = 1.0/3.0;
	b[n-1] = -1 - 1.0/3.0*x[n-1];
	
	for ( int i=1; i<n-1; i++ )
	{
		A[i][i] = 0.25 - 1;
		A[i][i-1] = A[i][i+1] = 1.0/4.0;
		b[i] = -1 - 1.0/4.0*x[i];
	}
/*	
	forn( i,n )
	{
		forn( j,n ) printf( "%.5f ", (double)A[i][j] ); printf( " | %.5f\n", (double)b[i] );		
	}
*/	
	ld coeff = -1;
	forn( i,n-1 )
//		if ( fabs( A[i+1][i] ) > eps )
		{
			coeff = -A[i+1][i] / A[i][i];
			A[i+1][i+1] += A[i][i+1] * coeff;			
			b[i+1] += b[i] * coeff;
		}
/*	
	printf( "-----------------------\n" );	
	forn( i,n )
	{
		forn( j,n ) printf( "%.5f ", (double)A[i][j] ); printf( " | %.5f\n", (double)b[i] );		
	}
	printf( "-----------------------\n" );	
*/		
	x[n-1] = b[n-1] / A[n-1][n-1];
	for ( int i=n-2; i>=0; i-- )
		x[i] = ( b[i] - A[i][i+1] * x[i+1] ) / A[i][i];
}

int main()
{
	scanf( "%d %d", &ni, &n );
	scanf( "%d %d", &ci, &cj );
	int d = ni-ci;
	
	if ( n == 1 )
	{
		printf( "%.10f\n", (double)2*d );
		return 0;
	}
	
	forn( q,d )
		fillmatr();
	
	printf( "%.10f\n", (double)x[cj-1] );
}