#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1000007

int n ;
long long a[ MAXN ] ;
int bits[ MAXN ] ;

long long ans = 0 ;

pair < long long , long long > pref[ MAXN ] , suff[ MAXN ] ;

int aux[ 70 ] ;


void f ( int l , int r ) {
    if ( l == r ) {
        ++ ans ;
        return ;
    }
    int mid = ( l + r ) / 2 ;
    f ( l , mid ) ; f ( mid + 1 , r ) ;
    
    pref[ mid ] = { a[ mid ] , a[ mid ] } ;
    for ( int i = mid - 1 ; i >= l ; -- i ) {
        pref[ i ] = { max ( pref[ i + 1 ].first , a[ i ] ) , min ( pref[ i + 1 ].second , a[ i ] ) } ;
    }

    suff[ mid + 1 ] = { a[ mid + 1 ] , a[ mid + 1 ] } ;
    for ( int i = mid + 2 ; i <= r ; ++ i ) {
        suff[ i ] = { max ( suff[ i - 1 ].first , a[ i ] ) , min ( suff[ i - 1 ].second , a[ i ] ) } ;
    }
    int mxend = mid ;
    int mnend = mid ;
    for ( int i = mid ; i >= l ; -- i ) {
        long long mx = pref[ i ].first ;
        long long mn = pref[ i ].second ;
        while ( mxend + 1 <= r && suff[ mxend + 1 ].first <= mx ) {
            ++ mxend ;
            // ++ aux[ __builtin_popcountll ( suff[ mxend ].second ) ] ;
        }

        while ( mnend + 1 <= r && suff[ mnend + 1 ].second >= mn ) {
            // -- aux[ __builtin_popcountll ( suff[ lstpos ].second ) ] ;
            ++ mnend ;
        }
        if ( __builtin_popcountll ( mx ) == __builtin_popcountll ( mn ) ) {
            ans += min ( mxend , mnend ) - ( mid + 1 ) + 1 ;
        }
    }
    mxend = mid + 1 ;
    mnend = mid + 1 ;
    for ( int i = mid + 1 ; i <= r ; ++ i ) {
        long long mx = suff[ i ].first ;
        long long mn = suff[ i ].second ;
        while ( mxend - 1 >= l && pref[ mxend - 1 ].first < mx ) {
            -- mxend ;
        }
        while ( mnend - 1 >= l && pref[ mnend - 1 ].second > mn ) {
            -- mnend ;
        }
        if ( __builtin_popcountll ( mx ) == __builtin_popcountll ( mn ) ) {
            ans += mid - ( max ( mxend , mnend ) ) + 1 ;
        }        
    }


    mxend = mid ;
    mnend = mid + 1 ;
    for ( int i = mid ; i >= l ; -- i ) {
        long long mx = pref[ i ].first ;
        long long mn = pref[ i ].second ;
        while ( mxend + 1 <= r && suff[ mxend + 1 ].first <= mx ) {
            ++ mxend ;
            ++ aux[ __builtin_popcountll ( suff[ mxend ].second ) ] ;
        }

        while ( mnend <= r && suff[ mnend ].second >= mn ) {
            -- aux[ __builtin_popcountll ( suff[ mnend ].second ) ] ;
            ++ mnend ;
        }
        if ( mnend <= mxend ) { 
            ans += aux[ __builtin_popcountll ( mx ) ] ;
        }
    }    
    for ( int i = 0 ; i < 65 ; ++ i ) {
        aux[ i ] = 0 ;
    }

    mxend = mid + 1 ;
    mnend = mid ;
    for ( int i = mid + 1 ; i <= r ; ++ i ) {
        long long mx = suff[ i ].first ;
        long long mn = suff[ i ].second ;
        while ( mxend - 1 >= l && pref[ mxend - 1 ].first < mx ) {
            -- mxend ;
            ++ aux[ __builtin_popcountll ( pref[ mxend ].second ) ] ;
        }
        while ( mnend >= l && pref[ mnend ].second > mn ) {
            -- aux[ __builtin_popcountll ( pref[ mnend ].second ) ] ;
            -- mnend ;
        }
        if ( mxend <= mnend ) {
            ans += aux[ __builtin_popcountll ( mx ) ] ;
        }
    }
    for ( int i = 0 ; i < 65 ; ++ i ) {
        aux[ i ] = 0 ;
    }
}


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        bits[ i ] = __builtin_popcountll ( a[ i ] ) ;
    }
}

void solve ( ) {
    f ( 1 , n ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}