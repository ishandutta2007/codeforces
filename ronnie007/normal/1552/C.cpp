#include<bits/stdc++.h>
using namespace std ;

#define MAXN 201

int n , k ;
pair < int , int > a[ MAXN ] ;
bool used[ MAXN ] ;

bool f ( int x , int y ) {
    if ( a[ x ].first <= a[ y ].first && a[ y ].first <= a[ x ].second ) {
        if ( !( a[ x ].first <= a[ y ].second && a[ y ].second <= a[ x ].second ) ) {
            return true ;
        }
    }

    if ( a[ x ].first <= a[ y ].second && a[ y ].second <= a[ x ].second ) {
        if ( !( a[ x ].first <= a[ y ].first && a[ y ].first <= a[ x ].second ) ) {
            return true ;
        }
    }    
    return false ;
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        used[ i ] = false ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
        if ( a[ i ].first > a[ i ].second ) {
            swap ( a[ i ].first , a[ i ].second ) ;
        }
        used[ a[ i ].first ] = true ;
        used[ a[ i ].second ] = true ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        for ( int j = i + 1 ; j <= k ; ++ j ) {
            ans += f ( i , j ) ;
        }
    }
    ans += ( n - k ) * ( n - k - 1 ) / 2 ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int cnt = 0 ;
        for ( int j = a[ i ].first + 1 ; j < a[ i ].second ; ++ j ) {
            cnt += ( used[ j ] == false ) ;
        }
        ans += min ( cnt , 2 * ( n - k ) - cnt ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}