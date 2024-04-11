#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
long long a[ MAXN ] ;
int aux[ MAXN ] ;

long long ans = 0 ;

priority_queue < pair < long long , int > > q ;

long long cost ( long long val , int cnt ) {
    long long x = ( val / cnt ) ;
    long long lft = val - x * cnt ;
    return x * x * ( cnt - lft ) + ( x + 1 ) * ( x + 1 ) * lft ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
        aux[ i ] = 1 ;
        ans += a[ i ] * a[ i ] ;
        if ( a[ i ] >= 2 ) {
            q.push ( { a[ i ] * a[ i ] - cost ( a[ i ] , 2 ) , i } ) ;
        }
    }
}

void solve ( ) {
    k -= n ;
    while ( k > 0 && q.empty ( ) == false ) {
        -- k ;
        auto foo = q.top ( ) ;
        long long x = foo.first ; int y = foo.second ;
        q.pop ( ) ;
        ans -= x ;
        ++ aux[ y ] ;
        if ( a[ y ] > aux[ y ] ) {
            q.push ( { cost ( a[ y ] , aux[ y ] ) - cost ( a[ y ] , aux[ y ] + 1 ) , y } ) ;
        }
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