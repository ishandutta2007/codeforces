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

#define MAXK 77
#define MAXN 4007
#define MOD 998244353


int n[ 2 ] , k ;
vector < int > v[ 2 ][ MAXN ] ;

long long cycles[ 2 ][ MAXN ][ MAXK ] ;

int subtree[ 2 ][ MAXN ] ;
int used[ 2 ][ MAXN ] ;

long long path[ 2 ][ MAXN ][ MAXK ] ;
long long dp[ 2 ][ MAXN ][ MAXK ] ;

long long total_cycles[ 2 ][ MAXK ] ;

long long fac[ MAXK ] ;
long long inv[ MAXK ] ;

void calc_subtrees ( int id , int vertex , int prv ) {
    int sz = v[ id ][ vertex ].size ( ) ;
    subtree[ id ][ vertex ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ id ][ vertex ][ i ] == prv ) { continue ; }
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        calc_subtrees ( id , v[ id ][ vertex ][ i ] , vertex ) ;
        subtree[ id ][ vertex ] += subtree[ id ][ v[ id ][ vertex ][ i ] ] ;
    }
}

int get_centroid ( int id , int vertex , int prv , int comp_size ) {
    int sz = v[ id ][ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ id ][ vertex ][ i ] == prv ) { continue ; }
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        if ( subtree[ id ][ v[ id ][ vertex ][ i ] ] > comp_size / 2 ) {
            return get_centroid ( id , v[ id ][ vertex ][ i ] , vertex , comp_size ) ;
        }
    }
    return vertex ;
}

void reset ( int id , int vertex , int prv ) {
    int sz = v[ id ][ vertex ].size ( ) ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        path[ id ][ vertex ][ i ] = dp[ id ][ vertex ][ i ] = 0 ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ id ][ vertex ][ i ] == prv ) { continue ; }
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        reset ( id , v[ id ][ vertex ][ i ] , vertex ) ;
    }
}

void fill_path ( int id , int vertex , int prv , int len ) {
    int sz = v[ id ][ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        path[ id ][ v[ id ][ vertex ][ i ] ][ len + 1 ] =
            ( path[ id ][ v[ id ][ vertex ][ i ] ][ len + 1 ] + path[ id ][ vertex ][ len ] ) % MOD ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ id ][ vertex ][ i ] == prv ) { continue ; }
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        fill_path ( id , v[ id ][ vertex ][ i ] , vertex , len ) ;
    }
}

void fill_dp ( int id , int vertex , int prv , int len , int cen ) {
    int sz = v[ id ][ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 && v[ id ][ vertex ][ i ] != cen ) { continue ; }
        dp[ id ][ v[ id ][ vertex ][ i ] ][ len + 1 ] =
            ( dp[ id ][ v[ id ][ vertex ][ i ] ][ len + 1 ] + dp[ id ][ vertex ][ len ] ) % MOD ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ id ][ vertex ][ i ] == prv ) { continue ; }
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        fill_dp ( id , v[ id ][ vertex ][ i ] , vertex , len , cen ) ;
    }
}

void combine ( int id , int vertex , int prv ) {
    int sz = v[ id ][ vertex ].size ( ) ;
    for ( int j = 0 ; j <= k ; ++ j ) {
        for ( int t = 0 ; j + t <= k ; ++ t ) {
            cycles[ id ][ vertex ][ j + t ] =
                ( cycles[ id ][ vertex ][ j + t ] + path[ id ][ vertex ][ j ] * dp[ id ][ vertex ][ t ] ) % MOD ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ id ][ vertex ][ i ] == prv ) { continue ; }
        if ( used[ id ][ v[ id ][ vertex ][ i ] ] != 0 ) { continue ; }
        combine ( id , v[ id ][ vertex ][ i ] , vertex ) ;
    }

}

void decompose ( int id , int vertex ) {
    calc_subtrees ( id , vertex , -1 ) ;
    int cen = get_centroid ( id , vertex , -1 , subtree[ id ][ vertex ] ) ;
    used[ id ][ cen ] = 1 ;
    int sz = v[ id ][ cen ].size ( ) ;

    reset ( id , cen , -1 ) ;
    path[ id ][ cen ][ 0 ] = dp[ id ][ cen ][ 0 ] = 1 ;

    for ( int len = 0 ; len < k ; ++ len ) {
        fill_path ( id , cen , -1 , len ) ;
        fill_dp ( id , cen , -1 , len , cen ) ;
    }

    combine ( id , cen , -1 ) ;

    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ id ][ v[ id ][ cen ][ i ] ] != 0 ) { continue ; }
        decompose ( id , v[ id ][ cen ][ i ] ) ;
    }
}

void calc ( int id ) {
    decompose ( id , 1 ) ;
    for ( int i = 1 ; i <= n[ id ] ; ++ i ) {
        for ( int j = 0 ; j <= k ; ++ j ) {
            total_cycles[ id ][ j ] =
                ( total_cycles[ id ][ j ] + cycles[ id ][ i ][ j ] ) % MOD ;
        }
    }
}


long long fastpow ( long long x , long long n ) {
    long long ret = 1 ;
    while ( n > 0 ) {
        if ( ( n % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            n /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- n ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n[ 0 ] , &n[ 1 ] , &k ) ;
    for ( int j = 0 ; j < 2 ; ++ j ) {
        for ( int i = 1 ; i < n[ j ] ; ++ i ) {
            int x , y ;
            scanf ( "%d%d" , &x , &y ) ;
            v[ j ][ x ].push_back ( y ) ;
            v[ j ][ y ].push_back ( x ) ;
        }
    }
}

void solve ( ) {
    calc ( 0 ) , calc ( 1 ) ;
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ k ] = fastpow ( fac[ k ] , MOD - 2 ) ;
    for ( int i = k - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }
    long long ans = 0 ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        long long aux = ( total_cycles[ 0 ][ i ] * total_cycles[ 1 ][ k - i ] ) % MOD ;
        aux = ( aux * fac[ k ] ) % MOD ;
        aux = ( aux * inv[ i ] ) % MOD ;
        aux = ( aux * inv[ k - i ] ) % MOD ;
        ans = ( ans + aux ) % MOD ;
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