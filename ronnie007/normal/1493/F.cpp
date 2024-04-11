#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;
bool f[ MAXN ] ;

int ask ( int h , int w , int i1 , int j1 , int i2 , int j2 ) {
    cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << "\n" ;
    fflush ( stdout ) ;
    int ret ; cin >> ret ;
    return ret ;
}

bool check ( int len , int st , int en , bool fl ) {
    int tm = ( en - st + 1 ) / len ;
    if ( tm <= 1 ) { return true ; }
    
    int mid = ( tm / 2 ) ;
    if ( fl == false ) {
        if ( ask ( mid * len , m , st , 1 , en - mid * len + 1 , 1 ) == 0 ) { return false ; }
    }
    else {
        if ( ask ( n , mid * len , 1 , st , 1 , en - mid * len + 1 ) == 0 ) { return false ; }
    }
    return check ( len , st , en - mid * len , fl ) ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( f[ i ] == true ) { continue ; }
        for ( int j = 2 * i ; j < MAXN ; f[ j ] = true , j += i ) { }
    }
}

void solve ( ) {
    int ans = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int cnt = 0 , dummy = n ;
        if ( f[ i ] == true ) { continue ; }
        int coef = 1 ;
        while ( ( dummy % i ) == 0 ) {
            dummy /= i ;
            if ( check ( dummy , 1 , n / coef , false ) == true ) { ++ cnt ; }
            else { break ; }
            coef *= i ;
        }
        ans *= ( cnt + 1 ) ;
    }
    for ( int i = 2 ; i <= m ; ++ i ) {
        int cnt = 0 , dummy = m ; 
        if ( f[ i ] == true ) { continue ; }
        int coef = 1 ;
        while ( ( dummy % i ) == 0 ) {
            dummy /= i ;
            if ( check ( dummy , 1 , m / coef , true ) == true ) { ++ cnt ; }
            else { break ; }
            coef *= i ;
        }
        ans *= ( cnt + 1 ) ;
    }
    cout << "! " << ans << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}