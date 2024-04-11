#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<random>
using namespace std ;

#define MAXN 200007

int n ;
long long a[ MAXN ] ;

mt19937 rng ( time ( 0 ) ) ;

long long ans = MAXN ;

void upd ( long long x ) {
    long long aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long ost = ( a[ i ] % x ) ;
        if ( ost == a[ i ] ) {
            aux += x - a[ i ] ;
        }
        else {
            aux += min ( ost , x - ost ) ;
        }
    }
    ans = min ( ans , aux ) ;
}

void calc ( long long x ) {
    long long aux = 2 ;
    while ( aux * aux <= x ) {
        if ( ( x % aux ) == 0 ) {
            while ( ( x % aux ) == 0 ) {
                x /= aux ;
            }
            upd ( aux ) ;
        }
        ++ aux ;
    }
    if ( x > 1 ) { upd ( x ) ; }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int cnt = 50 ;
    while ( cnt -- ) {
        int id = rng ( ) % n ;
        ++ id ;
        calc ( a[ id ] ) ;
        if ( a[ id ] > 1 ) { calc ( a[ id ] - 1 ) ; }
        calc ( a[ id ] + 1 ) ;
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