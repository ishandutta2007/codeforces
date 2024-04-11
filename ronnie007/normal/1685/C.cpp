#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 200007 ;

int n ;
string a ;
int pref[ MAXN ] ;

void input ( ) {
    cin >> n >> a ;
    n *= 2 ;
}

void solve ( ) {
    int fst = -1 , lst = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] ;
        if ( a[ i - 1 ] == '(' ) { ++ pref[ i ] ; }
        else { -- pref[ i ] ; }
        if ( pref[ i ] < 0 && fst == -1 ) { fst = i ; }
        if ( pref[ i ] < 0 ) { lst = i ; }
    }
    if ( fst < 0 ) {
        cout << "0\n" ;
        return ;
    }
    int aux1 = -1 , aux2 = -1 ;
    int pos1 = -1 , pos2 = -1 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        if ( i < fst && aux1 < pref[ i ] ) {
            aux1 = pref[ i ] , pos1 = i ;
        }
        if ( lst < i && aux2 < pref[ i ] ) {
            aux2 = pref[ i ] , pos2 = i ;
        }
    }
    bool fl = true ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( pref[ i ] > aux1 + aux2 ) {
            fl = false ; break ;
        }
    }
    if ( fl == true ) {
        cout << "1\n" ;
        cout << pos1 + 1 << " " << pos2 << "\n" ;
        return ;
    }
    int mx = 0 , wh = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx < pref[ i ] ) {
            mx = pref[ i ] , wh = i ;
        }
    }
    cout << "2\n" ;
    cout << "1 " << wh << "\n" ;
    cout << wh + 1 << " " << n << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}