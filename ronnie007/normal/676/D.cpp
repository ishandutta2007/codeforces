#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 1007

int n , m ;
string a[ MAXN ] ;

pair < int , int > st , en ;

int dp[ MAXN ][ MAXN ][ 4 ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

struct tuhla {
    int x , y ;
    int rot ;
    tuhla ( ) { x = y = rot = 0 ; }
    tuhla ( int _x , int _y , int _rot ) { x = _x ; y = _y ; rot = _rot ; }
};

char f ( char c ) {
    if ( c == '+' ) { return '+' ; }
    if ( c == '-' ) { return '|' ; }
    if ( c == '|' ) { return '-' ; }
    if ( c == '^' ) { return '>' ; }
    if ( c == '>' ) { return 'v' ; }
    if ( c == 'v' ) { return '<' ; }
    if ( c == '<' ) { return '^' ; }
    if ( c == 'U' ) { return 'R' ; }
    if ( c == 'R' ) { return 'D' ; }
    if ( c == 'D' ) { return 'L' ; }
    if ( c == 'L' ) { return 'U' ; }
    if ( c == '*' ) { return '*' ; }
}

char getnxt ( char c , int tm ) {
    while ( tm != 0 ) {
        c = f ( c ) ;
        tm -- ;
    }
    return c ;
}

bool can ( char c , int dir ) {
    if ( c == '*' ) { return false ; }
    if ( dir == 0 ) {
        if ( c == '+' || c == '|' || c == 'v' || c == 'U' || c == 'L' || c == 'R' ) { return true ; }
        return false ;
    }
    if ( dir == 1 ) {
        if ( c == '+' || c == '|' || c == '^' || c == 'D' || c == 'L' || c == 'R' ) { return true ; }
        return false ;
    }
    if ( dir == 2 ) {
        if ( c == '+' || c == '-' || c == '>' || c == 'U' || c == 'D' || c == 'L' ) { return true ; }
        return false ;
    }
    if ( dir == 3 ) {
        if ( c == '+' || c == '-' || c == '<' || c == 'U' || c == 'D' || c == 'R' ) { return true ; }
    }
    return false ;
}

void bfs ( ) {
    queue < tuhla > q ;
    q.push ( tuhla ( st.first , st.second , 0 ) ) ;
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            for ( t = 0 ; t < 4 ; t ++ ) {
                dp[ i ][ j ][ t ] = -1 ;
            }
        }
    }
    dp[ st.first ][ st.second ][ 0 ] = 0 ;
    while ( q.empty ( ) == false ) {
        tuhla u = q.front ( ) ;
        q.pop ( ) ;
        int id = ( u.rot + 1 ) % 4 ;
        if ( dp[ u.x ][ u.y ][ id ] == -1 ) {
            dp[ u.x ][ u.y ][ id ] = dp[ u.x ][ u.y ][ u.rot ] + 1 ;
            q.push ( tuhla ( u.x , u.y , id ) ) ;
        }
        char sym = getnxt ( a[ u.x - 1 ][ u.y - 1 ] , u.rot ) ;
        for ( i = 0 ; i < 4 ; i ++ ) {
            int nx = u.x + dx[ i ] ;
            int ny = u.y + dy[ i ] ;
            if ( nx < 1 || nx > n ) { continue ; }
            if ( ny < 1 || ny > m ) { continue ; }
            if ( can ( getnxt ( a[ u.x - 1 ][ u.y - 1 ] , u.rot ) , i ) == false || can ( getnxt ( a[ nx - 1 ][ ny - 1 ] , u.rot ) , i^1 ) == false ) { continue ; }
            if ( dp[ nx ][ ny ][ u.rot ] != -1 ) { continue ; }
            dp[ nx ][ ny ][ u.rot ] = dp[ u.x ][ u.y ][ u.rot ] + 1 ;
            q.push ( tuhla ( nx , ny , u.rot ) ) ;
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ;
    }
    cin >> st.first >> st.second ;
    cin >> en.first >> en.second ;
}

void solve ( ) {
    bfs ( ) ;
    int ans = -1 ;
    int i ;
    for ( i = 0 ; i < 4 ; i ++ ) {
        if ( dp[ en.first ][ en.second ][ i ] == -1 ) { continue ; }
        if ( ans == -1 ) {
            ans = dp[ en.first ][ en.second ][ i ] ;
        }
        if ( ans > dp[ en.first ][ en.second ][ i ] ) {
            ans = dp[ en.first ][ en.second ][ i ] ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}