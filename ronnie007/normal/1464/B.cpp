#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
int n ;
string a ;
vector < int > v ;
long long c01 , c10 ;

long long pref[ MAXN ][ 2 ] ;

int get ( int l , int r , int id ) {
    if ( l > r ) { return 0 ; }
    return pref[ r ][ id ] - pref[ l - 1 ][ id ] ;
}

long long sum ( int i , int val ) {
    if ( val == 0 ) {
        return c10 * get ( 1 , i - 1 , 1 ) + c01 * get ( i + 1 , n , 1 ) ;
    }
    else {
        return c01 * get ( 1 , i - 1 , 0 ) + c10 * get ( i + 1 , n , 0 ) ;
    }
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    a = '#' + a ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == '?' ) {
            v.push_back ( i ) ;
        }
    }
    cin >> c01 >> c10 ;
}

void solve ( ) {
    long long init = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ][ 0 ] = pref[ i - 1 ][ 0 ] ;
        pref[ i ][ 1 ] = pref[ i - 1 ][ 1 ] ;
        if ( a[ i ] == '0' ) {
            init += pref[ i - 1 ][ 1 ] * c10 ;
            ++ pref[ i ][ 0 ] ;
        }
        if ( a[ i ] == '1' ) {
            init += pref[ i - 1 ][ 0 ] * c01 ;
            ++ pref[ i ][ 1 ] ;
        }
    }
    int sz = v.size ( ) ;
    // 01
    long long aux = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        aux += sum ( v[ i ] , 1 ) ;
    }
    long long ans = 1 ;
    for ( int i = 1 ; i <= 17 ; ++ i ) { ans *= 10 ; }
    for ( int i = 0 ; i <= sz ; ++ i ) {
        ans = min ( ans , init + aux + 1LL * i * ( sz - i ) * c01 ) ;
        if ( i < sz ) {
            aux -= sum ( v[ i ] , 1 ) ;
            aux += sum ( v[ i ] , 0 ) ;
        }
    }
    // 10 
    for ( int i = 0 ; i <= sz ; ++ i ) {
        ans = min ( ans , init + aux + 1LL * i * ( sz - i ) * c10 ) ;
        if ( i < sz ) {
            aux -= sum ( v[ i ] , 0 ) ;
            aux += sum ( v[ i ] , 1 ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}