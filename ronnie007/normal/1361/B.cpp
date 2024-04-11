#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
#define MAXN 2000007


int n , p ;
int a[ MAXN ] ;

vector < int > v ;
set < int > w ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &p ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    if ( p == 1 ) {
        cout << ( n % 2 ) << "\n" ;
        return ;
    }
    w.clear ( ) ;
    int eq = 1 ;
    int val = a[ 1 ] ;
    v.clear ( ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == a[ i - 1 ] ) { ++ eq ; }
        else {
            int init = eq ;
            while ( eq > 0 ) {
                if ( eq >= p ) { w.insert ( val + 1 ) ; }
                int lft = ( eq % p ) ;
                while ( lft > 0 ) {
                    -- lft ;
                    v.push_back ( val ) ;
                }
                eq /= p ;
                ++ val ;
                if ( val == a[ i ] ) { break ; }
            }
            ++ eq ;
            val = a[ i ] ;
        }
    }
    int init = eq ;
    while ( eq > 0 ) {
        int lft = ( eq % p ) ;
        if ( eq >= p ) { w.insert ( val + 1 ) ; }        
        while ( lft > 0 ) {
            -- lft ;
            v.push_back ( val ) ;
        }
        eq /= p ;
        ++ val ;
    }
    int sz = v.size ( ) ;
    long long ans = 0 ;
    int cnt = 1 ;
    for ( int i = sz - 2 ; i >= 0 ; -- i ) {
        if ( v[ i ] == v[ i + 1 ] ) { ++ cnt ; }
        else {
            if ( ( cnt % 2 ) == 1 ) {
                int val = v[ i + 1 ] ;
                cnt = 1 ;
                while ( val > v[ i ] && w.find ( val ) != w.end ( ) ) {
                    -- val ;
                    cnt *= p ;
                }
                v[ i + 1 ] = val ;
                if ( v[ i + 1 ] == v[ i ] ) { ++ cnt ; continue ; }
                if ( ( cnt % 2 ) == 0 ) { cnt = 1 ; continue ; }
                ans += fastpow ( p , v[ i + 1 ] ) ;
                for ( int j = i ; j >= 0 ; -- j ) {
                    long long aux = fastpow ( p , v[ j ] ) ;
                    ans = ( ans - aux ) ;
                    if ( ans < 0 ) { ans += MOD ; }
                }
                cout << ans << "\n" ;
                return ;
            }
            else { cnt = 1 ; }
        }
    }
    if ( ( cnt % 2 ) == 1 ) {
        int hh = 1 ;
        while ( w.find ( v[ 0 ] ) != w.end ( ) ) { -- v[ 0 ] ; hh *= p ; }
        if ( ( hh % 2 ) == 0 ) { cout << "0\n" ; return ; }
        cout << fastpow ( p , v[ 0 ] ) << "\n" ;
    }
    else { cout << "0\n" ; }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}