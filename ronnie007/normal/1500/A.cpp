#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MAXVAL 5000007

int n ;
int a[ MAXN ] ;

pair < int , int > w[ MAXVAL ] ;
int cnt[ MAXVAL ] ;

vector < int > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ cnt[ a[ i ] ] ;
        if ( cnt[ a[ i ] ] == 2 ) {
            v.push_back ( a[ i ] ) ;
        }
    }
}

void solve ( ) {
    if ( v.size ( ) >= 2 ) {
        int val1 = v[ 0 ] ;
        int val2 = v[ 1 ] ;
        int x , y , z , t ;
        x = y = z = t = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( a[ i ] == val1 ) {
                if ( x == 0 ) { x = i ; }
                else if ( z == 0 ) { z = i ; }
            }
            else if ( a[ i ] == val2 ) {
                if ( y == 0 ) { y = i ; }
                else if ( t == 0 ) { t = i ; }
            }
        }
        printf ( "YES\n" ) ;
        printf ( "%d %d %d %d\n" , x , y , z , t ) ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            int h = a[ i ] + a[ j ] ;
            if ( w[ h ].first == 0 ) {
                w[ h ] = { i , j } ;
            }
            else {
                if ( w[ h ].first != i && w[ h ].second != i ) {
                    if ( w[ h ].first != j && w[ h ].second != j ) {
                        printf ( "YES\n" ) ;
                        printf ( "%d %d %d %d\n" , w[ h ].first , w[ h ].second , i , j ) ;
                        return ;
                    }
                }
            }
        }
    }
    printf ( "NO\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}