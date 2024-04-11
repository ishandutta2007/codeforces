#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 507
#define MOD 998244353

int n ;
int a[ MAXN ] ;

int pos[ MAXN ] ;
int mn_val[ MAXN ][ MAXN ] ;

long long dp[ MAXN ][ MAXN ] ;
bool vis[ MAXN ][ MAXN ] ;


void calc ( int st , int en ) {
    if ( vis[ st ][ en ] == true ) { return ; }
    vis[ st ][ en ] = true ;
    if ( st == en ) { dp[ st ][ en ] = 1 ; return ; }
    int aux = pos[ mn_val[ st ][ en ] ] ;
    for ( int i = st ; i <= aux ; ++ i ) {
        if ( i != st ) {
            calc ( st , i - 1 ) ;
        }
        if ( i != aux ) {
            calc ( i , aux - 1 ) ;
        }
    }
    for ( int j = aux ; j <= en ; ++ j ) {
        if ( j != en ) {
            calc ( j + 1 , en ) ;
        }
        if ( j != aux ) {
            calc ( aux + 1 , j ) ;
        }
    }
    long long l = 0 ;
    for ( int i = st ; i <= aux ; ++ i ) {
        long long add = 1 ;
        if ( i != st ) {
            add *= dp[ st ][ i - 1 ] ;
            if ( add >= MOD ) {
                add %= MOD ;
            }
        }
        if ( i != aux ) {
            add *= dp[ i ][ aux - 1 ] ;
            if ( add >= MOD ) {
                add %= MOD ;
            }
        }
        l += add ;
        if ( l >= MOD ) {
            l -= MOD ;
        }
    }
    long long r = 0 ;
    for ( int j = aux ; j <= en ; ++ j ) {
        long long add = 1 ;
        if ( j != en ) {
            add *= dp[ j + 1 ][ en ] ;
            if ( add >= MOD ) {
                add %= MOD ;
            }
        }
        if ( j != aux ) {
            add *= dp[ aux + 1 ][ j ] ;
            if ( add >= MOD ) {
                add %= MOD ;
            }
        }
        r += add ;
        if ( r >= MOD ) {
            r -= MOD ;
        }
    }
    dp[ st ][ en ] = ( l * r ) % MOD ;
}

void input ( ) {
    int foo ;
    scanf ( "%d%d" , &n , &foo ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i ; j <= n ; ++ j ) {
            if ( i == j ) { mn_val[ i ][ j ] = a[ i ] ; }
            else {
                mn_val[ i ][ j ] = min ( mn_val[ i ][ j - 1 ] , a[ j ] ) ;
            }
        }
    }
}

void solve ( ) {
    calc ( 1 , n ) ;
    printf ( "%I64d\n" , dp[ 1 ][ n ] ) ;
}

int main ( ) {
    ///freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}