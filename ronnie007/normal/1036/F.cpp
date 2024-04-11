#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<stack>
using namespace std ;

int q ;
long long n ;

long long lim ;

bool use[ 72 ] ;
int divs[ 72 ] ;

long long precalc[ 107 ][ 72 ] ;

void init ( ) {
    int i , j ;
    for ( i = 2 ; i <= 70 ; i ++ ) {
        for ( j = 2 ; j <= i ; j ++ ) {
            int br = 0 ;
            int aux = i ;
            while ( ( aux % j ) == 0 ) { aux /= j ; br ++ ; }
            if ( br >= 2 ) { break ; }
        }
        if ( j > i ) { use[ i ] = true ; }
    }
    for ( i = 2 ; i <= 70 ; i ++ ) {
        if ( divs[ i ] != 0 ) { continue ; }
        divs[ i ] ++ ;
        for ( j = 2 * i ; j <= 70 ; j += i ) {
            divs[ j ] ++ ;
        }
    }
    lim = 1 ;
    for ( i = 1 ; i <= 18 ; i ++ ) { lim *= 10 ; }
    lim += 2 ;
    for ( i = 1 ; i <= 100 ; i ++ ) {
        long long tot = 1 ;
        for ( j = 1 ; j <= 70 ; j ++ ) {
            if ( ( lim / i ) < tot ) { precalc[ i ][ j ] = -1 ; continue ; }
            tot *= i ;
            precalc[ i ][ j ] = tot ;
        }
    }
}

bool check ( long long val , int st ) {
    if ( val <= 100 ) {
        if ( precalc[ val ][ st ] == -1 ) { return false ; }
        if ( precalc[ val ][ st ] > n ) { return false ; }
        return true ;
    }
    int i ;
    long long tot = 1 ;
    for ( i = 1 ; i <= st ; i ++ ) {
        if ( ( n / val ) < tot ) { return false ; }
        tot *= val ;
    }
    return true ;
}

long long get ( int st , long long lst ) {
    long long l , r , mid ;
    l = 1 ;
    if ( lst == -1 ) {
        r = 2 ;
        for ( int i = 1 ; i <= 9 ; i ++ ) { r *= 10 ; }
    }
    else { r = lst ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( check ( mid , st ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( check ( r , st ) == false ) { r -- ; }
    return r ;
}

void calc ( ) {
    int i ;
    long long ret = 0 ;
    long long lst = -1 ;
    for ( i = 2 ; i <= 70 ; i ++ ) {
        if ( use[ i ] == false ) { continue ; }
        long long aux = ( get ( i , lst ) - 1 ) ;
        lst = aux + 1 ;
        if ( ( divs[ i ] % 2 ) == 0 ) { aux *= -1 ; }
        ret += aux ;
    }
    printf ( "%I64d\n" , ( n - ret - 1 ) ) ;
}

void input ( ) {
    scanf ( "%d" , &q ) ;
    init ( ) ;
}

void solve ( ) {
    while ( q != 0 ) {
        q -- ;
        scanf ( "%I64d" , &n ) ;
        calc ( ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}