#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007
#define MAGIC 700

int n , k ;
int a[ MAXN ] ;
vector < int > v ;
int used[ MAXN ] ;

bitset < 1000001> dp ;
int lft[ MAXN ] ;
int tot[ MAGIC + 1 ] ;

int solve_min ( ) {
    int sz = v.size ( ) ;
    dp[ 0 ] = true ;
    int sm = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( dp[ k ] == true ) { break ; }
        sm += v[ i ] ;
        if ( v[ i ] >= MAGIC ) {
            dp |= ( dp << v[ i ] ) ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ i ] < MAGIC ) {
            if ( tot[ v[ i ] ] == 0 ) { continue ; }
            for ( int j = 0 ; j < v[ i ] ; ++ j ) {
                if ( dp[ j ] == true ) {
                    lft[ j ] = tot[ v[ i ] ] ;
                }
                else {
                    lft[ j ] = 0 ;
                }
            }
            for ( int j = v[ i ] ; j <= sm ; ++ j ) {
                if ( dp[ j ] == true ) {
                    lft[ j ] = tot[ v[ i ] ] ;
                }
                else {
                    if ( lft[ j - v[ i ] ] > 0 ) {
                        dp[ j ] = true ;
                        lft[ j ] = lft[ j - v[ i ] ] - 1 ;
                    }
                    else {
                        lft[ j ] = 0 ;
                    }
                }
            }
            tot[ v[ i ] ] = 0 ;
        }
    }
    if ( dp[ k ] == true ) { return k ; }
    return k + 1 ; 
}

int solve_max ( ) {
    int sz = v.size ( ) ;
    int ret = 0 ;
    int aux = k ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int x = v[ i ] ;
        while ( aux > 0 && x >= 2 ) {
            -- aux ;
            x -= 2 ;
            ret += 2 ;
        }
    }
    return min ( n , ret + aux ) ;
}
void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 1 ) { continue ; }
        int x = i ;
        int cnt = 0 ;
        while ( 1 ) {
            used[ x ] = 1 ;
            x = a[ x ] ;
            ++ cnt ;
            if ( x == i ) { break ; }
        }
        v.push_back ( cnt ) ;
        if ( cnt < MAGIC ) { ++ tot[ cnt ] ; }
    }
    printf ( "%d %d\n" , solve_min ( ) , solve_max ( ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}