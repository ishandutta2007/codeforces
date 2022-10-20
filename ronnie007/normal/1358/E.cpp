#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
int st ;
int a[ MAXN ] ;
int x ;

long long suff[ MAXN ] ;
long long mn[ MAXN ] ;



void input ( ) {
    scanf ( "%d" , &n ) ;
    st = ( n / 2 ) + ( n % 2 ) ;
    for ( int i = 1 ; i <= st ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &x ) ;
}

void solve ( ) {
    if ( x > 0 ) {
        long long sm = 0 ;
        for ( int i = 1 ; i <= st ; ++ i ) {
            sm += a[ i ] ;
        }
        sm += 1LL * ( n - st ) * x ;
        if ( sm <= 0 ) { printf ( "-1\n" ) ; }
        else { printf ( "%d\n" , n ) ; }
        return ;
    }
    for ( int i = st ; i >= 1 ; -- i ) {
        suff[ i ] = suff[ i + 1 ] + ( a[ i ] - x ) ;
    }
    for ( int i = 1 ; i <= st ; ++ i ) {
        if ( i == 1 ) { mn[ i ] = suff[ i ] ; continue ; }
        mn[ i ] = min ( mn[ i - 1 ] , suff[ i ] ) ;
    }
    for ( int i = st ; i >= 1 ; -- i ) {
        long long init = 1LL * ( n - st ) * x ;
        init += suff[ i ] + 1LL * ( st - i + 1 ) * x ;
        if ( init <= 0 ) { continue ; }
        if ( i > 1 && init + mn[ i - 1 ] - suff[ i ] <= 0 ) { continue ; }
        printf ( "%d\n" , ( st - i + 1 ) + ( n - st ) ) ;
        return ;
    }
    printf ( "-1\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}