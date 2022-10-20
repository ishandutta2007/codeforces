#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

#define inf 1000000007

long long f1 , f2 , f3 , f4 ;
long long ans = inf ;
long long r1 , r2 , r3 , r4 ;

map < pair < long long , long long > , int > m[ 2 ] ;

map < long long , int > ZX ;
map < long long , pair < long long , long long > > REVZX ;



void bfs ( long long x , long long y , int ind ) {
	pair < long long , long long > p = make_pair ( x , y ) ;
	pair < long long , long long > e ;
	m[ ind ][ p ] = 1 ;
	if ( ind == 0 ) {
		ZX[ x * y ] = 1 ;
		REVZX[ x * y ].first = x ;
		REVZX[ x * y ].second = y ;
	}
	queue < pair < long long , long long > > q ;
	long long s ;
	q.push ( p ) ;
	while ( q.empty ( ) == false ) {
		p = q.front ( ) ;
		q.pop ( ) ;
		s = p.first * p.second ;
		//printf ( "%d %d %d\n" , p.first , p.second , m[ ind ][ p ] ) ;
		if ( ind == 1 && ZX[ s ] != 0 ) {
			//printf ( "--%d\n" , ZX[ s ] ) ;
			if ( ans > ZX[ s ] + m[ 1 ][ p ] ) {
				ans = ZX[ s ] + m[ 1 ][ p ] ;
				r1 = REVZX[ s ].first ;
				r2 = REVZX[ s ].second ;
				r3 = p.first ;
				r4 = p.second ;
            }
        }
		// p.first --> 2
		if ( p.first % 2 == 0 ) {
			e = p ;
			e.first /= 2 ;
			if ( m[ ind ][ e ] == 0 ) {
				q.push ( e ) ;
				m[ ind ][ e ] = m[ ind ][ p ] + 1 ;
				if ( ind == 0 ) {
					s = e.first * e.second ;
					if ( ZX[ s ] == 0 ) {
						ZX[ s ] = m[ ind ][ e ] ;
						REVZX[ s ] = e ;
	                }
    	        }
			}
        }
		// p.second --> 2
		if ( p.second % 2 == 0 ) {
			e = p ;
			e.second /= 2 ;
			if ( m[ ind ][ e ] == 0 ) {
				q.push ( e ) ;
				m[ ind ][ e ] = m[ ind ][ p ] + 1 ;
				if ( ind == 0 ) {
					s = e.first * e.second ;
					if ( ZX[ s ] == 0 ) {
						ZX[ s ] = m[ ind ][ e ] ;
						REVZX[ s ] = e ;
    	            }
        	    }
			}
        }


		// p.first --> 3
		if ( p.first % 3 == 0 ) {
			e = p ;
			e.first = ( e.first / 3 ) * 2 ;
			if ( m[ ind ][ e ] == 0 ) {
				q.push ( e ) ;
				m[ ind ][ e ] = m[ ind ][ p ] + 1 ;
				if ( ind == 0 ) {
					s = e.first * e.second ;
					if ( ZX[ s ] == 0 ) {
						ZX[ s ] = m[ ind ][ e ] ;
						REVZX[ s ] = e ;
            	    }
	            }
			}
        }
		// p.second --> 3
		if ( p.second % 3 == 0 ) {
			e = p ;
			e.second = ( e.second / 3 ) * 2 ;
			if ( m[ ind ][ e ] == 0 ) {
				q.push ( e ) ;
				m[ ind ][ e ] = m[ ind ][ p ] + 1 ;
				if ( ind == 0 ) {
					s = e.first * e.second ;
					if ( ZX[ s ] == 0 ) {
						ZX[ s ] = m[ ind ][ e ] ;
						REVZX[ s ] = e ;
        	        }
            	}
			}
        }
    }
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> f1 >> f2 >> f3 >> f4 ;
}
 
void solve ( )  {
	bfs ( f1 , f2 , 0 ) ;
	bfs ( f3 , f4 , 1 ) ;
	if ( ans != inf ) {
		cout << ans - 2 << "\n" ;
		cout << r1 << " " << r2 << "\n" ; 
		cout << r3 << " " << r4 << "\n" ;
    }
	else cout << "-1\n" ;
}