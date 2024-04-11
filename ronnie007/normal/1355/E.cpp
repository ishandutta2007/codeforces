#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , x , y , z ;
int a[ MAXN ] ;

long long f ( int sr ) {
    long long up = 0 ;
    long long down = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] >= sr ) {
            up += ( a[ i ] - sr ) ;
        }
        else {
            down += ( sr - a[ i ] ) ;
        }
    }
    if ( z > x + y ) {
        return ( down * x + up * y ) ;
    }
    else {
        long long aux = min ( up , down ) ;
        return ( aux * z + ( down - aux ) * x + ( up - aux ) * y ) ;
    }
}

void input ( ) {
    scanf ( "%d%d%d%d" , &n , &x , &y , &z ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = -1 ;
    long long l , r ;
    l = 1 ;
    r = 1 ;
    for ( int i = 1 ; i <= 9 ; ++ i ) {
        r *= 10 ;
    }
    while ( r - l > 3 ) {
        long long mid1 = ( l * 2 + r ) / 3 ;
        long long mid2 = ( r * 2 + l ) / 3 ;
        if ( f ( mid1 ) <= f ( mid2 ) ) {
            r = mid2 ; 
        }
        else {
            l = mid1 ;
        }
    }
    ans = f ( l ) ;
    for ( int i = l + 1 ; i <= r ; ++ i ) {
        ans = min ( ans , f ( i ) ) ;
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