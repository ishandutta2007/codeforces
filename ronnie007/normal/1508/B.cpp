#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
long long k ;

bool st[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    -- k ;
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        st[ i ] = false ;
    }
    for ( int i = 61 ; i >= 0 ; -- i ) {
        long long bit = ( 1LL << i ) ;
        if ( ( k & bit ) > 0 ) {
            if ( ( n - i ) <= 1 ) {
                cout << "-1\n" ;
                return ;
            }
            st[ n - i ] = true ;
        }
    }
    stack < int > aux ;
    while ( aux.empty ( ) == false ) { aux.pop ( ) ; }
    
    vector < int > v ; v.clear ( ) ;
    
    for ( int i = n ; i >= 1 ; -- i ) {
        aux.push ( i ) ;
        if ( st[ i ] == false ) {
            while ( aux.empty ( ) == false ) {
                v.push_back ( aux.top ( ) ) ;
                aux.pop ( ) ;
            }
        }
    }
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        cout << v[ i ] << " " ;
    }
    cout << "\n" ; 
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}