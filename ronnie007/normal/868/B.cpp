#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;


int x , y , z ;
int st , en ;

int f ( int h ) {
    if ( h == 12 ) { h = 0 ; }
    h *= 5 ;
    return h ;
}

void input ( ) {
    cin >> x >> y >> z ;
    cin >> st >> en ;
}

void solve ( ) {
    x = f ( x ) ;
    if ( y != 0 || z != 0 ) { x ++ ; }
    st = f ( st ) ;
    en = f ( en ) ;
    if ( st > en ) { swap ( st , en ) ; }
    int br = 0 ;
    if ( st < x && x < en ) { br ++ ; }
    //if ( st < y && y < en ) { br ++ ; }
    if ( st < z && z < en ) { br ++ ; }
    st *= 2 ;
    en *= 2 ;
    y *= 2 ;
    if ( z != 0 ) { y ++ ; }
    if ( st < y && y < en ) { br ++ ; }
    if ( br == 0 || br == 3 ) {
        cout << "YES\n" ;
    }
    else {
        cout << "NO\n" ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}