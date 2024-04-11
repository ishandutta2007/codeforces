#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , q ;
vector < int > v[ MAXN ] ;

int comp[ MAXN ] ;
int comp_sz[ MAXN ] ;
int dist[ MAXN ] ;

int diam[ MAXN ] ;
vector < int > suff_cnt[ MAXN ] ;
vector < long long > suff_sm[ MAXN ] ;

map < pair < int , int > , double > ww ;

int get ( int st , bool fl ) {
    queue < pair < pair < int , int > , int > > q ;
    q.push ( { { st , 0 } , -1 } ) ;
    int ret ;
    while ( q.empty ( ) == false ) {
        pair < pair < int , int > , int > hh = q.front ( ) ;
        q.pop ( ) ;
        int vertex = hh.first.first ;
        int d = hh.first.second ;
        int lst = hh.second ;
        int sz = v[ vertex ].size ( ) ;
        ret = vertex ;
        if ( fl == true ) {
            comp[ vertex ] = st ;
        }
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( v[ vertex ][ i ] == lst ) { continue ; }
            dist[ v[ vertex ][ i ] ] = max ( dist[ v[ vertex ][ i ] ] , d + 1 ) ;
            q.push ( { { v[ vertex ][ i ] , d + 1 } , vertex } ) ;
        }
    }
    return ret ;
}

void prep ( int st ) {
    int h1 = get ( st , true ) ;
    int h2 = get ( h1 , false ) ;
    get ( h2 , false ) ;
    diam[ st ] = dist[ h2 ] ;

    suff_cnt[ st ].resize ( diam[ st ] + 1 ) ;
    suff_sm[ st ].resize ( diam[ st ] + 1 ) ;
}

double get ( int x , int y ) {
    int sr = max ( diam[ x ] , diam[ y ] ) ;
    double total_sm = 0.0 ;
    long long aux = 0 ;
    double total = 1.0 * comp_sz[ x ] * comp_sz[ y ] ;    
    for ( int i = 0 ; i <= diam[ x ] ; ++ i ) {
        int lft = sr - i - 1 ;
        if ( lft < 0 ) { lft = 0 ; }
        int coef = suff_cnt[ x ][ i ] ;
        if ( i < diam[ x ] ) { coef -= suff_cnt[ x ][ i + 1 ] ; }
        if ( lft <= diam[ y ] ) {
            aux += 1.0 * coef * suff_cnt[ y ][ lft ] ;
            total_sm += ( 1.0 * coef * suff_sm[ y ][ lft ] ) / total ;
            total_sm += ( 1.0 * coef * ( i + 1 ) * suff_cnt[ y ][ lft ] ) / total ;
        }
    }

    total_sm += ( 1.0 * ( total - aux ) * sr ) / total ;
    return total_sm ;
}

void input ( ) {
    int m ;
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( comp[ i ] == 0 ) {
            prep ( i ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ suff_cnt[ comp[ i ] ][ dist[ i ] ] ;
        suff_sm[ comp[ i ] ][ dist[ i ] ] += dist[ i ] ;
        ++ comp_sz[ comp[ i ] ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz = diam[ i ] + 1 ;
        for ( int j = sz - 2 ; j >= 0 ; -- j ) {
            suff_cnt[ i ][ j ] += suff_cnt[ i ][ j + 1 ] ;
            suff_sm[ i ][ j ] += suff_sm[ i ][ j + 1 ] ;
        }
    }
    while ( q -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y  );
        if ( comp_sz[ comp[ x ] ] > comp_sz[ comp[ y ] ] ) {
            swap ( x , y ) ;
        }
        if ( comp[ x ] == comp[ y ] ) {
            printf ( "-1\n" ) ;
            continue ;
        }
        if ( ww.find ( { comp[ x ] , comp[ y ] } ) == ww.end ( ) ) {
            ww[ { comp[ x ] , comp[ y ] } ] = get ( comp[ x ] , comp[ y ] ) ;
        }
        printf ( "%.16lf\n" , ww[ { comp[ x ] , comp[ y ] } ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}