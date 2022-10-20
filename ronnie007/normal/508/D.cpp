#include<bits/stdc++.h>
using namespace std ;

#define MAXN 3845

int n ;
vector < int > v[ MAXN ] ;
int len[ MAXN ] ;
int in_deg[ MAXN ] ;
int out_deg[ MAXN ] ;

int id[ MAXN ] ;

stack < int > aux ;

int get_val ( char c ) {
    if ( c >= 'a' && c <= 'z' ) {
        return ( c - 'a' ) ;
    }
    else if ( c >= 'A' && c <= 'Z' ) {
        return 26 + ( c - 'A' ) ;
    }
    else {
        return 52 + ( c - '0' ) ;
    }
}
char get_char ( int val ) {
    if ( val < 26 ) {
        return char ( val + 'a' ) ;
    }
    else if ( val < 52 ) {
        return char ( ( val - 26 ) + 'A' ) ;
    }
    else {
        return char ( ( val - 52 ) + '0' ) ;
    }
}

int encode ( char c1 , char c2 ) {
    return 62 * get_val ( c1 ) + get_val ( c2 ) ;
}
char decode ( int val , int id ) {
    if ( id == 0 ) {
        return get_char ( ( val / 62 ) ) ;
    }
    else {
        return get_char ( ( val % 62 ) ) ;
    }
}

void dfs ( int vertex ) {
    aux.push ( vertex ) ;
    if ( id[ vertex ] < len[ vertex ] ) {
        int x = v[ vertex ][ id[ vertex ] ++ ] ;
        dfs ( x ) ;
    }
}

void input ( ) {
    cin >> n ;
    string s ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> s ;
        int x = encode ( s[ 0 ] , s[ 1 ] ) ;
        int y = encode ( s[ 1 ] , s[ 2 ] ) ;
        v[ x ].push_back ( y ) ;
        ++ out_deg[ x ] ; ++ in_deg[ y ] ;
    }
}

void solve ( ) {
    int st = -1 ;
    int bal = 0 ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        len[ i ] = v[ i ].size ( ) ;
        if ( in_deg[ i ] == out_deg[ i ] ) { continue ; }
        if ( in_deg[ i ] < out_deg[ i ] ) {
            if ( out_deg[ i ] - in_deg[ i ] > 1 || st != -1 ) {
                cout << "NO\n" ;
                return ;
            }
            st = i ;
            ++ bal ;
        }
        else {
            if ( in_deg[ i ] - out_deg[ i ] > 1 ) {
                cout << "NO\n" ;
                return ;
            }
            -- bal ;
        }
    }
    if ( bal != 0 ) { cout << "NO\n" ; return ; }
    if ( st == -1 ) {
        for ( int i = 0 ; i < MAXN ; ++ i ) {
            if ( out_deg[ i ] > 0 ) {
                st = i ;
                break ;
            }
        }
    }
    dfs ( st ) ;
    stack < int > ans ;
    int sz ;
    while ( aux.empty ( ) == false ) {
        sz = aux.size ( ) ;
        int x = aux.top ( ) ;
        aux.pop ( ) ;
        dfs ( x ) ;
        if ( aux.size ( ) == sz ) {
            ans.push ( x ) ;
            aux.pop ( ) ;
        }
    }
    if ( ans.size ( ) != n + 1 ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
    while ( 1 ) {
        int x = ans.top ( ) ;
        ans.pop ( ) ;
        if ( ans.empty ( ) == false ) {
            cout << decode ( x , 0 ) ;
        }
        else {
            cout << decode ( x , 0 ) << decode ( x , 1 ) ;
            break ;
        }
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}