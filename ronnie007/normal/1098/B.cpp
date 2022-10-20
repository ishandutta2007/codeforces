#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , m ;
vector < string > v ;

vector < string > cand ;
int ans = MAXN ; 
vector < string > best ;

char a[ 4 ] = { 'A' , 'G' , 'C' , 'T' } ;

int perm[ 4 ] = { 0 , 1 , 2 , 3 } ;

void f ( ) {
    int aux = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            aux += ( cand[ i ][ j ] != v[ i ][ j ] ) ;
        }
    }
    if ( ans > aux ) {
        ans = aux ;
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j < m ; ++ j ) {
                best[ i ][ j ] = cand[ i ][ j ] ;
            }
        }
    }
}

int opt_row ( int id ) {
    int ret1 , ret2 ;
    ret1 = ret2 = 0 ;
    int offset = 2 * ( id & 1 ) ;
    int pos1 = 0 , pos2 = 1 ;
    for ( int j = 0 ; j < m ; ++ j ) {
        ret1 += ( v[ id ][ j ] != a[ perm[ offset + pos1 ] ] ) ;
        ret2 += ( v[ id ][ j ] != a[ perm[ offset + pos2 ] ] ) ;
        pos1 ^= 1 ; pos2 ^= 1 ;
    }
    if ( ret1 <= ret2 ) { return 0 ; }
    return 1 ;
}

int opt_col ( int id ) {
    int ret1 , ret2 ;
    ret1 = ret2 = 0 ;
    int offset = 2 * ( id & 1 ) ;
    int pos1 = 0 , pos2 = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        ret1 += ( v[ i ][ id ] != a[ perm[ offset + pos1 ] ] ) ;
        ret2 += ( v[ i ][ id ] != a[ perm[ offset + pos2 ] ] ) ;
        pos1 ^= 1 ; pos2 ^= 1 ;
    }
    if ( ret1 <= ret2 ) { return 0 ; }
    return 1 ;
}

void proc ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        int offset = 2 * ( i & 1 ) ;
        int ret = opt_row ( i ) ;
        for ( int j = 0 ; j < m ; ++ j ) {
            cand[ i ][ j ] = a[ perm[ offset + ret ] ] ;
            ret ^= 1 ;
        }
    }
    f ( ) ;
    for ( int j = 0 ; j < m ; ++ j ) {
        int offset = 2 * ( j & 1 ) ;
        int ret = opt_col ( j ) ;
        for ( int i = 0 ; i < n ; ++ i ) {
            cand[ i ][ j ] = a[ perm[ offset + ret ] ] ;
            ret ^= 1 ;
        }        
    }
    f ( ) ;
}

void input ( ) {
    cin >> n >> m ;
    v.resize ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> v[ i ] ;
    }
}

void solve ( ) {
    cand.resize ( n ) ; best.resize ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cand[ i ].resize ( m ) ;
        best[ i ].resize ( m ) ;
    }
    do {
        proc ( ) ;
    } while ( next_permutation ( perm , perm + 4 ) ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cout << best[ i ] << "\n" ;
    }
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