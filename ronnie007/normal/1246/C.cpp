#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std ;

#define MAXN 2007
#define MOD 1000000007

int n , m ;
string a[ MAXN ] ;

long long st[ MAXN ][ MAXN ] ;
long long en[ MAXN ][ MAXN ] ;

long long add[ MAXN ][ MAXN ] ;
long long sweep[ MAXN ] ;

long long qw[ MAXN ] ;

long long endrw[ MAXN ][ MAXN ] ;
long long endcl[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = m - 1 ; j >= 0 ; -- j ) {
            endrw[ i ][ j ] = endrw[ i ][ j + 1 ] + ( a[ i ][ j ] == 'R' ) ;
        }
    }
    for ( int j = 0 ; j < m ; ++ j ) {
        for ( int i = n - 1 ; i >= 0 ; -- i ) {
            endcl[ i ][ j ] = endcl[ i + 1 ][ j ] + ( a[ i ][ j ] == 'R' ) ;
        }
    }
    for ( int i = 0 ; i < n - endcl[ 0 ][ 0 ] ; ++ i ) {
        st[ i ][ 0 ] = 1 ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= m ; ++ j ) {
            qw[ j ] = 0 ;
        }
        for ( int j = 0 ; j < m ; ++ j ) {
            sweep[ j ] = ( sweep[ j ] + add[ i ][ j ] + MOD ) % MOD ;
            st[ i ][ j ] = ( st[ i ][ j ] + sweep[ j ] ) % MOD ;
            ///printf ( "st[ %d ][ %d ] = %I64d\n" , i , j , st[ i ][ j ] ) ;
            int mx = m - endrw[ i ][ j + 1 ] ;
            ///printf ( "--- %d\n" , mx ) ;
            qw[ j + 1 ] = ( st[ i ][ j ] + qw[ j + 1 ] ) % MOD ;
            qw[ mx ] = ( qw[ mx ] - st[ i ][ j ] + MOD ) % MOD ;
        }
        long long cnt = 0 ;
        for ( int j = 0 ; j < m ; ++ j ) {
            cnt = ( cnt + qw[ j ] + MOD ) % MOD ;
            ///printf ( "%I64d " , cnt ) ;
            en[ i ][ j ] = cnt ;
            ///printf ( "en[ %d ][ %d ] = %I64d\n" , i , j , en[ i ][ j ] ) ;
            int mx = n - endcl[ i + 1 ][ j ] ;
            ///printf ( "--- %d\n" , mx ) ;
            add[ i + 1 ][ j ] = ( add[ i + 1 ][ j ] + en[ i ][ j ] ) % MOD ;
            add[ mx ][ j ] = ( add[ mx ][ j ] - en[ i ][ j ] + MOD ) % MOD ;
        }
        ///printf ( "\n" ) ;
    }
    printf ( "%I64d\n" , ( en[ n - 1 ][ m - 1 ] + st[ n - 1 ][ m - 1 ] ) % MOD ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}