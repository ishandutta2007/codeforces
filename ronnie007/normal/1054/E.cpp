#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n , m ;
string a[ MAXN ][ MAXN ] ;
queue < int > init[ MAXN ][ MAXN ] ;
int coef[ MAXN ][ MAXN ] ;


string sr[ MAXN ][ MAXN ] ;

struct tuhla {
    int stx , sty ;
    int enx , eny ;
    tuhla ( ) { stx = sty = enx = eny = 0 ; }
    tuhla ( int _stx , int _sty , int _enx , int _eny ) {
        stx = _stx ; sty = _sty ;
        enx = _enx ; eny = _eny ;
    }
};

vector < tuhla > v ;

void collect ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            while ( init[ i ][ j ].empty ( ) == false ) {
                int aux = init[ i ][ j ].front ( ) ;
                init[ i ][ j ].pop ( ) ;
                if ( aux == 1 ) {
                    if ( i == 1 ) {
                        int pl = 1 ;
                        if ( j == 1 ) { pl = m ; }
                        v.push_back ( tuhla ( i , j , i , pl ) ) ;
                        ++ coef[ i ][ pl ] ;
                    }
                    else {
                        v.push_back ( tuhla ( i , j , 1 , j ) ) ;
                        ++ coef[ 1 ][ j ] ;
                    }
                }
                else {
                    if ( i == n ) {
                        int pl = m ;
                        if ( j == m ) { pl = 1 ; }
                        v.push_back ( tuhla ( i , j , i , pl ) ) ;
                        ++ coef[ i ][ pl ] ;
                    }
                    else {
                        v.push_back ( tuhla ( i , j , n , j ) ) ;
                        ++ coef[ n ][ j ] ;
                    }
                }
            }
        }
    }
    for ( int i = 2 ; i <= m ; ++ i ) {
        while ( coef[ 1 ][ i ] -- ) {
            v.push_back ( tuhla ( 1 , i , 1 , 1 ) ) ;
        }
    }
    for ( int i = 1 ; i < m ; ++ i ) {
        while ( coef[ n ][ i ] -- ) {
            v.push_back ( tuhla ( n , i , n , m ) ) ;
        }
    }
}


void reconstruct ( ) {
    for ( int i = 2 ; i < n ; ++ i ) {
        for ( int j = 2 ; j < m ; ++ j ) {
            int sz = sr[ i ][ j ].size ( ) ;
            for ( int t = sz - 1 ; t >= 0 ; -- t ) {
                if ( sr[ i ][ j ][ t ] == '0' ) {
                    v.push_back ( tuhla ( n , m , i , m ) ) ;
                    v.push_back ( tuhla ( i , m , i , j ) ) ;
                }
                else {
                    v.push_back ( tuhla ( 1 , 1 , i , 1 ) ) ;
                    v.push_back ( tuhla ( i , 1 , i , j ) ) ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            if ( i == 1 && j == m ) { continue ; }
            if ( i == n && j == 1 ) { continue ; }
            if ( 1 < i && i < n ) {
                if ( 1 < j && j < m ) { continue ; }
            }
            int sz = sr[ i ][ j ].size ( ) ;
            for ( int t = sz - 1 ; t >= 0 ; -- t ) {
                if ( sr[ i ][ j ][ t ] == '0' ) {
                    if ( ( i != n && j != m ) || ( i == n && j == m ) ) {
                        if ( i == 1 ) { 
                            v.push_back ( tuhla ( n , m , 1 , m ) ) ;
                            v.push_back ( tuhla ( 1 , m , i , j ) ) ;
                        }
                        else {
                            v.push_back ( tuhla ( n , m , n , 1 ) ) ;
                            v.push_back ( tuhla ( n , 1 , i , j ) ) ;
                        }
                    }
                    else {
                        v.push_back ( tuhla ( n , m , i , j ) ) ;
                    }
                }
                else {
                    if ( ( i != 1 && j != 1 ) || ( i == 1 && j == 1 ) ) {
                        if ( i == n ) { 
                            v.push_back ( tuhla ( 1 , 1 , n , 1 ) ) ;
                            v.push_back ( tuhla ( n , 1 , i , j ) ) ;
                        }
                        else {
                            v.push_back ( tuhla ( 1 , 1 , 1 , m ) ) ;
                            v.push_back ( tuhla ( 1 , m , i , j ) ) ;
                        }
                    }
                    else {
                        v.push_back ( tuhla ( 1 , 1 , i , j ) ) ;
                    }
                }
            }
        }
    }
    int sz = sr[ 1 ][ m ].size ( ) ;
    for ( int t = sz - 1 ; t >= 0 ; -- t ) {
        if ( sr[ 1 ][ m ][ t ] == '0' ) {
            v.push_back ( tuhla ( n , m , 1 , m ) ) ;
        }
        else {
            v.push_back ( tuhla ( 1 , 1 , 1 , m ) ) ;
        }
    }
    sz = sr[ n ][ 1 ].size ( ) ;
    for ( int t = sz - 1 ; t >= 0 ; -- t ) {
        if ( sr[ n ][ 1 ][ t ] == '0' ) {
            v.push_back ( tuhla ( n , m , n , 1 ) ) ;
        }
        else {
            v.push_back ( tuhla ( 1 , 1 , n , 1 ) ) ;
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
            int sz = a[ i ][ j ].size ( ) ;
            for ( int t = sz - 1 ; t >= 0 ; -- t ) {
                init[ i ][ j ].push ( a[ i ][ j ][ t ] - '0' ) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> sr[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    collect ( ) ;
    reconstruct ( ) ;
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ].stx << " " << v[ i ].sty << " " << v[ i ].enx << " " << v[ i ].eny << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}