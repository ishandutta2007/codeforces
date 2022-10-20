#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
struct tuhla {
    long long a , b , k ;
    bool operator < ( tuhla other ) const {
        return ( b > other.b ) ;
    }
};
tuhla f[ MAXN ] ;

long long dp[ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> f[ i ].a >> f[ i ].b >> f[ i ].k ;
    }
    sort ( f + 1 , f + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = n - 1 ; j >= 0 ; -- j ) {
            long long aux = dp[ j ] + f[ i ].a - f[ i ].b * j ;
            dp[ j + 1 ] = max ( dp[ j + 1 ] , aux ) ;
            aux = dp[ j ] + f[ i ].a - f[ i ].b * f[ i ].k ;
            dp[ j ] = max ( dp[ j ] , aux ) ;
        }
    }
    long long mx = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        mx = max ( mx , dp[ i ] ) ;
    }
    cout << mx << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}