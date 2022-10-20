#include<bits/stdc++.h>
using namespace std ;

long long x , y ;

void input ( ) {
    cin >> x >> y ;
}

void solve ( ) {
    if ( x + y == 2 || __gcd ( x , y ) > 1 ) {
        cout << "Impossible\n" ;
        return ;
    }
    vector < pair < long long , int > > v ;
    v.clear ( ) ;
    while ( x > 1 || y > 1 ) {
        if ( x >= y ) {
            long long cnt = ( x - 1 ) / y ;
            v.push_back ( { cnt , 0 } ) ;
            x -= cnt * y ;
        }
        else {
            long long cnt = ( y - 1 ) / x ;
            v.push_back ( { cnt , 1 } ) ;            
            y -= cnt * x ;
        }
    }
    int sz = v.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ].first ;
        if ( v[ i ].second == 0 ) { cout << "A" ; }
        else { cout << "B" ; }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}