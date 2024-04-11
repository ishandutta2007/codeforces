#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 10007
#define MAXLEN 1007

int n ;
int a[ MAXN ] ;

int red , green ;

bool f[ MAXN ] ;

long long dp[ MAXN ][ MAXLEN ] ;

deque < pair < int , int > > q ;

void input ( ) {
    scanf ( "%*d%d" , &n ) ;
    set < int > s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        s.insert ( a[ i ] ) ;
    }
    set < int > :: iterator it ;
    n = 0 ;
    for ( it = s.begin ( ) ; it != s.end ( ) ; ++ it ) {
        a[ ++ n ] = (*it) ;
    }
    scanf ( "%d%d" , &green , &red ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= green ; ++ j ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ 1 ][ green ] = 0 ;
    q.push_front ( { 1 , green } ) ;
    while ( q.empty ( ) == false ) {
        pair < int , int > aux = q.front ( ) ;
        q.pop_front ( ) ;
        int x = aux.first ;
        int k = aux.second ;
        if ( k == 0 ) {
            if ( dp[ x ][ green ] == -1 ) {
                dp[ x ][ green ] = dp[ x ][ 0 ] + 1 ;
                q.push_back ( { x , green } ) ;
            }
        }
        if ( x > 1 ) {
            int nw = a[ x ] - a[ x - 1 ] ;
            if ( k >= nw && dp[ x - 1 ][ k - nw ] == -1 ) {
                dp[ x - 1 ][ k - nw ] = dp[ x ][ k ] ;
                q.push_front ( { x - 1 , k - nw } ) ;
            }
        }
        if ( x < n ) {
            int nw = a[ x + 1 ] - a[ x ] ;
            if ( k >= nw && dp[ x + 1 ][ k - nw ] == -1 ) {
                dp[ x + 1 ][ k - nw ] = dp[ x ][ k ] ;
                q.push_front ( { x + 1 , k - nw } ) ;
            }
        }
    }
    long long ans = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( dp[ i ][ 0 ] != -1 && a[ n ] - a[ i ] <= green ) {
            long long sr = dp[ i ][ 0 ] * ( green + red ) + green ;
            if ( i != n ) { sr += red + ( a[ n ] - a[ i ] ) ; }
            if ( ans == -1 ) { ans = sr ; }
            else {
                ans = min ( ans , sr ) ;
            }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}