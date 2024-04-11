#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n , k ;
string a ;
int to[ MAXN ][ 2 ] ;

vector < int > ord ;
void init ( int vertex ) {
    if ( to[ vertex ][ 0 ] != 0 ) {
        init ( to[ vertex ][ 0 ] ) ;
    }
    ord.push_back ( vertex ) ;
    if ( to[ vertex ][ 1 ] != 0 ) {
        init ( to[ vertex ][ 1 ] ) ;
    }
}

bool fl[ MAXN ] ;
bool w[ MAXN ] ;
string ans ;

void dfs ( int vertex , int aux ) {
    if ( to[ vertex ][ 0 ] != 0 ) {
        dfs ( to[ vertex ][ 0 ] , aux + 1 ) ;
    }
    if ( w[ to[ vertex ][ 0 ] ] == true ) {
        w[ vertex ] = true ;
    }
    else if ( fl[ vertex ] == true && aux <= k ) {
        k -= aux ;
        w[ vertex ] = true ;
    }
    
    if ( to[ vertex ][ 1 ] != 0 && w[ vertex ] == true ) {
        dfs ( to[ vertex ][ 1 ] , 1 ) ;
    }
}

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
    a = '#' + a ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> to[ i ][ 0 ] >> to[ i ][ 1 ] ;
    }
}

void solve ( ) {
    init ( 1 ) ;
    int lst = -1 ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        if ( i < n - 1 && a[ ord[ i + 1 ] ] != a[ ord[ i ] ] ) {
            lst = a[ ord[ i + 1 ] ] - 'a' ;
        }
        if ( a[ ord[ i ] ] - 'a' < lst ) {
            fl[ ord[ i ] ] = true ;
        }
    }
    dfs ( 1 , 1 ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ans += a[ ord[ i ] ] ;
        if ( w[ ord[ i ] ] == true ) { ans += a[ ord[ i ] ] ; }
    }
    cout << ans << "\n" ;
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