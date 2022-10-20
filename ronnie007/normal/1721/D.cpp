#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 1e5 + 7 ;

int n ;
int a[ MAXN ] , b[ MAXN ] ;

map < int , int > w ;

bool check ( int mask ) {
    w.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ w[ ( b[ i ] & mask ) ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = ( a[ i ] & mask ) ;
        if ( w[ mask - aux ] <= 0 ) { return false ; }
        -- w[ mask - aux ] ;
    }
    return true ;
}

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
    int mask = 0 ;
    for ( int bit = 29 ; bit >= 0 ; -- bit ) {
        if ( check ( mask + ( 1 << bit ) ) == true ) {
            mask += ( 1 << bit ) ;
        }
    }
    cout << mask << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}