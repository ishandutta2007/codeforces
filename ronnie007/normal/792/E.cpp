#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n ;
int a[ MAXN ] ;

long long ans = -1 ;

void f ( int x ) {
    if ( x <= 0 ) { return ; }
    long long aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int hh = ( a[ i ] / ( x + 1 ) ) ;
        int lft = ( a[ i ] % ( x + 1 ) ) ;
        if ( lft == 0 ) {
            aux += hh ;
            continue ;
        }
        if ( lft == x ) {
            aux += hh + 1 ;
            continue ;
        }
        lft = x - lft ;
        if ( hh < lft ) { return ; }
        aux += hh + 1 ;
    }
    if ( ans < 0 || ans > aux ) { ans = aux ; }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i * i <= a[ 1 ] ; ++ i ) {
        f ( i ) ;
        int val = ( a[ 1 ] / i ) ;
        f ( val ) ;
        f ( val - 1 ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}