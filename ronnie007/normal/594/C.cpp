#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 100007

int n , k ;
pair < long long , long long > a[ MAXN ] ;

int r[ MAXN ] ;
int c[ MAXN ] ;

int used[ MAXN ] ;

long long ans = -1 ;

bool cmp1 ( int x , int y ) {
	return ( a[ x ].first < a[ y ].first ) ;
}

bool cmp2 ( int x , int y ) {
	return ( a[ x ].second < a[ y ].second ) ;
}

void input ( ) {
	cin >> n >> k ;
	int i ;
	long long xx1 , yy1 , xx2 , yy2 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> xx1 >> yy1 >> xx2 >> yy2 ;
		xx1 *= 2 ; yy1 *= 2 ;
		xx2 *= 2 ; yy2 *= 2 ;
		a[ i ].first = ( xx1 + xx2 ) / 2 ;
		a[ i ].second = ( yy1 + yy2 ) / 2 ;
		r[ i ] = c[ i ] = i ;
	}
}

void solve ( ) {
	sort ( r + 1 , r + n + 1 , cmp1 ) ;
	sort ( c + 1 , c + n + 1 , cmp2 ) ;
	int i , j ;
	int mask ;
	int lim = (2<<(2*k)) ;
	vector < int > v ;	
	for ( mask = 0 ; mask < lim ; mask ++ ) {
		int u = mask ;
		v.clear ( ) ;
		for ( j = 0 ; j < k ; j ++ ) {
			int ost = ( u % 4 ) ;
			u /= 4 ;
			if ( ost == 0 ) {
				for ( i = 1 ; i <= n ; i ++ ) {
					if ( used[ r[ i ] ] == 1 ) { continue ; }
					used[ r[ i ] ] = 1 ;
					v.push_back ( r[ i ] ) ;
					break ;
				}
			}
			else if ( ost == 1 ) {
				for ( i = n ; i >= 1 ; i -- ) {
					if ( used[ r[ i ] ] == 1 ) { continue ; }
					used[ r[ i ] ] = 1 ;
					v.push_back ( r[ i ] ) ;					
					break ;				
				}
			}
			else if ( ost == 2 ) {
				for ( i = 1 ; i <= n ; i ++ ) {
					if ( used[ c[ i ] ] == 1 ) { continue ; }
					used[ c[ i ] ] = 1 ;
					v.push_back ( c[ i ] ) ;					
					break ;
				}			
			}
			else {
				for ( i = n ; i >= 1 ; i -- ) {
					if ( used[ c[ i ] ] == 1 ) { continue ; }
					used[ c[ i ] ] = 1 ;
					v.push_back ( c[ i ] ) ;					
					break ;				
				}			
			}
		}
		long long xx1 , yy1 , xx2 , yy2 ;
		xx1 = xx2 = yy1 = yy2 = 0 ;
		for ( i = 1 ; i <= n ; i ++ ) {
			if ( used[ r[ i ] ] == 0 ) {
				xx1 = a[ r[ i ] ].first ;
				break ;
			}
		}
		for ( i = n ; i >= 1 ; i -- ) {
			if ( used[ r[ i ] ] == 0 ) {
				xx2 = a[ r[ i ] ].first ;
				break ;
			}
		}

		for ( i = 1 ; i <= n ; i ++ ) {
			if ( used[ c[ i ] ] == 0 ) {
				yy1 = a[ c[ i ] ].second ;
				break ;
			}
		}
		for ( i = n ; i >= 1 ; i -- ) {
			if ( used[ c[ i ] ] == 0 ) {
				yy2 = a[ c[ i ] ].second ;
				break ;
			}
		}
		if ( xx1 == xx2 ) {
			if ( k != n ) { xx2 ++ ; }
		}
		if ( yy1 == yy2 ) {
			if ( k != n ) { yy2 ++ ; }		
		}
		long long s = ( xx2 - xx1 + 1 ) / 2 ;
		s *= ( ( yy2 - yy1 + 1 ) / 2 ) ;
		if ( ans == -1 || ans > s ) { ans = s ; }
		for ( i = 0 ; i < k ; i ++ ) {
			used[ v[ i ] ] = 0 ;
		}
	}
	cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}