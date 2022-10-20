#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 57

int n ;
string a[ MAXN ] ;

int dp[ MAXN ][ MAXN ][ MAXN ][ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;

inline int f ( int lx , int ly , int hx , int hy ) {
    return pref[ hx ][ hy ] - pref[ lx - 1 ][ hy ] - pref[ hx ][ ly - 1 ] + pref[ lx - 1 ][ ly - 1 ] ;
}

void dfs ( int lx , int ly , int hx , int hy ) {
    if ( hx < lx || hy < ly ) { return ; }
    if ( f ( lx , ly , hx , hy ) == 0 ) { return ; }
    if ( dp[ lx ][ ly ][ hx ][ hy ] != 0 ) { return ; }
    dp[ lx ][ ly ][ hx ][ hy ] = max ( hx - lx + 1 , hy - ly + 1 ) ;
    for ( int i = lx ; i <= hx ; ++ i ) {
        if ( f ( i , ly , i , hy ) != 0 ) { continue ; }
        dfs ( lx , ly , i - 1 , hy ) ;
        dfs ( i + 1 , ly , hx , hy ) ;
        int curr = dp[ lx ][ ly ][ i - 1 ][ hy ] + dp[ i + 1 ][ ly ][ hx ][ hy ] ;
        if ( dp[ lx ][ ly ][ hx ][ hy ] > curr ) {
            dp[ lx ][ ly ][ hx ][ hy ] = curr ;
        }
    }
    for ( int i = ly ; i <= hy ; ++ i ) {
        if ( f ( lx , i , hx , i ) != 0 ) { continue ; }
        dfs ( lx , ly , hx , i - 1 ) ;
        dfs ( lx , i + 1 , hx , hy ) ;
        int curr = dp[ lx ][ ly ][ hx ][ i - 1 ] + dp[ lx ][ i + 1 ][ hx ][ hy ] ;
        if ( dp[ lx ][ ly ][ hx ][ hy ] > curr ) {
            dp[ lx ][ ly ][ hx ][ hy ] = curr ;
        }
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '@' + a[ i ] ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            pref[ i ][ j ] = ( a[ i ][ j ] == '#' ) + pref[ i - 1 ][ j ] + pref[ i ][ j - 1 ] - pref[ i - 1 ][ j - 1 ] ;
        }
    }
}

void solve ( ) {
    dfs ( 1 , 1 , n , n ) ;
    printf ( "%d\n" , dp[ 1 ][ 1 ][ n ][ n ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}