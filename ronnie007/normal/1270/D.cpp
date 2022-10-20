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
using namespace std ;

#define MAXN 507

int n , k ;
int a[ MAXN ] ;

bool used[ MAXN ] ;

pair < int , int > ask ( ) {
    printf ( "?" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { printf ( " %d" , i ) ; }
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
    int x , y ;
    scanf ( "%d%d" , &x , &y ) ;
    return { x , y } ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = -1 ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        used[ i ] = true ;
    }
    for ( int i = 1 ; i <= n - k + 1 ; ++ i ) {
        pair < int , int > ret = ask ( ) ;
        a[ ret.first ] = ret.second ;
        used[ ret.first ] = false ;
        used[ k + i ] = true ;
    }
    int aux = -1 ;
    int id = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] > 0 ) {
            if ( aux < 0 ) { aux = a[ i ] ; id = i ; }
            if ( aux > a[ i ] ) {
                aux = a[ i ] ;
                id = i ;
            }
        }
    }
    int other = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] > 0 && id != i ) {
            other = i ;
            used[ i ] = true ;
            break ;
        }
    }
    
    used[ id ] = true ;
    int ans = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true && i != id && i != other ) {
            used[ i ] = false ;
            pair < int , int > ret = ask ( ) ;
            if ( ret.second != aux ) { ++ ans ; }
            used[ i ] = true ;
        }
    }
    printf ( "! %d\n" , ans ) ;
    fflush ( stdout ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}