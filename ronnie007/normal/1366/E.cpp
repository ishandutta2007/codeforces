#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;

map < int , int > lst ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        lst[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= k ; ++ i ) {
        if ( lst.find ( b[ i ] ) == lst.end ( ) ) {
            printf ( "0\n" ) ;
            return ;
        }
        if ( i < k && lst[ b[ i ] ] > lst[ b[ i + 1 ] ] ) {
            printf ( "0\n" ) ;
            return ;
        }
    }
    int aux = n ;
    long long ans = 1 ;
    for ( int i = k ; i >= 1 ; -- i ) {
        int sr = lst[ b[ i ] ] ;
        int init = aux ;
        while ( aux > sr ) {
            if ( a[ aux ] < b[ i ] ) {
                printf ( "0\n" ) ;
                return ;
            }
            -- aux ;
        }
        if ( 0 < i && i < k ) {
            long long coef = 1 ;
            while ( init > sr ) {
                if ( a[ init ] < b[ i + 1 ] ) { break ; }
                ++ coef ; -- init ;
            }
            ans = ( ans * coef ) % MOD ;
        }
        -- aux ;
    }
    while ( aux > 0 ) {
        if ( a[ aux ] < b[ 1 ] ) {
            printf ( "0\n" ) ;
            return ;
        }
        -- aux ;
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}