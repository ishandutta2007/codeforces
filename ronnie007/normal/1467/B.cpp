#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;

int pref[ MAXN ] ;
int suff[ MAXN ] ;

bool fl[ MAXN ] ;

int ans ;

vector < int > aux ;
int vec_sz ;

int calc ( ) {
    int ret = 0 ;
    for ( int i = 1 ; i < vec_sz - 1 ; ++ i ) {
        if ( aux[ i ] > aux[ i - 1 ] && aux[ i ] > aux[ i + 1 ] ) { ret += 1 ; }
        if ( aux[ i ] < aux[ i - 1 ] && aux[ i ] < aux[ i + 1 ] ) { ret += 1 ; }        
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    fl[ 1 ] = fl[ n ] = false ;
    for ( int i = 2 ; i < n ; ++ i ) {
        fl[ i ] = false ;
        if ( a[ i ] > a[ i - 1 ] && a[ i ] > a[ i + 1 ] ) { fl[ i ] = true ; }
        if ( a[ i ] < a[ i - 1 ] && a[ i ] < a[ i + 1 ] ) { fl[ i ] = true ; }
    }
    pref[ 0 ] = suff[ n + 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] ;
        if ( fl[ i ] == true ) { pref[ i ] += 1 ; }
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        suff[ i ] = suff[ i + 1 ] ;
        if ( fl[ i ] == true ) { suff[ i ] += 1 ; }
    }
}

void solve ( ) {
    ans = pref[ n ] ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        vector < int > pts ;
        if ( i > 1 ) {
            pts.push_back ( a[ i - 1 ] - 1 ) ;
            pts.push_back ( a[ i - 1 ] + 1 ) ;
            pts.push_back ( a[ i - 1 ] ) ;
        }
        if ( i < n ) {
            pts.push_back ( a[ i + 1 ] - 1 ) ;
            pts.push_back ( a[ i + 1 ] + 1 ) ;
            pts.push_back ( a[ i + 1 ] ) ;            
        }
        pts.push_back ( a[ i ] ) ;
        int ori_id = -1 ;
        int init = 0 ;        
        aux.clear ( ) ;
        if ( i >= 3 ) {
            aux.push_back ( a[ i - 2 ] ) ;
            init += pref[ i - 2 ] ;
        }
        if ( i >= 2 ) {
            aux.push_back ( a[ i - 1 ] ) ;
        }
        ori_id = aux.size ( ) ;
        aux.push_back ( 0 ) ;
        if ( i + 1 <= n ) {
            aux.push_back ( a[ i + 1 ] ) ;
        }
        if ( i + 2 <= n ) {
            aux.push_back ( a[ i + 2 ] ) ;
            init += suff[ i + 2 ] ;
        }
        vec_sz = aux.size ( ) ;
        for ( auto x : pts ) {
            aux[ ori_id ] = x ;
            int sr = init + calc ( ) ;
            ans = min ( ans , sr ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}