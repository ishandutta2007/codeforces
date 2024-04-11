#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007
#define MAXK 300007

int n , m , k ;
string a[ MAXN ] ;

struct tuhla {
    int stx , sty ;
    int enx , eny ;
    char c ;
};
tuhla w[ MAXK ] ;


int cnt[ 26 ][ MAXN ][ MAXN ] ;
long long pref[ 26 ][ MAXN ][ MAXN ] ;
long long init[ MAXN ][ MAXN ] ;


void input ( ) {
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '#' + a[ i ] ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        cin >> w[ i ].stx >> w[ i ].sty >> w[ i ].enx >> w[ i ].eny >> w[ i ].c ;
        ++ cnt[ w[ i ].c - 'a' ][ w[ i ].stx ][ w[ i ].sty ] ;
        -- cnt[ w[ i ].c - 'a' ][ w[ i ].stx ][ w[ i ].eny + 1 ] ;
        -- cnt[ w[ i ].c - 'a' ][ w[ i ].enx + 1 ][ w[ i ].sty ] ;
        ++ cnt[ w[ i ].c - 'a' ][ w[ i ].enx + 1 ][ w[ i ].eny + 1 ] ;
    }
}

void solve ( ) {
    for ( int t = 0 ; t < 26 ; ++ t ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= m ; ++ j ) {
                cnt[ t ][ i ][ j ] = cnt[ t ][ i ][ j ] + cnt[ t ][ i - 1 ][ j ] + cnt[ t ][ i ][ j - 1 ] - cnt[ t ][ i - 1 ][ j - 1 ] ;
            }
        }
    }
    
    long long ori = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int lft = k ;
            int tot = 0 ;
            int sub = 0 ;
            for ( int t = 0 ; t < 26 ; ++ t ) {
                pref[ t ][ i ][ j ] = t * tot - sub ;
                tot += cnt[ t ][ i ][ j ] ;
                sub += t * cnt[ t ][ i ][ j ] ;
            }
            lft -= tot ;
            tot = sub = 0 ;
            for ( int t = 25 ; t >= 0 ; -- t ) {
                pref[ t ][ i ][ j ] += sub - t * tot ;
                tot += cnt[ t ][ i ][ j ] ;
                sub += t * cnt[ t ][ i ][ j ] ;
            }

            for ( int t = 0 ; t < 26 ; ++ t ) {
                pref[ t ][ i ][ j ] += lft * ( abs ( t - ( a[ i ][ j ] - 'a' ) ) ) ;
            }
            init[ i ][ j ] = pref[ a[ i ][ j ] - 'a' ][ i ][ j ] ;
            ori += pref[ a[ i ][ j ] - 'a' ][ i ][ j ] ;
        }
    }
    for ( int t = 0 ; t < 26 ; ++ t ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= m ; ++ j ) {
                pref[ t ][ i ][ j ] = pref[ t ][ i ][ j ] + pref[ t ][ i - 1 ][ j ] + pref[ t ][ i ][ j - 1 ] - pref[ t ][ i - 1 ][ j - 1 ] ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            init[ i ][ j ] = init[ i ][ j ] + init[ i - 1 ][ j ] + init[ i ][ j - 1 ] - init[ i - 1 ][ j - 1 ] ;
        }
    }
    long long ans = -1 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        long long aux = ori ;
        aux -= init[ w[ i ].enx ][ w[ i ].eny ] - init[ w[ i ].enx ][ w[ i ].sty - 1 ]
            - init[ w[ i ].stx - 1 ][ w[ i ].eny ] + init[ w[ i ].stx - 1 ][ w[ i ].sty - 1 ] ;
        
        aux += pref[ w[ i ].c - 'a' ][ w[ i ].enx ][ w[ i ].eny ] - pref[ w[ i ].c - 'a' ][ w[ i ].enx ][ w[ i ].sty - 1 ]
            - pref[ w[ i ].c - 'a' ][ w[ i ].stx - 1 ][ w[ i ].eny ] + pref[ w[ i ].c - 'a' ][ w[ i ].stx - 1 ][ w[ i ].sty - 1 ] ;

        if ( ans < 0 ) { ans = aux ; }
        if ( ans > aux ) { ans = aux ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}