#include<bits/stdc++.h>
using namespace std ;

long long a , b ;

bool f ( long long sr ) {
    if ( a < sr ) { return false ; }
    if ( b < sr ) { return false ; }
    long long aux = a + b - sr * 2 ;
    if ( aux < sr ) { return false ; }
    return true ;
}

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    long long l , r , mid ;
    l = 0 ;
    r = a + b ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid ; }
    }
    while ( f ( r ) == false ) { -- r ; }
    cout << r << "\n" ;
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