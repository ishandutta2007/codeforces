#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
int n , m , k ;

bool fl[ MAXN ] ;
pair < int , int > sw[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        fl[ x ] = true ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        scanf ( "%d%d" , &sw[ i ].first , &sw[ i ].second ) ;
    }
}

void solve ( ) {
    int pos = 1 ;
    if ( fl[ pos ] == true ) {
        printf ( "%d\n" , pos ) ;
        return ;
    }
    for ( auto [ x , y ] : sw ) {
        if ( x == pos ) { pos = y ; }
        else if ( y == pos ) { pos = x ; }
        if ( fl[ pos ] == true ) {
            printf ( "%d\n" , pos ) ;
            return ;
        }
    }
    printf ( "%d\n" , pos ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}