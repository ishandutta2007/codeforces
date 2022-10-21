#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

long long ans = 0 ;

class Trie {
public :
    int cnt = 0 ;
    vector < int > zero ;
    vector < int > one ;
    void add_vertex ( ) {
        zero.push_back ( -1 ) ;
        one.push_back ( -1 ) ;
        ++ cnt ;
    }
    void add ( int x ) {
        int aux = 0 ;
        for ( int i = 29 ; i >= 0 ; -- i ) {
            if ( ( x & (1<<i) ) > 0 ) {
                if ( one[ aux ] == -1 ) {
                    add_vertex ( ) ;
                    one[ aux ] = cnt - 1 ;
                }
                aux = one[ aux ] ;
            }
            else {
                if ( zero[ aux ] == -1 ) {
                    add_vertex ( ) ;
                    zero[ aux ] = cnt - 1 ;
                }
                aux = zero[ aux ] ;
            }
        }
    }
    int f ( int x , int y , int lvl ) {
        if ( lvl < 0 ) { return 0 ; }
        int ret = -1 ;
        if ( zero[ x ] >= 0 && zero[ y ] >= 0 ) {
            int aux = f ( zero[ x ] , zero[ y ] , lvl - 1 ) ;
            if ( ret == -1 || ret > aux ) {
                ret = aux ;
            }
        }
        if ( one[ x ] >= 0 && one[ y ] >= 0 ) {
            int aux = f ( one[ x ] , one[ y ] , lvl - 1 ) ;
            if ( ret == -1 || ret > aux ) {
                ret = aux ;
            }
        }
        if ( ret != -1 ) { return ret ; }
        if ( zero[ x ] >= 0 && one[ y ] >= 0 ) {
            int aux = (1<<lvl) + f ( zero[ x ] , one[ y ] , lvl - 1 ) ;
            if ( ret == -1 || ret > aux ) {
                ret = aux ;
            }
        }
        if ( one[ x ] >= 0 && zero[ y ] >= 0 ) {
            int aux = (1<<lvl) + f ( one[ x ] , zero[ y ] , lvl - 1 ) ;
            if ( ret == -1 || ret > aux ) {
                ret = aux ;
            }
        }
        return ret ;
    }
    void dfs ( int vertex , int lvl ) {
        if ( one[ vertex ] >= 0 && zero[ vertex ] >= 0 ) {
            ans += f ( zero[ vertex ] , one[ vertex ] , lvl - 1 ) ;
            ans += (1<<lvl) ;
        }
        if ( zero[ vertex ] >= 0 ) {
            dfs ( zero[ vertex ] , lvl - 1 ) ;
        }
        if ( one[ vertex ] >= 0 ) {
            dfs ( one[ vertex ] , lvl - 1 ) ;
        }
    }
};
Trie w ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    w.add_vertex ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        w.add ( a[ i ] ) ;
    }
}

void solve ( ) {
    w.dfs ( 0 , 29 ) ;
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}