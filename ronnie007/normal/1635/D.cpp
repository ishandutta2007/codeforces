#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 1000000007

int n , p ;
int a[ MAXN ] ;

long long f[ MAXN ] ;
long long pref[ MAXN ] ;

void input ( ) {
    cin >> n >> p ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

set < pair < int , int > > s ;

set < int > vis ;
int val[ 35 ] ;

void solve ( ) {
    f[ 0 ] = pref[ 0 ] = 1 ;
    for ( int i = 1 ; i <= p ; ++ i ) {
        f[ i ] = f[ i - 1 ] ;
        if ( i >= 2 ) {
            f[ i ] = ( f[ i ] + f[ i - 2 ] ) % MOD ;
        }

        pref[ i ] = ( pref[ i - 1 ] + f[ i ] ) % MOD ;
    }
    vector < int > v ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( p <= 31 && ( 1LL << p ) <= a[ i ] ) { continue ; }
        int x = a[ i ] ;
        int cnt = 0 ;
        v.clear ( ) ;
        while ( x > 0 ) {
            v.push_back ( x % 2 ) ;
            x /= 2 ;
            ++ cnt ;
        }
        reverse ( v.begin ( ) , v.end ( ) ) ;
        val[ 0 ] = 0 ;
        for ( int j = 0 ; j < cnt ; ++ j ) {
            val[ j + 1 ] = val[ j ] * 2 + v[ j ] ;
        }
        int en = cnt ;
        bool fl = false ;
        while ( en > 0 ) {
            if ( vis.find ( val[ en ] ) != vis.end ( ) ) {
                fl = true ;
                break ;
            }
            if ( v[ en - 1 ] == 1 ) {
                -- en ;
            }
            else {
                if ( en - 2 >= 0 && v[ en - 2 ] == 0 ) {
                    en -= 2 ;
                }
                else { break ; }
            }
        }
        vis.insert ( a[ i ] ) ;
        if ( fl == false ) {
            ans += pref[ p - cnt ] ;
            ans %= MOD ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    /// freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}