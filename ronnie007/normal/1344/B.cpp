#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;
string a[ MAXN ] ;

bool used[ MAXN ][ MAXN ] ;

int cnt_r[ MAXN ] ;
int cnt_c[ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

int total = 0 ;
bool allrows ;
bool allcols ;

bool check ( int x , int y ) {
    if ( x < 0 || x >= n ) { return false ; }
    if ( y < 0 || y >= m ) { return false ; }
    return true ;
}

void proc ( int stx , int sty ) {
    queue < pair < int , int > > q ;
    q.push ( { stx , sty } ) ;
    used[ stx ][ sty ] = true ;

    while ( q.empty ( ) == false ) {
        pair < int , int > aux = q.front ( ) ;
        q.pop ( ) ;
        for ( int i = 0 ; i < 4 ; ++ i ) {
            int nx = aux.first + dx[ i ] ;
            int ny = aux.second + dy[ i ] ;
            if ( check ( nx , ny ) == false ) { continue ; }
            if ( a[ nx ][ ny ] == '#' && used[ nx ][ ny ] == false ) {
                used[ nx ][ ny ] = true ;
                q.push ( { nx , ny } ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == '#' ) {
                ++ cnt_r[ i ] ;
                ++ cnt_c[ j ] ;
                ++ total ;
            }
        }
    }
}

void solve ( ) {
    allrows = allcols = true ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( cnt_r[ i ] == 0 ) { allrows = false ; }
    }
    for ( int i = 0 ; i < m ; ++ i ) {
        if ( cnt_c[ i ] == 0 ) { allcols = false ; }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( cnt_r[ i ] == 0 && allcols == true ) {
            cout << "-1\n" ;
            return ;
        }
    }
    for ( int j = 0 ; j < m ; ++ j ) {
        if ( cnt_c[ j ] == 0 && allrows == true ) {
            cout << "-1\n" ;
            return ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        int st = 0 ;
        for ( st = 0 ; st < m ; ++ st ) {
            if ( a[ i ][ st ] == '#' ) { break ; }
        }
        while ( cnt_r[ i ] > 0 ) {
            if ( a[ i ][ st ] != '#' ) {
                cout << "-1\n" ;
                return ;
            }
            -- cnt_r[ i ] ;
            ++ st ;
        }
    }

    for ( int j = 0 ; j < m ; ++ j ) {
        int st = 0 ;
        for ( st = 0 ; st < n ; ++ st ) {
            if ( a[ st ][ j ] == '#' ) { break ; }
        }
        while ( cnt_c[ j ] > 0 ) {
            if ( a[ st ][ j ] != '#' ) {
                cout << "-1\n" ;
                return ;
            }
            -- cnt_c[ j ] ;
            ++ st ;
        }
    }
    int ans = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < m ; ++ j ) {
            if ( a[ i ][ j ] == '#' && used[ i ][ j ] == false ) {
                ++ ans ;
                proc ( i , j ) ;
            }
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}