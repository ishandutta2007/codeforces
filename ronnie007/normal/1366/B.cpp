#include<bits/stdc++.h>
using namespace std ;

int n , m , x ;
int l , r ;

bool intersect ( int a , int b , int c , int d ) {
    if ( b < c || d < a ) { return false ; }
    return true ;
}

void input ( ) {
    cin >> n >> x >> m ;
    l = r = x ;
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        if ( intersect ( l , r , x , y ) == false ) { continue ; }
        l = min ( l , x ) ;
        r = max ( r , y ) ;
    }
    cout << r - l + 1 << "\n" ;
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