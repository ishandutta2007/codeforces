#include<bits/stdc++.h>
using namespace std ;

int l , r ;
int n = 23 ;


struct edge {
    int x , y ;
    int len ;
    edge ( ) { x = y = len = 0 ; }
    edge ( int _x , int _y , int _len ) {
        x = _x ; y = _y ;
        len = _len ;
    }
};

vector < edge > v ;

void init ( ) {
    for ( int i = 0 ; i <= 20 ; ++ i ) {
        v.push_back ( edge ( 1 , i + 2 , 1 ) ) ;
        for ( int j = 0 ; j < i ; ++ j ) {
            v.push_back ( edge ( j + 2 , i + 2 , ( 1 << j ) ) ) ;
        }
    }
}

void input ( ) {
    cin >> l >> r ;
}


void solve ( ) {
    cout << "YES\n" ;
    init ( ) ;
    int diff = r - l ;
    int sm = 1 ;
    v.push_back ( edge ( 1 , n , 1 ) ) ;
    for ( int i = 0 ; i <= 20 ; ++ i ) {
        if ( ( diff & ( 1 << i ) ) > 0 ) {
            v.push_back ( edge ( i + 2 , n , sm ) ) ;
            sm += ( 1 << i ) ;
        }
    }
    if ( l > 1 ) {
        ++ n ;
        v.push_back ( edge ( n - 1 , n , l - 1 ) ) ;
    }
    
    int sz = v.size ( ) ;
    cout << n << " " << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ].x << " " << v[ i ].y << " " << v[ i ].len << "\n" ;
    }
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