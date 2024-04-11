#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , m ;
vector < string > a ;

int dp[ MAXN ][ 9 ] ;

int cost ( int col , int mask ) {
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ][ col ] == '0' && ( mask & (1<<i) ) > 0 ) { ++ ans ; }
        if ( a[ i ][ col ] == '1' && ( mask & (1<<i) ) == 0 ) { ++ ans ; }
    }
    return ans ;
}

bool check ( int h1 , int h2 ) {
    for ( int i = 0 ; i + 1 < n ; ++ i ) {
        int cnt = 0 ;
        cnt += ( ( h1 & (1<<i) ) > 0 ) ;
        cnt += ( ( h1 & (1<<(i+1)) ) > 0 ) ;
        
        cnt += ( ( h2 & (1<<i) ) > 0 ) ;
        cnt += ( ( h2 & (1<<(i+1)) ) > 0 ) ;
        if ( ( cnt % 2 ) == 0 ) { return false ; }
    }
    return true ;
}

void input ( ) {
    cin >> n >> m ;
    a.resize ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( n > 3 && m > 3 ) {
        cout << "-1\n" ;
        return ;
    }
    int lim = (1<<n) ;
    for ( int i = 0 ; i <= m ; ++ i ) {
        for ( int j = 0 ; j < lim ; ++ j ) {
            dp[ i ][ j ] = MAXN ; 
        }
    }
    for ( int i = 0 ; i < lim ; ++ i ) {
        dp[ 0 ][ i ] = cost ( 0 , i ) ;
    }
    int ret = MAXN ; 
    for ( int i = 0 ; i < m - 1 ; ++ i ) {
        for ( int j = 0 ; j < lim ; ++ j ) {
            if ( dp[ i ][ j ] == MAXN ) { continue ; }
            for ( int t = 0 ; t < lim ; ++ t ) {
                if ( check ( j , t ) == false ) { continue ; }
                dp[ i + 1 ][ t ] = min ( dp[ i + 1 ][ t ] , dp[ i ][ j ] + cost ( i + 1 , t ) ) ;
            }
        }
    }
    for ( int i = 0 ; i < lim ; ++ i ) {
        ret = min ( ret , dp[ m - 1 ][ i ] ) ;
    }
    cout << ret << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}