#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

long long init ;
long long l , r ;
long long t , x , y ;

bool vis[ MAXN ] ;

void input ( ) {
    cin >> init >> l >> r >> t >> x >> y ;
}

void solve ( ) {
    if ( x > y ) {
        if ( init + y <= r ) {
            long long diff = x - y ;
            long long lft = ( init - l ) / diff ;
            if ( lft >= t ) {
                cout << "Yes\n" ;
                return ;
            }
            else {
                cout << "No\n" ;
                return ;
            }
        }
        else {
            init -= x ;
            -- t ;
            if ( init < l ) {
                cout << "No\n" ;
                return ;
            }
            long long diff = x - y ;
            long long lft = ( init - l ) / diff ;
            if ( lft >= t ) {
                cout << "Yes\n" ;
                return ;
            }
            else {
                cout << "No\n" ;
                return ;
            }            
        }
    }
    long long lft = ( init - l ) / x ;
    if ( lft >= t ) {
        cout << "Yes\n" ;
        return ;
    }
    long long mx = r - y ;
    if ( mx < l ) {
        cout << "No\n" ;
        return ;
    }
    if ( mx - l >= x ) {
        cout << "Yes\n" ;
        return ;
    }
    long long aux = init - lft * x ;
    t -= lft ;
    if ( t <= 0 ) {
        cout << "Yes\n" ;
        return ;
    }
    while ( 1 ) {
        vis[ aux - l ] = true ;
        aux += y ;
        lft = ( aux - l ) / x ;
        aux -= lft * x ;
        t -= lft ;
        if ( t <= 0 ) {
            cout << "Yes\n" ;
            return ;
        }
        if ( aux > mx ) {
            cout << "No\n" ;
            return ;
        }
        if ( vis[ aux - l ] == true ) {
            cout << "Yes\n" ;
            return ;
        }
        vis[ aux - l ] = true ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}