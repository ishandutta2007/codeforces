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
using namespace std ;

#define MAXN 200007
#define LOG 21 

int n ;
vector < int > v[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;

int ans[ MAXN ] ;

vector < pair < int , int > > ask[ MAXN ] ;
vector < int > temp[ MAXN ] ;
bool bad[ MAXN ] ;

int jump[ MAXN ][ LOG ] ;

vector < int > b[ MAXN ] ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int time_val ;
void init ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    st[ vertex ] = ++ time_val ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        init ( v[ vertex ][ i ] ) ;
    }
    en[ vertex ] = time_val ;
}

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ; 
}

void CalcZeroJumps ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        CalcZeroJumps ( v[ vertex ][ i ] ) ;
        if ( jump[ v[ vertex ][ i ] ][ 0 ] == vertex ) { continue ; }
        if ( jump[ v[ vertex ][ i ] ][ 0 ] == 0 ) { continue ; }
        if ( jump[ vertex ][ 0 ] == 0 ) {
            jump[ vertex ][ 0 ] = jump[ v[ vertex ][ i ] ][ 0 ] ;
        }
        if ( lvl[ jump[ vertex ][ 0 ] ] > lvl[ jump[ v[ vertex ][ i ] ][ 0 ] ] ) {
            jump[ vertex ][ 0 ] = jump[ v[ vertex ][ i ] ][ 0 ] ;
        }
    }
}

void UpdJumps ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        jump[ vertex ][ i ] = jump[ jump[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        UpdJumps ( v[ vertex ][ i ] ) ;
    }
}

int get_lst ( int x , int barrier , int id ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( jump[ x ][ i ] > 0 && lvl[ jump[ x ][ i ] ] > lvl[ barrier ] ) {
            ans[ id ] += (1<<i) ;
            x = jump[ x ][ i ] ;
        }
    }
    int ret = x ;
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( jump[ x ][ i ] > 0 && lvl[ jump[ x ][ i ] ] >= lvl[ barrier ] ) {
            ans[ id ] += (1<<i) ;
            x = jump[ x ][ i ] ;
        }
    }
    if ( x != barrier ) { ++ ans[ id ] ; }
    if ( x != barrier && ( jump[ x ][ 0 ] == 0 || lvl[ jump[ x ][ 0 ] ] > lvl[ barrier ] ) ) { bad[ id ] = true ; }
    return ret ;
}



class Tree {
public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        tr[ where ] += val ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    int aux = ask[ vertex ].size ( ) ;
    for ( int i = 0 ; i < aux ; ++ i ) {
        temp[ vertex ].push_back ( w.query ( 1 , 1 , n , st[ ask[ vertex ][ i ].first ] , en[ ask[ vertex ][ i ].first ] ) ) ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        dfs ( v[ vertex ][ i ] ) ;
    }
    int hh = b[ vertex ].size ( ) ;
    for ( int i = 0 ; i < hh ; ++ i ) {
        w.update ( 1 , 1 , n , st[ b[ vertex ][ i ] ] , 1 ) ;
    }
    for ( int i = 0 ; i < aux ; ++ i ) {
        int sr = w.query ( 1 , 1 , n , st[ ask[ vertex ][ i ].first ] , en[ ask[ vertex ][ i ].first ] ) ;
        if ( sr != temp[ vertex ][ i ] ) {
            -- ans[ ask[ vertex ][ i ].second ] ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 2 , x ; i <= n ; ++ i ) {
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
    init ( 1 ) ;
    int m ;
    scanf ( "%d" , &m ) ;
    while ( m -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        b[ x ].push_back ( y ) ;
        b[ y ].push_back ( x ) ;
        if ( lvl[ x ] < lvl[ y ] ) { swap ( x , y ) ; }
        int aux = get_LCA ( x , y ) ;
        if ( aux == y ) {
            if ( jump[ x ][ 0 ] == 0 ) {
                jump[ x ][ 0 ] = y ;
            }
            if ( lvl[ jump[ x ][ 0 ] ] > lvl[ y ] ) {
                jump[ x ][ 0 ] = y ;
            }
        }
        else {
            if ( jump[ x ][ 0 ] == 0 ) {
                jump[ x ][ 0 ] = aux ;
            }
            if ( lvl[ jump[ x ][ 0 ] ] > lvl[ aux ] ) {
                jump[ x ][ 0 ] = aux ;
            }
            if ( jump[ y ][ 0 ] == 0 ) {
                jump[ y ][ 0 ] = aux ;
            }
            if ( lvl[ jump[ y ][ 0 ] ] > lvl[ aux ] ) {
                jump[ y ][ 0 ] = aux ;
            }
        }
    }
    CalcZeroJumps ( 1 ) ;
    UpdJumps ( 1 ) ;
}

void solve ( ) {
    int q ;
    scanf ( "%d" , &q ) ;
    for ( int i = 1 , x , y ; i <= q ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        int aux = get_LCA ( x , y ) ;
        if ( lvl[ x ] < lvl[ y ] ) { swap ( x , y ) ; }
        if ( aux == y ) {
            get_lst ( x , y , i ) ;
        }
        else {
            int p1 = get_lst ( x , aux , i ) ;
            int p2 = get_lst ( y , aux , i ) ;
            ask[ p1 ].push_back ( { p2 , i } ) ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    dfs ( 1 ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( bad[ i ] == true ) { ans[ i ] = -1 ; }
        printf ( "%d\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}