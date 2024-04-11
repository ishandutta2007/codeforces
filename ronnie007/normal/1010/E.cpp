#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 100007
#define inf 1000000007


int xmax , ymax , zmax ;
int n , m , k ;

pair < int , int > X , Y , Z ;
vector < pair < int , int > > add[ MAXN ] ;

int ans[ MAXN ] ;

struct query {
    int xx1 , yy1 , xx2 , yy2 ;
    int coef ;
    int id ;
    query ( ) { xx1 = yy1 = xx2 = yy2 = coef = id = 0 ; }
    query ( int _xx1 , int _yy1 , int _xx2 , int _yy2 , int _coef , int _id ) {
        xx1 = _xx1 ;
        yy1 = _yy1 ;
        xx2 = _xx2 ;
        yy2 = _yy2 ;
        coef = _coef ;
        id = _id ;
    }
};
vector < query > ask[ MAXN ] ;


template < class T > struct inner_tree {
    T val ;
    inner_tree < T > *pl , *pr ;
    inner_tree ( ) {
        this->val = 0 ;
        this->pl = this->pr = NULL ;
    }
    void recalc ( ) {
        this->val = 0 ;
        if ( this->pl != NULL ) { this->val += this->pl->val ; }
        if ( this->pr != NULL ) { this->val += this->pr->val ; }
    }
    void add ( int IL , int IR , int id , T v ) {
        if ( id < IL || IR < id ) { return ; }
        if ( IL == IR ) { this->val += v ; return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( id <= mid ) {
            if ( this->pl == NULL ) {
                this->pl = new inner_tree ( ) ;
            }
            this->pl->add ( IL , mid , id , v ) ;
        }
        else {
            if ( this->pr == NULL ) {
                this->pr = new inner_tree ( ) ;
            }
            this->pr->add ( mid + 1 , IR , id , v ) ;
        }
        this->recalc ( ) ;
    }
    T query ( int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return this->val ;
        }
        int mid = ( IL + IR ) / 2 ;
        T ret = 0 ;
        if ( this->pl != NULL ) { ret += this->pl->query ( IL , mid , CURL , CURR ) ; }
        if ( this->pr != NULL ) { ret += this->pr->query ( mid + 1 , IR , CURL , CURR ) ; }
        return ret ;
    }
};

template < class T > struct BIT {
    inner_tree <T> tr[ MAXN ] ;
    BIT ( ) {
        int i ;
        for ( i = 0 ; i < MAXN ; i ++ ) {
            tr[ i ] = inner_tree<T> ( ) ;
        }
    }
    void add_val ( int x , int y , T v ) {
        for ( x ++ ; x < MAXN ; x += (x&(-x)) ) { tr[ x ].add ( 1 , zmax , y , v ) ; }
    }
    T query_line ( int x , int st , int en ) {
        T ret = 0 ;
        for ( ; x > 0 ; x -= (x&(-x)) ) { ret += tr[ x ].query ( 1 , zmax , st , en ) ; }
        return ret ;
    }
    T query_rectangle ( int xx1 , int yy1 , int xx2 , int yy2 ) {
        return ( query_line ( xx2 + 1 , yy1 , yy2 ) - query_line ( xx1 , yy1 , yy2 ) ) ;
    }
};

BIT <int> w ;

void calc ( ) {
    int i , j ;
    for ( i = 0 ; i <= xmax ; i ++ ) {
        int sz = add[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            w.add_val ( add[ i ][ j ].first , add[ i ][ j ].second , 1 ) ;
        }
        sz = ask[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            ans[ ask[ i ][ j ].id ] += ask[ i ][ j ].coef * w.query_rectangle( ask[ i ][ j ].xx1 , ask[ i ][ j ].yy1 , ask[ i ][ j ].xx2 , ask[ i ][ j ].yy2 ) ;
        }
    }
}



void recalc_bounds ( pair < int , int > &aux , int val ) {
    aux.first = min ( aux.first , val ) ;
    aux.second = max ( aux.second , val ) ;
}
bool inside ( pair < int , int > aux , int val ) {
    if ( val < aux.first || aux.second < val ) { return false ; }
    return true ;
}

void input ( ) {
    scanf ( "%d%d%d" , &xmax , &ymax , &zmax ) ;
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    X = Y = Z = { inf , -inf } ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d"  ,&x , &y , &z ) ;
        recalc_bounds ( X , x ) ;
        recalc_bounds ( Y , y ) ;
        recalc_bounds ( Z , z ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( inside ( X , x ) == true && inside ( Y , y ) == true && inside ( Z , z ) == true ) {
            printf ( "INCORRECT\n" ) ;
            return ;
        }
        add[ x ].push_back ( make_pair ( y , z ) ) ;
    }
    printf ( "CORRECT\n" ) ;
    for ( i = 1 ; i <= k ; i ++ ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( inside ( X , x ) == true && inside ( Y , y ) == true && inside ( Z , z ) == true ) {
            ans[ i ] = -1 ;
        }
        else {
            pair < int , int > XX = { min ( X.first , x ) , max ( X.second , x ) } ;
            pair < int , int > YY = { min ( Y.first , y ) , max ( Y.second , y ) } ;
            pair < int , int > ZZ = { min ( Z.first , z ) , max ( Z.second , z ) } ;
            ask[ XX.first - 1 ].push_back ( query ( YY.first , ZZ.first , YY.second , ZZ.second , -1 , i ) ) ;
            ask[ XX.second ].push_back ( query ( YY.first , ZZ.first , YY.second , ZZ.second , 1 , i ) ) ;
        }
    }
    calc ( ) ;
    for ( i = 1 ; i <= k ; i ++ ) {
        if ( ans[ i ] == -1 ) { printf ( "OPEN\n" ) ; }
        else if ( ans[ i ] == 0 ) { printf ( "UNKNOWN\n" ) ; }
        else { printf ( "CLOSED\n" ) ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}