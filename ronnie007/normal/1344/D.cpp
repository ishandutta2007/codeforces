#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
long long k ;
long long a[ MAXN ] ;

long long aux[ MAXN ] ;

priority_queue < pair < long long , long long > > q ;

// max x, such that: c - 3x^2 - 3x - 1 >= sr 
long long srch ( int id , long long sr ) {
    if ( a[ id ] - 1 < sr ) { return -1 ; }
    long long l , r , mid ;
    l = 0 ;
    r = a[ id ] - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        long long poly = a[ id ] - mid * mid * 3 - mid * 3 - 1 ;
        if ( poly >= sr ) {
            l = mid ; 
        }
        else {
            r = mid ;
        }
    }
    while ( 1 ) {
        long long poly = a[ id ] - r * r * 3 - r * 3 - 1 ;
        if ( poly < sr ) { -- r ; }
        else { return r ; }
    }
}

long long f ( long long sr ) {
    long long ret = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ret += srch ( i , sr ) + 1 ;
    }
    return ret ;
}

long long get ( ) {
    long long l , r , mid ;
    l = -4 ;
    r = 4 ;
    for ( int i = 1 ; i <= 18 ; ++ i ) {
        l *= 10 ;
        r *= 10 ;
    }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        long long ret = f ( mid ) ;
        if ( ret > k ) { l = mid ; }
        else { r = mid ; }
    }
    while ( 1 ) {
        long long ret = f ( l ) ;
        if ( ret <= k ) { return l ; }
        ++ l ;
    }
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    long long h = get ( ) ;
    long long tot = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        long long ret = srch ( i , h + 1 ) + 1 ;
        aux[ i ] = ret ;
        tot += ret ;
        if ( aux[ i ] < a[ i ] ) {
            q.push ( { a[ i ] - ret * ret * 3 - ret * 3 - 1 , i } ) ;
        }
    }
    while ( tot < k ) {
        pair < long long , long long > w = q.top ( ) ;
        q.pop ( ) ;
        ++ aux[ w.second ] ;
        ++ tot ;
        if ( aux[ w.second ] < a[ w.second ] ) {
            long long p = aux[ w.second ] ;
            q.push ( { a[ w.second ] - 3LL * p * p - 3LL * p - 1 , w.second } ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << aux[ i ] << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}