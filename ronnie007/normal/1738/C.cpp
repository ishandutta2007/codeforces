#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair < int , int > pii ; 
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 107 ;
const int win = 1 ;
const int lose = -1 ;

int n ;
int a[ MAXN ] ;
int dp[ MAXN ][ MAXN ][ 2 ][ 2 ] ;


void solve ( ) {
    cin >> n ;
    int x = 0 , y = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( a[ i ] < 0 ) { a[ i ] = -a[ i ] ; }
        a[ i ] %= 2 ;
        if ( a[ i ] == 0 ) { ++ x ; }
        else { ++ y ; }
    }
    dp[ 0 ][ 0 ][ 0 ][ 0 ] = win ;
    dp[ 0 ][ 0 ][ 1 ][ 0 ] = lose ;
    dp[ 0 ][ 0 ][ 0 ][ 1 ] = lose ;
    dp[ 0 ][ 0 ][ 1 ][ 1 ] = win ;
    for ( int i = 0 ; i <= x ; ++ i ) {
        for ( int j = 0 ; j <= y ; ++ j ) {
            if ( i + j == 0 ) { continue ; }
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    dp[ i ][ j ][ t ][ z ] = lose ;
                    if ( z == 0 ) { 
                        if ( i > 0 && dp[ i - 1 ][ j ][ t ][ z ^ 1 ] == lose ) {
                            dp[ i ][ j ][ t ][ z ] = win ;
                        }
                        if ( j > 0 && dp[ i ][ j - 1 ][ t ^ 1 ][ z ^ 1 ] == lose ) {
                            dp[ i ][ j ][ t ][ z ] = win ;
                        }
                    }
                    else {
                        if ( i > 0 && dp[ i - 1 ][ j ][ t ][ z ^ 1 ] == lose ) {
                            dp[ i ][ j ][ t ][ z ] = win ;
                        }
                        if ( j > 0 && dp[ i ][ j - 1 ][ t ][ z ^ 1 ] == lose ) {
                            dp[ i ][ j ][ t ][ z ] = win ;
                        }
                    }
                }
            }
        }
    }
    if ( dp[ x ][ y ][ 0 ][ 0 ] == win ) {
        cout << "Alice\n" ;
    }
    else {
        cout << "Bob\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}