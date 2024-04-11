#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define inf 10000007

int n ;
long long a[ MAXN ] ;

long long calc ( int x , int y , long long sr ) {
    return ( a[ x ] * a[ y ] + ( a[ x ] + a[ y ] ) * sr ) ;
}

long long f ( long long sr ) {
    long long ret = calc ( 1 , n , sr ) ;
    for ( int i = 2 ; i < n ; ++ i ) {
        ret += min ( calc ( 1 , i , sr ) , calc ( i , n , sr ) ) ;
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    if ( a[ 1 ] > 1 || a[ n ] < 0 ) {
        cout << "INF\n" ;
        return ;
    }
    long long sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sm += a[ i ] ;
    }
    long long lft = 2 * ( n - 1 ) - n ;
    if ( sm > 0 ) {
        if ( lft * a[ 1 ] + sm > 0 ) {
            cout << "INF\n" ;
            return ;
        }
    }
    if ( sm < 0 ) {
        if ( lft * a[ n ] + sm < 0 ) {
            cout << "INF\n" ;
            return ;
        }
    }
    long long l , r , mid1 , mid2 ;
    l = -1e6 , r = 1e6 ;
    while ( r - l > 4 ) {
        mid1 = ( 2 * l + r ) / 3 ;
        mid2 = ( l + 2 * r ) / 3 ;
        if ( f ( mid1 ) < f ( mid2 ) ) { l = mid1 ; }
        else { r = mid2 ; }
    }
    long long ans = f ( l ) ;
    for ( long long i = l + 1 ; i <= r ; ++ i ) {
        ans = max ( ans , f ( i ) ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}