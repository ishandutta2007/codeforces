#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std ;

#define MAXN 23

int n , m ;
int val[ MAXN ] ;

int dp[ (1<<MAXN) ] ;
pair < int , int > rv[ (1<<MAXN) ] ;

int pwid[ (1<<MAXN) ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        x -- ; y -- ;
        val[ x ] |= (1<<y) ;
        val[ y ] |= (1<<x) ;
    }
}

void solve ( ) {
    if ( m == ( n * ( n - 1 ) ) / 2 ) { printf ( "0\n" ) ; return ; }
    dp[ 0 ] = 0 ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        pwid[ (1<<i) ] = i + 1 ;
    }
    for ( i = 1 ; i < (1<<n) ; i ++ ) {
        dp[ i ] = n + 27 ;
    }
    for ( i = 0 ; i < n ; i ++ ) {
        int id = ((1<<i)|val[ i ]) ;
        dp[ id ] = 1 ;
        rv[ id ] = make_pair ( i , 0 ) ;
    }
    for ( i = 0 ; i < (1<<n) ; i ++ ) {
        int aux = i ;
        while ( aux != 0 ) {
            int nw = (aux&(aux-1)) ;
            int id = pwid[ aux - nw ] - 1 ;
            if ( val >= 0 ) {
                int nwmask = (i|val[ id ]) ;
                if ( dp[ nwmask ] > dp[ i ] + 1 ) {
                    dp[ nwmask ] = dp[ i ] + 1 ;
                    rv[ nwmask ] = make_pair ( id , i ) ;
                }
            }
            aux = nw ;
        }
    }
    vector < int > v ;
    int h = (1<<n) - 1 ;
    while ( h != 0 ) {
        v.push_back ( rv[ h ].first ) ;
        h = rv[ h ].second ;
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d " , v[ i ] + 1 ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}