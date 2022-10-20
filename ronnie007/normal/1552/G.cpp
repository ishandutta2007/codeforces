#include<bits/stdc++.h>
using namespace std ;

int n , k ;
vector < int > v[ 11 ] ;

long long suff[ 11 ][ 42 ] ;
long long pref[ 11 ] ;
long long act[ 11 ] ;
int cnt_nw[ 11 ] ;

void dfs ( int lvl , long long mask ) {
    if ( lvl == k + 1 ) {
        int aux = __builtin_popcountll ( mask ) ;
        int lft = n - aux ;
        long long sr = ( 1LL << aux ) - 1 ;
        sr = ( sr << lft ) ;
        if ( sr != mask ) {
            cout << "REJECTED\n" ;
            exit ( 0 ) ;
        }
        return ;
    }
    long long hh = mask - ( mask & act[ lvl ] ) ;
    int init = __builtin_popcountll ( mask & act[ lvl ] ) ;
    for ( int i = 0 ; i <= cnt_nw[ lvl ] ; ++ i ) {
        dfs ( lvl + 1 , ( hh | suff[ lvl ][ i + init ] ) ) ;
    }
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int sz ; cin >> sz ;
        v[ i ].resize ( sz ) ;
        pref[ i ] = pref[ i - 1 ] ;
        for ( auto &x : v[ i ] ) {
            cin >> x ; -- x ;
            pref[ i ] |= ( 1LL << x ) ;
            act[ i ] |= ( 1LL << x ) ;
        }
        cnt_nw[ i ] = __builtin_popcountll ( pref[ i ] ^ pref[ i - 1 ] ) ;
        int tp = 0 ;
        for ( int j = sz - 1 ; j >= 0 ; -- j ) {
            ++ tp ;
            suff[ i ][ tp ] = suff[ i ][ tp - 1 ] ;
            suff[ i ][ tp ] |= ( 1LL << v[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "ACCEPTED\n" ;
        return ;
    }
    if ( pref[ k ] != ( 1LL << n ) - 1 ) {
        cout << "REJECTED\n" ;
        return ;
    }
    dfs ( 1 , 0 ) ;
    cout << "ACCEPTED\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}