#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<random>
using namespace std ;

#define MAXN 100007
#define MAXCOMP 22
int n , m , d ;

int a[ MAXN ] ;

int cnt[ MAXCOMP ] ;
bool f[ (1<<MAXCOMP) ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &d ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int x ;
            scanf ( "%d" , &x ) ;
            a[ x ] = i ;
        }
    }
}

void solve ( ) {
    int aux = (1<<m) - 1 ;
    for ( int i = 1 ; i <= d ; ++ i ) {
        ++ cnt[ a[ i ] ] ;
        if ( cnt[ a[ i ] ] == 1 ) {
            aux -= (1<<a[ i ]) ;
        }
    }
    f[ aux ] = true ;
    for ( int i = d + 1 ; i <= n ; ++ i ) {
        ++ cnt[ a[ i ] ] ;
        if ( cnt[ a[ i ] ] == 1 ) {
            aux -= (1<<a[ i ]) ;
        }
        -- cnt[ a[ i - d ] ] ;
        if ( cnt[ a[ i - d ] ] == 0 ) {
            aux += (1<<a[ i - d ]) ;
        }
        f[ aux ] = true ;
    }
    for ( int i = (1<<m) - 1 ; i >= 0 ; -- i ) {
        if ( f[ i ] == true ) {
            for ( int j = 0 ; j < m ; ++ j ) {
                if ( ( i & (1<<j) ) != 0 ) {
                    f[ i - (1<<j) ] = true ;
                }
            }
        }
    }
    int mn = m ;
    for ( int i = 0 ; i < (1<<m) ; ++ i ) {
        if ( f[ i ] == false ) {
            int cnt = 0 ;
            int aux = i ;
            while ( aux > 0 ) {
                aux &= ( aux - 1 ) , ++ cnt ;
            }
            if ( mn > cnt ) { mn = cnt ; }
        }
    }
    printf ( "%d\n" , mn ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}