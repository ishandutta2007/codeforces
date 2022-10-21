#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007

string a ;
int n ;
int cnt[ MAXN ] ;
string s[ MAXN ] ;

int vert_cnt ;

int win[ MAXN ] ;
vector < int > v[ MAXN ] ;


class aho_corasick {
    public :
    bool wordend[ MAXN ] ;
    int wordid[ MAXN ] ;
    int PI[ MAXN ] ;
    map < int , int > to[ MAXN ] ;
    void init ( ) {
        int i ;
        for ( i = 0 ; i < MAXN ; i ++ ) {
            wordend[ i ] = false ;
            wordid[ i ] = 0 ;
            PI[ i ] = 0 ;
            to[ i ].clear ( ) ;
        }
        vert_cnt = 1 ;
    }
    void add_string ( string &aux , int idx ) {
        int sz = aux.size ( ) ;
        int cur = 1 ;
        int i ;
        for ( i = 0 ; i < sz ; i ++ ) {
            int val = ( aux[ i ] - 'a' ) ;
            if ( to[ cur ].find ( val ) == to[ cur ].end ( ) ) {
                vert_cnt ++ ;
                to[ cur ][ val ] = vert_cnt ;
            }
            cur = to[ cur ][ val ] ;
        }
        wordend[ cur ] = true ;
        wordid[ cur ] = idx ;
    }
    void calc_links ( ) {
        queue < int > q ;
        q.push ( 1 ) ;
        PI[ 1 ] = 0 ;
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            map < int , int > :: iterator it ;
            for ( it = to[ x ].begin ( ) ; it != to[ x ].end ( ) ; it ++ ) {
                int letter = (*it).first ;
                int nwvertex = (*it).second ;
                int lst = PI[ x ] ;
                while ( lst != 0 && to[ lst ].find ( letter ) == to[ lst ].end ( ) ) { lst = PI[ lst ] ; }
                PI[ nwvertex ] = 1 ;
                if ( lst != 0 ) { lst = to[ lst ][ letter ] ; PI[ nwvertex ] = lst ; }

                if ( wordend[ lst ] == true ) { win[ nwvertex ] = lst ; }
                else { win[ nwvertex ] = win[ lst ] ; }
                q.push ( nwvertex ) ;
            }
        }
    }
};

aho_corasick w ;

void input ( ) {
    cin >> a ;
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> cnt[ i ] >> s[ i ] ;
    }
}

void solve ( ) {
    w.init ( ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        w.add_string ( s[ i ] , i ) ;
    }
    w.calc_links ( ) ;
    int p = a.size ( ) ;
    int cur = 1 ;
    for ( i = 0 ; i < p ; i ++ ) {
        int val = ( a[ i ] - 'a' ) ;
        while ( cur != 1 && w.to[ cur ].find ( val ) == w.to[ cur ].end ( ) ) { cur = w.PI[ cur ] ; }
        if ( w.to[ cur ].find ( val ) != w.to[ cur ].end ( ) ) {
            cur = w.to[ cur ][ val ] ;
        }
        int aux = cur ;
        while ( aux != 0 ) {
            if ( w.wordend[ aux ] == true ) {
                v[ w.wordid[ aux ] ].push_back ( i ) ;
            }
            aux = win[ aux ] ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        int sz = v[ i ].size ( ) ;
        int ans = -1 ;
        int h = s[ i ].size ( ) ;
        for ( j = cnt[ i ] - 1 ; j < sz ; j ++ ) {
            int cur = ( v[ i ][ j ] - v[ i ][ j - cnt[ i ] + 1 ] + h ) ;
            if ( ans < 0 ) { ans = cur ; }
            if ( ans > cur ) { ans = cur ; }
        }
        cout << ans << "\n" ;
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}