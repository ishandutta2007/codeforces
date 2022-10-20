#include<bits/stdc++.h>
using namespace std ;

int n ;
long long sr ;
#define MAXN 100007
long long cnt[ MAXN ] ;
int deg[ MAXN ] ;
int lvl[ MAXN ] ;


bool can ( int n , long long sr , long long roots , long long mxcoef ) {
    if ( sr < 0 ) { return false ; }
    if ( roots > n ) { roots = n ; }
    if ( sr > 1LL * n * ( n + 1 ) / 2 ) {
        return false ;
    }    
    if ( mxcoef == 1 ) {
        if ( sr < 1LL * n * ( n + 1 ) / 2 ) { return false ; }
    }
    else {
        long long dummy = sr - roots ;
        long long lst = roots ;
        int lft = ( n - roots ) ;
        if ( dummy < 0 ) { return false ; }
        for ( int i = 2 ; i <= n ; ++ i ) {
            long long aux = min ( 1LL * lft , lst * mxcoef ) ;
            lft -= aux ;
            dummy -= aux * i ;
            lst *= mxcoef ;
            if ( dummy < 0 ) { return false ; }
            if ( lft == 0 ) { break ; }
        }
    }

    return true ;
}

bool f ( int coef , bool need ) {
    long long dummy = sr ;
    int lft = n ;
    if ( need == false ) {
        return can ( n , sr , 1 , coef ) ;
    }
    dummy -= n ; -- lft ;
    cnt[ 1 ] = 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        long long st = min ( 1LL * lft , 1LL * coef * cnt[ i - 1 ] ) ;
        bool fl = false ;
        for ( int j = 1 ; j <= st ; ++ j ) {
            if ( can ( lft - j , dummy - 1LL * lft , 1LL * j * coef , coef ) == true ) {
                dummy -= lft ;
                lft -= j ;
                cnt[ i ] = j ;
                fl = true ;
                break ; 
            }
        }
        if ( fl == false ) { return false ; }
        if ( lft == 0 && dummy == 0 ) { return true ; }
    }
    return false ;
}

void construct ( int coef ) {
    cout << "Yes\n" ;
    f ( coef , true ) ;
    deg[ 1 ] = 0 ;
    lvl[ 1 ] = 1 ;
    int aux = 1 ;
    int id = 2 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( id > n ) { break ; }
        while ( lvl[ aux ] < i - 1 ) { ++ aux ; }
        for ( int j = 1 ; j <= cnt[ i ] ; ++ j ) {
            while ( deg[ aux ] == coef ) { ++ aux ; }
            cout << aux << " " ;
            ++ deg[ aux ] ;
            lvl[ id ++ ] = i ;
            if ( id > n ) { break ; }
        }
    }
    cout << "\n" ;
}

void input ( ) {
    cin >> n >> sr ; 
}

void solve ( ) {
    if ( can ( n , sr , 1 , n ) == false ) {
        cout << "No\n" ;
        return ;
    }
    int l , r , mid ;
    l = 1 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid , false ) == true ) { r = mid ; }
        else { r = mid ; }
    }
    while ( f ( l , false ) == false ) { ++ l ; }
    construct ( l ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}