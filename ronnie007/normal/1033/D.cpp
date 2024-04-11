#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MOD 998244353
#define MAXN 507

long long ans ;

int n ;
long long a[ MAXN ] ;

long long root[ MAXN ] ;


map < long long , int > w ;

bool cmp ( long long a , int coef , long long x ) {
    long long sr = 1 ;
    for ( int i = 1 ; i <= coef ; ++ i ) {
        if ( ( x / a ) < sr ) { return true ; }
        sr *= a ;
    }
    if ( sr >= x ) { return true ; }
    return false ;
}

void proc ( long long x , int id ) {
    root[ id ] = -1 ;
    for ( int i = 4 ; i >= 2 ; -- i ) {
        long long l , r , mid ;
        l = 1 ; r = 2000000000 ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            if ( cmp ( mid , i , x ) == false ) { l = mid ; }
            else { r = mid ; }
        }
        while ( cmp ( l , i , x ) == false ) { ++ l ; }
        long long h = 1 ;
        for ( int j = 1 ; j <= i ; ++ j ) { h *= l ; }
        if ( h == x ) {
            root[ id ] = l ;
            return ;
        }
    }
}
    

void input ( ) {
    ans = 1 ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    queue < long long > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        proc ( a[ i ] , i ) ;
        if ( root[ i ] != -1 ) {
            int add = 0 ;
            while ( a[ i ] > 1 ) {
                a[ i ] /= root[ i ] ;
                ++ add ;
            }
            w[ root[ i ] ] += add ;
            q.push ( root[ i ] ) ;
        }
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == 1 ) { continue ; }
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            if ( a[ j ] == 1 ) { continue ; }
            long long aux = __gcd ( a[ i ] , a[ j ] ) ;
            if ( aux > 1 && aux != a[ i ] ) {
                w[ aux ] += 2 ;
                ++ w[ a[ i ] / aux ] ;
                ++ w[ a[ j ] / aux ] ;
                q.push ( aux ) ;
                q.push ( a[ i ] / aux ) ;
                q.push ( a[ j ] / aux ) ;
                a[ i ] = a[ j ] = 1 ;
                break ;
            }
        }
    }
    while ( q.empty ( ) == false ) {
        long long x = q.front ( ) ;
        q.pop ( ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( a[ i ] == 1 ) { continue ; }
            if ( ( a[ i ] % x ) == 0 ) {
                ++ w[ x ] ;
                ++ w[ a[ i ] / x ] ;
                q.push ( a[ i ] / x ) ;
                a[ i ] = 1 ;
            }
        }
    }
    for ( auto [ x , y ] : w ) {
        ans = ( ans * ( y + 1 ) ) % MOD ;
    }
    w.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == 1 ) { continue ; }
        ++ w[ a[ i ] ] ;
    }
    for ( auto [ x , y ] : w ) {
        ans = ( ans * ( y + 1 ) ) % MOD ;
        ans = ( ans * ( y + 1 ) ) % MOD ;
    }
    cout << ans << "\n" ;
    fflush ( stdout ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}