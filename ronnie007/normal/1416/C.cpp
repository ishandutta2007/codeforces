#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 300007

int n ;
int a[ MAXN ] ;

long long init[ 37 ] ;
long long sm[ 37 ] ;

struct node {
    node *pl , *pr ;
    int lvl ;
    int cnt ;
    node ( ) { pl = pr = NULL ; lvl = cnt = 0 ; }
    node ( int _lvl ) {
        pl = pr = NULL ;
        lvl = _lvl ;
        cnt = 0 ;
    }
};

node *root ;

int get_sz ( node *aux ) {
    if ( aux == NULL ) { return 0 ; }
    return aux->cnt ;
}

void add ( int x ) {
    node *where = root ;
    for ( int i = 29 ; i >= 0 ; -- i ) {
        ++ where->cnt ;
        int bit = 0 ;
        if ( ( x & (1<<i) ) > 0 ) { bit = 1 ; }
        if ( bit == 0 ) {
            init[ where->lvl ] += get_sz ( where->pr ) ;
            sm[ where->lvl ] += get_sz ( where->pr ) ;

            if ( where->pl == NULL ) {
                where->pl = new node ( where->lvl - 1 ) ;
            }
            where = where->pl ;
        }
        else {
            sm[ where->lvl ] += get_sz ( where->pl ) ;
            if ( where->pr == NULL ) {
                where->pr = new node ( where->lvl - 1 ) ;
            }
            where = where->pr ;
        }
    }
    ++ where->cnt ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    root = new node ( 29 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        add ( a[ i ] ) ;
    }
    long long ans = 0 ;
    int val = 0 ;
    for ( int i = 29 ; i >= 0 ; -- i ) {
        if ( init[ i ] <= sm[ i ] - init[ i ] ) {
            ans += init[ i ] ;
        }
        else {
            val += (1<<i) ;
            ans += sm[ i ] - init[ i ] ;
        }
    }
    cout << ans << " " << val << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}