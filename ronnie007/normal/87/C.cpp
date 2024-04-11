#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std ;


set < int > s ;

int n ;
int sg[ 100007 ] ;
int bst[ 100007 ] ;


void input ( ) ;
void solve ( ) ;



int main ( )  {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n ;
}


void solve ( ) {
    sg[ 1 ] = sg[ 2 ] = 0 ;

    int st , en ;
    int h ;
    int i , j , t ;
    for ( i = 3 ; i <= n ; i ++ ) {
        s.clear ( ) ;
        for ( j = 2 ; j * ( j + 1 ) / 2 <= i ; j ++ ) {
            if ( ( 2 * i ) % j == 0 ) {
                int ans = 0 ;
                h = ( 2 * i ) / j ;
                if ( ( h - j + 1 ) % 2 != 0 ) continue;
                st = ( h - j + 1 ) / 2;
                en = h - st ;
                if ( st > 0 && en > st ) {
                    for ( t = st ; t <= en ; t ++ ) {
                        ans = ans ^ sg[ t ] ;
                    }
                    s.insert ( ans ) ;
                    if ( ans == 0 && bst[ i ] == 0 ) bst[ i ] = j ;
                }
            }
        }
        for ( j = 0 ; j <= 10000 ; j ++ ) {
            if ( s.find( j ) == s.end( )  ) break ;
        }
        sg[ i ] = j ;
    }
    if ( sg[ n ] == 0 ) printf ( "-1\n" ) ;
    else printf ( "%d\n", bst[ n ] ) ;
}