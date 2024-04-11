#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;
string s ;

long long ans = 0 ;


void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    cin >> s ;
}

void solve ( ) {
    bool fl = false ;
    long long aux = 0 ;
    long long cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( s[ i ] == 'G' ) {
            ans += 5LL * a[ i ] ;
            aux += a[ i ] ;
            cnt += 2LL * a[ i ] ;
        }
        else if ( s[ i ] == 'W' ) {
            fl = true ;
            ans += 3LL * a[ i ] ;
            aux += a[ i ] ;
        }
        else {
            ans += a[ i ] ;
            if ( aux < a[ i ] ) {
                if ( fl == true ) {
                    ans += 3LL * ( a[ i ] - aux ) ;
                }
                else {
                    ans += 5LL * ( a[ i ] - aux ) ;
                }
                aux = 0 ;
            }
            else {
                aux -= a[ i ] ;
            }
        }
        cnt = min ( cnt , aux ) ;
    }
    ans -= 2LL * cnt ;
    aux -= cnt ;
    ans -= aux ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}