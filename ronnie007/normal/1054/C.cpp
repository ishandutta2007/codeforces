#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int val[ MAXN ] ;

map < int , int > w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        w[ a[ i ] + b[ i ] ] = 1 ;
    }
    int id = 0 ;
    for ( auto it = w.begin ( ) ; it != w.end ( ) ; ++ it ) {
        it->second = ++ id ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        val[ i ] = n + 1 - w[ a[ i ] + b[ i ] ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( val[ j ] > val[ i ] ) {
                if ( j < i ) { -- a[ i ] ; }
                else { -- b[ i ] ; }
            }
        }
        if ( a[ i ] != 0 || b[ i ] != 0 ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    printf ( "YES\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , val[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}