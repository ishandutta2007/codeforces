#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define LOG 19

int n , q ;
vector < int > v[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;
int tpsz ;

set < pair < int , int > > s ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int cnt[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;

    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void merge ( int where ) {
        cnt[ where ] = 0 ;
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
        if ( tr[ where ] == tr[ 2 * where ] ) {
            cnt[ where ] += cnt[ 2 * where ] ;
        }
        if ( tr[ where ] == tr[ 2 * where + 1 ] ) {
            cnt[ where ] += cnt[ 2 * where + 1 ] ;
        }
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        cnt[ where ] = ( IR - IL + 1 ) ;
        lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        merge ( where ) ;
    }
    int query ( ) {
        if ( tr[ 1 ] > 0 ) { return 0 ; }
        return cnt[ 1 ] ;
    }
};
Tree w ;

void dfs ( int vertex , int prv ) {
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    st[ vertex ] = ++ tpsz ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        LCA[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    en[ vertex ] = tpsz ;
}
bool parent ( int x , int y ) {
    if ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) { return true ; }
    return false ;
}

int jump ( int x , int target ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - (1<<i) >= target ) {
            x = LCA[ x ][ i ] ;
        }
    }
    return x ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( x > y ) { swap ( x , y ) ; }
        int coef = 0 ; 
        if ( s.find ( { x , y } ) == s.end ( ) ) {
            coef = 1 ;
            s.insert ( { x , y } ) ;
        }
        else {
            coef = -1 ;
            s.erase ( { x , y } ) ;
        }
        if ( parent ( x , y ) == false && parent ( y , x ) == false ) {
            w.update ( 1 , 1 , n , 1 , n , coef ) ;
            w.update ( 1 , 1 , n , st[ x ] , en[ x ] , -coef ) ;
            w.update ( 1 , 1 , n , st[ y ] , en[ y ] , -coef ) ;
        }
        else {
            if ( parent ( x , y ) == true ) {
                int aux = jump ( y , lvl[ x ] + 1 ) ;
                w.update ( 1 , 1 , n , st[ aux ] , en[ aux ] , coef ) ;
                w.update ( 1 , 1 , n , st[ y ] , en[ y ] , -coef ) ;
            }
            else {
                int aux = jump ( x , lvl[ y ] + 1 ) ;
                w.update ( 1 , 1 , n , st[ aux ] , en[ aux ] , coef ) ;
                w.update ( 1 , 1 , n , st[ x ] , en[ x ] , -coef ) ;
            }
        }
        printf ( "%d\n" , w.query ( ) ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}