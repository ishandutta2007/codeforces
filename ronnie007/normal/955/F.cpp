#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#define LOG 21 

int n ;
vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;

int cnt[ MAXN ] ;

int f[ MAXN ][ LOG ] ;
int dp[ MAXN ][ LOG ] ;

long long ans = 0 ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    lvl[ vertex ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( h == prv ) { continue ; }
        dfs ( h , vertex ) ;
        lvl[ vertex ] = max ( lvl[ vertex ] , lvl[ h ] + 1 ) ;
        for ( int j = 1 ; j < LOG ; ++ j ) {
            dp[ vertex ][ j ] = max ( dp[ vertex ][ j ] , dp[ h ][ j ] ) ;
        }
    }
    ans += lvl[ vertex ] ;
    f[ vertex ][ 1 ] = n ; 
    for ( int j = 2 ; j < LOG ; ++ j ) {
        for ( int i = 0 ; i < sz ; ++ i ) {
            int h = v[ vertex ][ i ] ;
            if ( h == prv ) { continue ; }
            if ( f[ h ][ j - 1 ] <= sz ) {
                ++ cnt[ f[ h ][ j - 1 ] ] ;
            }
            else {
                ++ cnt[ sz ] ;
            }
        }
        int suff = 0 ;
        for ( int i = sz ; i >= 0 ; -- i ) {
            suff += cnt[ i ] ;
            if ( suff >= i ) {
                f[ vertex ][ j ] = i ;
                break ;
            }
        }
        for ( int i = 0 ; i <= sz ; ++ i ) {
            cnt[ i ] = 0 ;
        }
    }
    int lst = 1 ;
    for ( int j = LOG - 1 ; j >= 0 ; -- j ) {
        dp[ vertex ][ j ] = max ( dp[ vertex ][ j ] , f[ vertex ][ j ] ) ;
        if ( dp[ vertex ][ j ] > lst ) {
            ans += 1LL * ( dp[ vertex ][ j ] - lst ) * j ;
            lst = dp[ vertex ][ j ] ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}