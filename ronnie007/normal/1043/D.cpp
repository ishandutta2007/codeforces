#include<iostream>
#include<stdio.h>
using namespace std ;

#define MOD1 1000000007
#define MOD2 1000003
#define BASE 100007

#define MAXN 100007
#define MAXK 12

pair < long long , long long > h[ MAXK ][ MAXN ] ;




int n , m ;
int a[ MAXK ][ MAXN ] ;

int pos[ MAXK ][ MAXN ] ;

long long base_st1[ MAXN ] ;
long long base_st2[ MAXN ] ;


bool f ( int stval , int len ) {
    pair < long long , long long > sr ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int st = pos[ i ][ stval ] ;
        pair < long long , long long > aux1 = h[ i ][ st + len - 1 ] ;
        pair < long long , long long > aux2 = h[ i ][ st - 1 ] ;
        aux2.first = ( aux2.first * base_st1[ len ] ) % MOD1 ;
        aux2.second = ( aux2.second * base_st2[ len ] ) % MOD2 ;
        aux1.first = ( aux1.first + MOD1 - aux2.first ) % MOD1 ;
        aux1.second = ( aux1.second + MOD2 - aux2.second ) % MOD2 ;
        if ( i == 1 ) { sr = aux1 ; }
        else {
            if ( sr.first != aux1.first ) { return false ; }
            if ( sr.second != aux1.second ) { return false ; }
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 1 ; i <= m ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
            pos[ i ][ a[ i ][ j ] ] = j ;
            h[ i ][ j ].first = ( h[ i ][ j - 1 ].first * BASE + a[ i ][ j ] ) % MOD1 ;
            h[ i ][ j ].second = ( h[ i ][ j - 1 ].second * BASE + a[ i ][ j ] ) % MOD2 ;
        }
    }
    base_st1[ 0 ] = base_st2[ 0 ] = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        base_st1[ i ] = ( BASE * base_st1[ i - 1 ] ) % MOD1 ;
        base_st2[ i ] = ( BASE * base_st2[ i - 1 ] ) % MOD2 ;
    }
}

void solve ( ) {
    int i , j ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int l , r , mid ;
        int mx = 0 ;
        for ( j = 1 ; j <= m ; j ++ ) {
            if ( pos[ j ][ i ] > mx ) { mx = pos[ j ][ i ] ; }
        }
        l = 1 ;
        r = ( n - mx + 1 ) ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            if ( f ( i , mid ) == true ) { l = mid ; }
            else { r = mid ; }
        }
        while ( f ( i , r ) == false ) { r -- ; }
        ans += r ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}