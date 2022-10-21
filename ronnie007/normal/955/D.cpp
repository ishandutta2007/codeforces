#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , m , k ;
string text , pattern ;

string aux ;
int PI[ 2 ][ MAXN ] ;

int mxsuff[ MAXN ] ;
int mxpref[ MAXN ] ;

int mn[ MAXN ] ;
int mx[ MAXN ] ;

bool ch[ MAXN ] ;
bool full[ MAXN ] ;

void init ( ) {
    for ( int i = 0 ; i <= m ; ++ i ) {
        mn[ i ] = MAXN ;
        mx[ i ] = 0 ;
    }
    for ( int i = m - 1 ; i >= 0 ; -- i ) {
        aux += pattern[ i ] ;
    }
    aux += '#' ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        aux += text[ i ] ;
    }
    int len = 0 ;
    for ( int i = 2 ; i <= n + m + 1 ; ++ i ) {
        while ( len > 0 && aux[ len ] != aux[ i - 1 ] ) {
            len = PI[ 0 ][ len ] ;
        }
        if ( aux[ len ] == aux[ i - 1 ] ) { ++ len ; }
        PI[ 0 ][ i ] = len ;
        mxsuff[ n - ( i - m - 1 ) + 1 ] = len ;
        if ( i > m + k ) {
            mx[ len ] = max ( n - ( i - m - 1 ) + 1 , mx[ len ] ) ;
        }
    }
    aux.clear ( ) ;
    aux = pattern + '#' + text ;
    len = 0 ;
    for ( int i = 2 ; i <= n + m + 1 ; ++ i ) {
        while ( len > 0 && aux[ len ] != aux[ i - 1 ] ) {
            len = PI[ 1 ][ len ] ;
        }
        if ( aux[ len ] == aux[ i - 1 ] ) { ++ len ; }
        PI[ 1 ][ i ] = len ;
        mxpref[ i - m - 1 ] = len ;
        if ( i > m + k ) {
            mn[ len ] = min ( i - m - 1 , mn[ len ] ) ;
        }
    }
}

void input ( ) {
    cin >> n >> m >> k ;
    cin >> text >> pattern ;
}

void solve ( ) {
    init ( ) ;
    if ( k >= m ) {
        for ( int i = k ; i <= n ; ++ i ) {
            if ( mxpref[ i ] == m ) {
                ch[ i - k + 1 ] = true ;
            }
        }
        for ( int i = 1 ; i + k - 1 <= n ; ++ i ) {
            if ( mxsuff[ i ] == m ) {
                ch[ i ] = true ;
            }
        }
        int cnt = 0 ;
        for ( int i = 1 ; i <= n - k + 1 ; ++ i ) {
            cnt += ( ch[ i ] == true ) ;
            if ( i > k ) {
                cnt -= ( ch[ i - k ] == true ) ;
            }
            full[ i ] = ( cnt > 0 ) ;
            if ( full[ i ] == true ) {
                if ( i > k ) {
                    cout << "Yes\n" ;
                    cout << "1 " << i << "\n" ;
                    return ;
                }
                else if ( i + k - 1 < n - k + 1 ) {
                    cout << "Yes\n" ;
                    cout << i << " " << n - k + 1 << "\n" ;
                    return ;
                }
            }
        }
    }
    for ( int i = m ; i >= 0 ; -- i ) {
        mx[ PI[ 0 ][ i ] ] = max ( mx[ PI[ 0 ][ i ] ] , mx[ i ] ) ;
        mn[ PI[ 1 ][ i ] ] = min ( mn[ PI[ 1 ][ i ] ] , mn[ i ] ) ;
    }
    mn[ 0 ] = k ;
    mx[ 0 ] = n - k + 1 ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        int lft = ( m - i ) ;
        if ( lft < 0 || lft > k ) { continue ; }
        if ( mn[ i ] < mx[ lft ] ) {
            cout << "Yes\n" ;
            cout << mn[ i ] - k + 1 << " " << mx[ lft ] << "\n" ;
            return ;
        }
    }
    cout << "No\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}