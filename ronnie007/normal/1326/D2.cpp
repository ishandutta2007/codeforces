#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<random>
using namespace std ;

#define NUM 3 
#define MAXN 1000007

#define BASE 26
long long MOD[ 3 ] ;

int n ;
string a ;

struct tuhla {
    long long h[ NUM ] ;
};

tuhla fw[ MAXN ] ;
tuhla rv[ MAXN ] ;

tuhla pw[ MAXN ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int st , en ;
    st = 1 ; en = n ;
    while ( st <= en && a[ st - 1 ] == a[ en - 1 ] ) {
        ++ st , -- en ;
    }
    if ( st > en ) { cout << a << "\n" ; return ; }
    for ( int j = 0 ; j < NUM ; ++ j ) {
        fw[ st - 1 ].h[ j ] = 0 ;
    }
    for ( int i = st ; i <= en ; ++ i ) {
        int aux = ( a[ i - 1 ] - 'a' ) ;
        for ( int j = 0 ; j < NUM ; ++ j ) {
            fw[ i ].h[ j ] = ( fw[ i - 1 ].h[ j ] * BASE + aux ) % MOD[ j ] ;
        }
    }
    for ( int j = 0 ; j < NUM ; ++ j ) {
        rv[ en + 1 ].h[ j ] = 0 ;
    }
    for ( int i = en ; i >= st ; -- i ) {
        int aux = ( a[ i - 1 ] - 'a' ) ;
        for ( int j = 0 ; j < NUM ; ++ j ) {
            rv[ i ].h[ j ] = ( rv[ i + 1 ].h[ j ] * BASE + aux ) % MOD[ j ] ;
        }
    }

    int len = 0 ;
    int pos = 0 ;
    int side = -1 ;

    for ( int i = en ; i >= st ; -- i ) {
        tuhla aux = rv[ st ] ;
        for ( int j = 0 ; j < NUM ; ++ j ) {
            long long sub = ( rv[ i + 1 ].h[ j ] * pw[ i - st + 1 ].h[ j ] ) % MOD[ j ] ;
            aux.h[ j ] = ( aux.h[ j ] - sub + MOD[ j ] ) % MOD[ j ] ;
        }
        int j ;
        for ( j = 0 ; j < NUM ; ++ j ) {
            if ( aux.h[ j ] != fw[ i ].h[ j ] ) { break ; }
        }
        if ( j == NUM ) {
            pos = i ;
            side = 0 ;
            break ;
        }
    }
    for ( int i = st ; i <= en ; ++ i ) {
        tuhla aux = fw[ en ] ;
        for ( int j = 0 ; j < NUM ; ++ j ) {
            long long sub = ( fw[ i - 1 ].h[ j ] * pw[ en - i + 1 ].h[ j ] ) % MOD[ j ] ;
            aux.h[ j ] = ( aux.h[ j ] - sub + MOD[ j ] ) % MOD[ j ] ;
        }
        int j ;
        for ( j = 0 ; j < NUM ; ++ j ) {
            if ( aux.h[ j ] != rv[ i ].h[ j ] ) { break ; }
        }
        if ( j == NUM ) {
            if ( en - i + 1 > pos - st + 1 ) {
                pos = i ;
                side = 1 ;
                break ;
            }
        }
    }
    for ( int i = 1 ; i < st ; ++ i ) {
        cout << a[ i - 1 ] ;
    }
    if ( side == 0 ) {
        for ( int i = st ; i <= pos ; ++ i ) {
            cout << a[ i - 1 ] ;
        }
    }
    else {
        for ( int i = pos ; i <= en ; ++ i ) {
            cout << a[ i - 1 ] ;
        }
    }
    for ( int i = en + 1 ; i <= n ; ++ i ) {
        cout << a[ i - 1 ] ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    MOD[ 0 ] = 1000000007 ;
    MOD[ 1 ] = 998244353 ;
    MOD[ 2 ] = 83928329 ;

    for ( int j = 0 ; j < NUM ; ++ j ) {
        pw[ 0 ].h[ j ] = 1 ;
    }
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < NUM ; ++ j ) {
            pw[ i ].h[ j ] = ( pw[ i - 1 ].h[ j ] * BASE ) % MOD[ j ] ;
        }
    }
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}