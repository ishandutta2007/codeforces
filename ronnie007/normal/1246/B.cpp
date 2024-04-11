#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
long long cnt[ MAXN ] ;

long long sr ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ cnt[ a[ i ] ] ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    if ( k == 2 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            cnt[ a[ i ] ] = 0 ;
        }
        for ( int i = 2 ; i <= 320 ; ++ i ) {
            for ( int j = 1 ; j <= n ; ++ j ) {
                while ( ( a[ j ] % ( i * i ) ) == 0 ) {
                    a[ j ] /= ( i * i ) ;
                }
            }
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            ans += cnt[ a[ i ] ] ;
            ++ cnt[ a[ i ] ] ;
        }
        printf ( "%I64d\n" , ans ) ;
        return ;
    }
    sr = MAXN ;
    sr *= MAXN ;
    for ( int i = 1 ; i <= 2500 ; ++ i ) {
        long long aux = 1 ;
        for ( int j = 0 ; j < k ; ++ j ) {
            aux *= i ;
            if ( aux > sr ) { break ; }
        }
        if ( aux > sr ) { break ; }
        for ( int j = 1 ; j <= 100000 ; ++ j ) {
            if ( ( aux % j ) == 0 ) {
                long long hh = ( aux / j ) ;
                if ( hh <= 100000 ) {
                    if ( hh != j ) {
                        ans += 1LL * cnt[ j ] * cnt[ hh ] ;
                    }
                    else {
                        ans += 1LL * cnt[ j ] * ( cnt[ j ] - 1 ) ;
                    }
                }
            }
        }
    }
    ans /= 2 ;
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}