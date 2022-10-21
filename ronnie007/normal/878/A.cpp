#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 500007

int n ;
char type[ MAXN ] ;
int val[ MAXN ] ;


void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> type[ i ] >> val[ i ] ;
    }
}

void solve ( ) {
    int i , j ;
    int a , b , c ;
    a = b = c = 0 ;
    for ( i = 0 ; i < 10 ; i ++ ) {
        int x , y ;
        x = 0 ;
        y = 1 ;
        for ( j = 1 ; j <= n ; j ++ ) {
            int aux ;
            if ( ( val[ j ] & (1<<i) ) != 0 ) { aux = 1 ; }
            else { aux = 0 ; }
            if ( type[ j ] == '&' ) { x = ( x & aux ) ; y = ( y & aux ) ; }
            if ( type[ j ] == '|' ) { x = ( x | aux ) ; y = ( y | aux ) ; }
            if ( type[ j ] == '^' ) { x = ( x ^ aux ) ; y = ( y ^ aux ) ; }
        }
        if ( x == 0 && y == 1 ) {
            c += (1<<i) ;
        }
        if ( x == 1 && y == 0 ) {
            b += (1<<i) ;
            c += (1<<i) ;
        }
        if ( x == 1 && y == 1 ) {
            a += (1<<i) ;
            c += (1<<i) ;
        }
    }
    cout << 3 << "\n" ;
    cout << "| " << a << "\n" ;
    cout << "^ " << b << "\n" ;
    cout << "& " << c << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}