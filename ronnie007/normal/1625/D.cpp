#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 300007
#define mxbit 29

int n , k ;
int a[ MAXN ] ;

struct node {
    int cnt ;
    int cand ;
    node *to[ 2 ] ;
    node ( ) {
        cnt = cand = 0 ;
        to[ 0 ] = to[ 1 ] = NULL ;
    }
};

int tp = 0 ;
map < node* , int > posmap ;

vector < int > idvec[ MAXN ] ;

node *root ;
vector < int > ans ;

void add ( int x , int id ) {
    node *aux = root ;
    bool seen = false ;
    for ( int i = mxbit ; i >= 0 ; -- i ) {
        int nxt = 0 ;
        if ( ( x & ( 1 << i ) ) > 0 ) { nxt = 1 ; }

        if ( aux->to[ nxt ] == NULL ) {
            aux->to[ nxt ] = new node ( ) ;
        }
        aux = aux->to[ nxt ] ;
        ++ aux->cnt ;
        aux->cand = id ;
        if ( ( k & ( 1 << i ) ) > 0 && seen == false ) {
            if ( posmap[ aux ] == 0 ) {
                posmap[ aux ] = ++ tp ;
            }
            idvec[ posmap[ aux ] ].push_back ( id ) ;
            seen = true ;
        }
    }
}

int ch ( node *wh , int hh , int lvl ) {
    if ( wh == NULL ) { return -1 ; }
    if ( lvl == -1 ) {
        return wh->cand ;
    }
    int nxt = 0 ;
    if ( ( k & ( 1 << lvl ) ) > 0 ) { nxt ^= 1 ; }

    if ( nxt == 1 ) {
        if ( ( hh & ( 1 << lvl ) ) == 0 ) {
            return ch ( wh->to[ 1 ] , hh , lvl - 1 ) ;
        }
        else {
            return ch ( wh->to[ 0 ] , hh , lvl - 1 ) ;
        }
    }
    else {
        if ( ( hh & ( 1 << lvl ) ) == 0 ) {
            if ( wh->to[ 1 ] != NULL ) {
                return wh->to[ 1 ]->cand ;
            }
            else {
                return ch ( wh->to[ 0 ] , hh , lvl - 1 ) ;
            }
        }
        else {
            if ( wh->to[ 0 ] != NULL ) {
                return wh->to[ 0 ]->cand ;
            }
            else {
                return ch ( wh->to[ 1 ] , hh , lvl - 1 ) ;
            }
        }
    }
}

void rec ( node *wh , int lvl ) {
    if ( lvl == -1 ) {
        ans.push_back ( wh->cand ) ;
        return ;
    }
    int nxt = 0 ;
    if ( ( k & ( 1 << lvl ) ) > 0 ) { nxt = 1 ; }

    if ( nxt == 0 ) {
        if ( wh->to[ 0 ] != NULL ) {
            rec ( wh->to[ 0 ] , lvl - 1 ) ;
        }
        if ( wh->to[ 1 ] != NULL ) {
            rec ( wh->to[ 1 ] , lvl - 1 ) ;
        }
    }
    else {
        if ( wh->to[ 0 ] == NULL ) {
            ans.push_back ( wh->to[ 1 ]->cand ) ;
        }
        else if ( wh->to[ 1 ] == NULL ) {
            ans.push_back ( wh->to[ 0 ]->cand ) ;
        }
        else {
            bool found = false ;
            for ( auto pos1 : idvec[ posmap[ wh->to[ 0 ] ] ] ) {
                int ret = ch ( wh->to[ 1 ] , a[ pos1 ] , lvl - 1 ) ;
                if ( ret != -1 ) {
                    ans.push_back ( pos1 ) ;
                    ans.push_back ( ret ) ;
                    found = true ;
                    break ;
                }
            }
            if ( found == false ) { 
                ans.push_back ( wh->to[ 0 ]->cand ) ;
            }
        }
    }
}

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( k == 0 ) {
        cout << n << "\n" ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            cout << i << " " ;
        }
        cout << "\n" ;
        return ;
    }
    root = new node ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        add ( a[ i ] , i ) ;
    }
    rec ( root , mxbit ) ;
    int sz = ans.size ( ) ;
    if ( sz < 2 ) {
        cout << "-1\n" ;
        return ;
    }
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}