#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int sm ;

long long dp[ MAXN ][ MAXN * MAXN ] ;

void add ( int val , int cnt ) {
    for ( int j = n - 1 ; j >= 0 ; -- j ) {
        for ( int i = sm - 1 ; i >= 0 ; -- i ) {
            if ( dp[ j ][ i ] == 0 ) { continue ; }
            for ( int z = 1 ; z <= cnt ; ++ z ) {
                if ( i + z * val > sm ) { break ; }
                if ( j + z > n ) { break ; }
                dp[ j + z ][ i + z * val ] += dp[ j ][ i ] ;
                if ( dp[ j + z ][ i + z * val ] > 1 ) {
                    dp[ j + z ][ i + z * val ] = 2 ;
                }
            }
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        sm += a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int ans = 0 ;
    int x = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        x += ( a[ i ] != a[ i - 1 ] ) ;
    }
    if ( x <= 1 ) {
        printf ( "%d\n" , n ) ;
        return ;
    }
    dp[ 0 ][ 0 ] = 1 ; 
    x = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) { ++ x ; }
        else {
            add ( a[ i - 1 ] , x ) ;
            x = 1 ;
        }
    }
    add ( a[ n ] , x ) ;
    x = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) { ++ x ; }
        else {
            for ( int j = 1 ; j <= x ; ++ j ) {
                if ( dp[ j ][ j * a[ i - 1 ] ] == 1 ) {
                    ans = max ( ans , j ) ;
                }
            }
            x = 1 ;
        }
    }
    for ( int j = 1 ; j <= x ; ++ j ) {
        if ( dp[ j ][ j * a[ n ] ] == 1 ) {
            ans = max ( ans , j ) ;
        }
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