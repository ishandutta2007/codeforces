#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;


int n , m ;
string a , b ;

int br[ 17 ] ;

vector < string > h[ 17 ] ;

int digcnt ( int x ) {
    int ret = 0 ;
    while ( x != 0 ) {
        ret ++ ;
        x /= 10 ;
    }
    return ret ;
}

void calc ( int x ) {
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        br[ ( a[ i ] - '0' ) ] ++ ;
    }
    int aux = x ;
    while ( aux != 0 ) {
        br[ ( aux % 10 ) ] -- ;
        aux /= 10 ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        br[ ( b[ i ] - '0' ) ] -- ;
    }
    for ( i = 0 ; i < 10 ; i ++ ) {
        while ( br[ i ] != 0 ) {
            br[ i ] -- ;
            string qq ;
            qq.clear ( ) ;
            qq += char( i + '0' ) ;
            h[ i ].push_back ( qq ) ;
        }
    }
    bool fl = true ;
    int id = ( b[ 0 ] - '0' ) ;
    for ( i = 0 ; i < m ; i ++ ) {
        if ( b[ i ] != b[ 0 ] ) {
            if ( b[ i ] > b[ 0 ] ) { fl = false ; }
            break ;
        }
    }
    string gg1 , gg2 ;
    if ( fl == true ) {
        vector < string > g ;
        g.clear ( ) ;
        g.push_back ( b ) ;
        for ( i = 0 ; i < h[ id ].size ( ) ; i ++ ) {
            g.push_back ( h[ id ][ i ] ) ;
        }
        h[ id ].clear ( ) ;
        for ( i = 0 ; i < g.size ( ) ; i ++ ) {
            h[ id ].push_back ( g[ i ] ) ;
        }
        if ( h[ id ].size ( ) >= 2 ) {
            gg1.clear ( ) ;
            gg2.clear ( ) ;
            int upos = -1 ;
            if ( h[ 0 ].size ( ) != 0 ) {
                for ( i = 1 ; i < 10 ; i ++ ) {
                    if ( h[ i ].size ( ) != 0 ) {
                        gg1 += h[ i ][ 0 ] ;
                        upos = i ;
                        break ;
                    }
                }
            }
            for ( i = 0 ; i < 10 ; i ++ ) {
                int stpos = 0 ;
                if ( upos == i ) { stpos ++ ; }
                int sz = h[ i ].size ( ) ;
                for ( j = stpos ; j < sz ; j ++ ) {
                    gg1 += h[ i ][ j ] ;
                }
            }
            swap ( h[ id ][ 0 ] , h[ id ][ 1 ] ) ;
            upos = -1 ;
            if ( h[ 0 ].size ( ) != 0 ) {
                for ( i = 1 ; i < 10 ; i ++ ) {
                    if ( h[ i ].size ( ) != 0 ) {
                        gg2 += h[ i ][ 0 ] ;
                        upos = i ;
                        break ;
                    }
                }
            }
            for ( i = 0 ; i < 10 ; i ++ ) {
                int stpos = 0 ;
                if ( upos == i ) { stpos ++ ; }
                int sz = h[ i ].size ( ) ;
                for ( j = stpos ; j < sz ; j ++ ) {
                    gg2 += h[ i ][ j ] ;
                }
            }
            if ( gg1 < gg2 ) { swap ( h[ id ][ 0 ] , h[ id ][ 1 ] ) ; }
        }
    }
    else {
        h[ id ].push_back ( b ) ;
    }
    int pos = 0 ;
    if ( h[ 0 ].size ( ) == 0 ) { pos = -1 ; }
    else {
        for ( i = 1 ; i < 10 ; i ++ ) {
            if ( h[ i ].size ( ) != 0 ) {
                cout << h[ i ][ 0 ] ;
                pos = i ;
                break ;
            }
        }
    }
    for ( i = 0 ; i < 10 ; i ++ ) {
        int stpos = 0 ;
        if ( pos == i ) { stpos ++ ; }
        int sz = h[ i ].size ( ) ;
        for ( j = stpos ; j < sz ; j ++ ) {
            cout << h[ i ][ j ] ;
        }
    }
    cout << "\n" ;
}

void input ( ) {
    cin >> a >> b ;
    n = a.size ( ) ;
    m = b.size ( ) ;
}

void solve ( ) {
    if ( n == 2 ) {
        if ( a[ 0 ] == '1' && a[ 1 ] == '0' ) {
            cout << "0\n" ;
        }
        if ( a[ 1 ] == '1' && a[ 0 ] == '0' ) {
            cout << "0\n" ;
        }
    }
    int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i + digcnt ( i ) == n ) {
            ans = i ;
            break ;
        }
    }
    calc ( ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}