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

int stx , sty ;

int lx , ly , rx , ry ;
int a , b , c , d ;

void input ( ) {
    cin >> a >> b >> c >> d ;
    cin >> stx >> sty >> lx >> ly >> rx >> ry ;
}

void solve ( ) {
    if ( lx == rx && a + b > 0 ) { cout << "NO\n" ; return ; }
    if ( ly == ry && c + d > 0 ) { cout << "NO\n" ; return ; }
    int hx = stx - a + b ;
    int hy = sty - c + d ;
    if ( hx < lx || rx < hx ) { cout << "NO\n" ; return ; }
    if ( hy < ly || ry < hy ) { cout << "NO\n" ; return ; }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}