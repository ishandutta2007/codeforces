#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;

int f1[ MAXN ] ;
int f2[ MAXN ] ;

int stk[ MAXN ] ;
int sz ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ; 
    }
}

void solve ( ) {
    sz = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int lst = -1 ;
        while ( sz > 0 && stk[ sz - 1 ] < a[ i ] ) {
            lst = stk[ sz - 1 ] ;
            -- sz ;
        }
        if ( lst == -1 ) { lst = a[ i ] ; }
        stk[ sz ++ ] = lst ;
        if ( stk[ 0 ] <= a[ i ] ) { f1[ i ] = 1 ; }
        else { f1[ i ] = 0 ; }
    }

    sz = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        int lst = -1 ;
        while ( sz > 0 && stk[ sz - 1 ] > a[ i ] ) {
            lst = stk[ sz - 1 ] ;
            -- sz ;
        }
        if ( lst == -1 ) { lst = a[ i ] ; }
        stk[ sz ++ ] = lst ;
        if ( stk[ 0 ] >= a[ i ] ) { f2[ i ] = 1 ; }
        else { f2[ i ] = 0 ; }

        if ( f1[ i ] == 1 && f2[ i ] == 1 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
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