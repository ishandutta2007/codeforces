#include<bits/stdc++.h>
using namespace std ;

#define MAXN 4007
#define MOD 998244353

int n ;
string a ;

int aux = 1 ;

int f[ MAXN ] ;
bool used[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

void dfs ( int vertex ) {
    used[ vertex ] = true ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( used[ h ] == true ) {
            if ( f[ h ] != ( f[ vertex ] ^ c ) ) { aux = 0 ; }
        }
        else {
            f[ h ] = f[ vertex ] ^ c ;
            dfs ( h ) ;
        }
    }
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    if ( a[ n - 1 ] == '1' ) {
        cout << "0\n" ;
        return ;
    }
    a[ n - 1 ] = '0' ;
    long long ans = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        aux = 1 ;
        for ( int j = 1 ; j <= 2 * n ; ++ j ) {
            v[ j ].clear ( ) ;
            used[ j ] = false ;
            f[ j ] = 0 ;
        }
        for ( int j = i ; j <= n ; ++ j ) {
            v[ j ].push_back ( { n - ( j - i ) , 0 } ) ;
        }
        for ( int j = 1 ; j <= n ; ++ j ) {
            v[ n + j ].push_back ( { 2 * n - j + 1 , 0 } ) ;
        }
        v[ 1 ].push_back ( { n + 1 , 1 } ) ;
        for ( int j = 1 ; j < i - 1 ; ++ j ) {
            v[ j ].push_back ( { j + 1 , 0 } ) ;
        }
        v[ i - 1 ].push_back ( { i , 1 } ) ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( a[ j - 1 ] == '0' ) {
                v[ j ].push_back ( { n + j , 0 } ) ;
                v[ n + j ].push_back ( { j , 0 } ) ;
            }
            else if ( a[ j - 1 ] == '1' ) {
                v[ j ].push_back ( { n + j , 1 } ) ;
                v[ n + j ].push_back ( { j , 1 } ) ;
            }
        }
        bool fl = false ;
        for ( int j = 1 ; j <= 2 * n ; ++ j ) {
            if ( used[ j ] == false ) {
                dfs ( j ) ;
                if ( fl == true ) {
                    aux = ( aux * 2 ) % MOD ;
                }
                fl = true ;
            }
        }
        ans = ( ans + aux ) % MOD ;
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