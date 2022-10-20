#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std ;

#define MAXN 2007

int n ;
string a[ MAXN ] ;
string b[ MAXN ] ;

string str ;

vector < int > v[ 4 * MAXN ] ;

vector < int > rev[ 4 * MAXN ] ;

bool bad = false ;


int used[ 4 * MAXN ] ;
int COMP[ 4 * MAXN ] ;

stack < int > st ;

vector < int > comp_list[ 4 * MAXN ] ;

bool set_fl[ 2 * MAXN ] ;
bool ans[ 2 * MAXN ] ;


void dfs1 ( int vertex ) {
    used[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( used[ v[ vertex ][ i ] ] == 0 ) {
            dfs1 ( v[ vertex ][ i ] ) ;
        }
    }
    st.push ( vertex ) ;
}

void dfs2 ( int vertex , int id ) {
    COMP[ vertex ] = id ;
    comp_list[ id ].push_back ( vertex ) ;
    int sz = rev[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( COMP[ rev[ vertex ][ i ] ] == 0 ) {
            dfs2 ( rev[ vertex ][ i ] , id ) ;
        }
    }
}


void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> b[ i ] ;
    }
    cin >> str ;
    bad = false ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            int true_row = i ;
            int true_col = j + n ;

            int false_row = 2 * n + i ;
            int false_col = 3 * n + j ;
            
            if ( str[ i ] == '1' && str[ j ] == '1' ) {
                if ( a[ i ][ j ] == b[ i ][ j ] ) {
                    v[ true_row ].push_back ( true_col ) ;
                    v[ true_col ].push_back ( true_row ) ;

                    v[ false_row ].push_back ( false_col ) ;
                    v[ false_col ].push_back ( false_row ) ;
                }
                else {
                    v[ true_row ].push_back ( false_col ) ;
                    v[ false_col ].push_back ( true_row ) ;

                    v[ false_row ].push_back ( true_col ) ;
                    v[ true_col ].push_back ( false_row ) ;
                }
            }
            else if ( str[ i ] == '0' && str[ j ] == '1' ) {
                if ( a[ i ][ j ] == b[ i ][ j ] ) {
                    // v[ true_col ].push_back ( false_row ) ;
                    // v[ false_col ].push_back ( false_row ) ;
                    v[ true_row ].push_back ( false_row ) ;
                }
                else {
                    // v[ true_col ].push_back ( true_row ) ;
                    // v[ false_col ].push_back ( true_row ) ;
                    v[ false_row ].push_back ( true_row ) ;
                }
            }
            else if ( str[ i ] == '1' && str[ j ] == '0' ) {
                if ( a[ i ][ j ] == b[ i ][ j ] ) {
                    // v[ true_row ].push_back ( false_col ) ;
                    // v[ false_row ].push_back ( false_col ) ;
                    v[ true_col ].push_back ( false_col ) ;
                }
                else {
                    // v[ true_row ].push_back ( true_col ) ;
                    // v[ false_row ].push_back ( true_col ) ;
                    v[ false_col ].push_back ( true_col ) ;
                }
            }
            else {
                if ( a[ i ][ j ] != b[ i ][ j ] ) { bad = true ; }
            }
        }
    }
    for ( int i = 0 ; i < 4 * n ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            rev[ v[ i ][ j ] ].push_back ( i ) ;
        }
    }
}

void solve ( ) {
    if ( bad == true ) { cout << "-1\n" ; return ; }
    for ( int i = 0 ; i < 4 * n ; ++ i ) {
        if ( used[ i ] == 0 ) {
            dfs1 ( i ) ;
        }
    }
    int id = 1 ;
    while ( st.empty ( ) == false ) {
        int x = st.top ( ) ;
        st.pop ( ) ;
        if ( COMP[ x ] > 0 ) { continue ; }
        dfs2 ( x , id ) ;
        ++ id ;
    }
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        if ( COMP[ i ] == COMP[ 2 * n + i ] ) {
            cout << "-1\n" ;
            return ;
        }
    }
    int ret = 0 ;
    for ( int i = id - 1 ; i >= 1 ; -- i ) {
        int sz = comp_list[ i ].size ( ) ;
        bool fl = false ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int h = comp_list[ i ][ j ] ;
            if ( h >= 2 * n ) { h -= 2 * n ; }
            if ( set_fl[ h ] == false ) { fl = true ; break ; }
        }
        if ( fl == true ) {
            for ( int j = 0 ; j < sz ; ++ j ) {
                int h = comp_list[ i ][ j ] ;
                if ( h < 2 * n ) {
                    ++ ret ;
                    ans[ h ] = true ;
                    set_fl[ h ] = true ;
                }
                else {
                    set_fl[ h - 2 * n ] = true ; 
                }
            }
        }
    }
    cout << ret << "\n" ;
    for ( int i = 0 ; i < 2 * n ; ++ i ) {
        if ( ans[ i ] == true ) {
            if ( i < n ) { cout << "row " << i << "\n" ; }
            else { cout << "col " << i - n << "\n" ; }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}