#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2000007

int n ;
int a[ MAXN ] ;

pair < int , int > f[ MAXN ] ;

void add ( pair < int , int > &x , int val ) {
    if ( val > x.first ) {
        x.second = x.first ;
        x.first = val ;
    }
    else if ( val > x.second ) {
        x.second = val ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        f[ i ] = { -1 , -1 } ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        add ( f[ a[ i ] ] , i ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 21 ; ++ i ) {
        int h = (1<<i) ;
        for ( int j = 0 ; j + h < MAXN ; ++ j ) {
            if ( ( j & h ) == 0 ) {
                add ( f[ j ] , f[ j + h ].first ) ;
                add ( f[ j ] , f[ j + h ].second ) ;
            }
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = 0 ;
        for ( int j = 20 ; j >= 0 ; -- j ) {
            if ( ( a[ i ] & (1<<j) ) > 0 ) { continue ; }
            if ( aux + (1<<j) < MAXN ) {
                if ( f[ aux + (1<<j) ].second > i ) {
                    aux += (1<<j) ;
                }
            }
        }
        if ( f[ aux ].second <= i ) { continue ; }
        ans = max ( ans , a[ i ] + aux ) ;
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}