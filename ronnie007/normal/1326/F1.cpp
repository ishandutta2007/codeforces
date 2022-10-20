#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 14 ;


int n ;
string a[ MAXN ] ;
ll ans[ ( 1 << MAXN ) ] ;

vector < int > v[ 2 ] ;

int dp[ 2 ][ 7 ][ ( 1 << 7 ) ] ;
int mr[ 14 ] ;
int targ_l , targ_r ;

int aux[ 8 ] ;

void upd ( int rep , int sz ) {
    int val = 0 ;
    for ( int i = sz - 2 ; i >= 0 ; -- i ) {
        val *= 2 ;
        if ( a[ aux[ i ] ][ aux[ i + 1 ] ] == '1' ) { ++ val ; }
    }
    if ( rep == 0 ) {
        ++ dp[ rep ][ mr[ aux[ sz - 1 ] ] ][ val ] ;
    }
    else {
        ++ dp[ rep ][ mr[ aux[ 0 ] ] ][ val ] ;
    }
}

void calc ( ) {
    for ( int rep = 0 ; rep < 2 ; ++ rep ) {
        int sz = v[ rep ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            for ( int j = 0 ; j < ( 1 << ( sz - 1 ) ) ; ++ j ) {
                dp[ rep ][ i ][ j ] = 0 ;
            }
        }
        for ( int i = 0 ; i < sz ; ++ i ) {
            aux[ i ] = v[ rep ][ i ] ;
        }
        upd ( rep , sz ) ;
        while ( next_permutation ( aux , aux + sz ) ) {
            upd ( rep , sz ) ;
        }
    }
    for ( int i = 0 ; i < targ_l ; ++ i ) {
        for ( int j = 0 ; j < ( 1 << ( targ_l - 1 ) ) ; ++ j ) {
            if ( dp[ 0 ][ i ][ j ] == 0 ) { continue ; }
            for ( int t = 0 ; t < targ_r ; ++ t ) {
                for ( int z = 0 ; z < ( 1 << ( targ_r - 1 ) ) ; ++ z ) {
                    if( dp[ 1 ][ t ][ z ] == 0 ) { continue ; }
                    int nw = ( z << targ_l ) + j ;
                    if ( a[ v[ 0 ][ i ] ][ v[ 1 ][ t ] ] == '1' ) {
                        nw += ( 1 << ( targ_l - 1 ) ) ;
                    }
                    ans[ nw ] += dp[ 0 ][ i ][ j ] * dp[ 1 ][ t ][ z ] ;
                }
            }
        }
    }
}

void f ( int pos , int sz1 , int sz2 ) {
    int lft = n - pos ;
    if ( sz1 + lft < targ_l || sz2 + lft < targ_r ) { return ; }
    if ( pos == n ) {
        calc ( ) ;
        return ;
    }
    v[ 0 ].push_back ( pos ) ;
    mr[ pos ] = sz1 ;
    f ( pos + 1 , sz1 + 1 , sz2 ) ;
    v[ 0 ].pop_back ( ) ;

    v[ 1 ].push_back ( pos ) ;
    mr[ pos ] = sz2 ;
    f ( pos + 1 , sz1 , sz2 + 1 ) ;
    v[ 1 ].pop_back ( ) ;
}

void solve ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    targ_r = ( n / 2 ) ;
    targ_l = n - targ_r ;
    f ( 0 , 0 , 0 ) ;
    for ( int i = 0 ; i < ( 1 << ( n - 1 ) ) ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}