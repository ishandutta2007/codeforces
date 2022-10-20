#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
struct tuhla {
	int x[ 3 ] ;
};
struct tuhla a[ MAXN ] ;
map < pair < int , int > , pair < int , int > > ZX ;



void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d%d%d" , &a[ i ].x[ 0 ] , &a[ i ].x[ 1 ] , &a[ i ].x[ 2 ] ) ;
        sort ( a[ i ].x , a[ i ].x + 3 ) ;
    }
}

void solve ( ) {
	int ans = 0 ;
    int br = 0 ;
    int ans1 , ans2 ;
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( a[ i ].x[ 0 ] > ans ) {
        	ans = a[ i ].x[ 0 ] ;
            br = 1 ;
            ans1 = i ;
        }
        for ( j = 0 ; j < 3 ; j ++ ) {
        	for ( t = j + 1 ; t < 3 ; t ++ ) {
            	int id = ( 3 - t - j ) ;
                if ( ZX.find ( make_pair ( a[ i ].x[ j ] , a[ i ].x[ t ] ) ) != ZX.end ( ) ) {
                	pair < int , int > val = ZX[ make_pair ( a[ i ].x[ j ] , a[ i ].x[ t ] ) ] ;
                    int h = val.first + a[ i ].x[ id ] ;
                    if ( h > a[ i ].x[ j ] ) { h = a[ i ].x[ j ] ; }
                    if ( h > a[ i ].x[ t ] ) { h = a[ i ].x[ t ] ; }                    
                    if ( ans < h ) {
                    	ans = h ;
                        br = 2 ;
                        ans1 = val.second ;
                        ans2 = i ;
                    }
                }
            }
        }
        for ( j = 0 ; j < 3 ; j ++ ) {
        	for ( t = j + 1 ; t < 3 ; t ++ ) {
            	int id = ( 3 - t - j ) ;
                if ( ZX.find ( make_pair ( a[ i ].x[ j ] , a[ i ].x[ t ] ) ) != ZX.end ( ) ) {
                	pair < int , int > val = ZX[ make_pair ( a[ i ].x[ j ] , a[ i ].x[ t ] ) ] ;
                    if ( val.first < a[ i ].x[ id ] ) { ZX[ make_pair ( a[ i ].x[ j ] , a[ i ].x[ t ] ) ] = make_pair ( a[ i ].x[ id ] , i ) ; }
                }
                else {
                	ZX[ make_pair ( a[ i ].x[ j ] , a[ i ].x[ t ] ) ] = make_pair ( a[ i ].x[ id ] , i ) ;
				}
			}
		}
    }
    if ( br == 1 ) {
    	printf ( "%d\n%d\n" , br , ans1 ) ;
    }
    else {
    	printf ( "%d\n%d %d\n" , br , ans1 , ans2 ) ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}