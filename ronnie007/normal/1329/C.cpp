#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2000007

int n ;
int h , g ;
int a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

bool full[ MAXN ] ;
bool used[ MAXN ] ;

long long ans ;

void input ( ) {
    scanf ( "%d%d" , &h , &g ) ;
    n = (1<<h) - 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        b[ i ] = { a[ i ] , i } ;
        used[ i ] = full[ i ] = false ;
    }
}

void solve ( ) {
    sort ( b + 1 , b + n + 1 ) ;
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int id = b[ i ].second ;
        while ( id > 0 ) {
            if ( id <= (1<<g) - 1 && full[ id ] == false ) { break ; }
            id /= 2 ;
        }
        if ( 2 * id >= (1<<g) || full[ 2 * id ] == true ) {
            if ( 2 * id + 1 >= (1<<g) || full[ 2 * id + 1 ] == true ) {
                full[ id ] = true ;
                used[ b[ i ].second ] = true ;
                ans += b[ i ].first ;
            }
        }
    }
    printf ( "%I64d\n" , ans ) ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( used[ i ] == false ) {
            printf ( "%d " , i ) ;
        }
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}