#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
struct tuhla {
    int a , b , c , d ;
};

tuhla h[ MAXN ] ;
int dist[ MAXN ] ;
int prv[ MAXN ] ;

bool init[ MAXN ] ;

int maxvalX , maxvalY ;

vector < int > nw ;


struct outer_tree {
    int IL , IR ;
    outer_tree *pl , *pr ;
    vector < pair < int , int > > v ;
    outer_tree ( ) { IL = IR = 0 ; v.clear ( ) ; pl = pr = NULL ; }
    outer_tree ( int _IL , int _IR ) {
        IL = _IL ; IR = _IR ;
        pl = pr = NULL ;
        v.clear ( ) ;
    }
};

outer_tree *root ;



void update_outer ( outer_tree *w , int x , int y , int id ) {
    if ( w == NULL ) { return ; }
    if ( w->IR < x || x < w->IL ) { return ; }
    w->v.push_back ( { y , id } ) ;
    if ( w->IL == w->IR ) { return ; }
    int mid = ( w->IL + w->IR ) / 2 ;
    if ( x <= mid ) {
        if ( w->pl == NULL ) { w->pl = new outer_tree ( w->IL , mid ) ; }
        update_outer ( w->pl , x , y , id ) ;
    }
    else {
        if ( w->pr == NULL ) { w->pr = new outer_tree ( mid + 1 , w->IR ) ; }
        update_outer ( w->pr , x , y , id ) ;
    }
}

void sort_all ( outer_tree *w ) {
    if ( w == NULL ) { return ; }
    sort ( w->v.begin ( ) , w->v.end ( ) ) ;
    if ( w->pl != NULL ) { sort_all ( w->pl ) ; }
    if ( w->pr != NULL ) { sort_all ( w->pr ) ; }
}


void query_outer ( outer_tree *w , int x , int y ) {
    if ( w == NULL ) { return ; }
    if ( w->IR < x ) { return ; }
    if ( x <= w->IL ) {
        while ( w->v.empty ( ) == false ) {
            if ( w->v.back( ).first < y ) { break ; }
            if ( dist[ w->v.back( ).second ] == -1 ) {
                nw.push_back ( w->v.back( ).second ) ;
            }
            w->v.pop_back ( ) ;
        }
        return ;
    }
    if ( w->pl != NULL ) { query_outer ( w->pl , x , y ) ; }
    if ( w->pr != NULL ) { query_outer ( w->pr , x , y ) ; }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    set < int > c1 , c2 ;
    map < int , int > w1 , w2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d%d" , &h[ i ].a , &h[ i ].b , &h[ i ].c , &h[ i ].d ) ;
        if ( h[ i ].a == 0 && h[ i ].b == 0 ) { init[ i ] = true ; }
        c1.insert ( h[ i ].a ) ; c1.insert ( h[ i ].c ) ;
        c2.insert ( h[ i ].b ) ; c2.insert ( h[ i ].d ) ;
    }
    for ( auto it = c1.begin ( ) ; it != c1.end ( ) ; ++ it ) {
        w1[ (*it) ] = ++ maxvalX ;
    }
    for ( auto it = c2.begin ( ) ; it != c2.end ( ) ; ++ it ) {
        w2[ (*it) ] = ++ maxvalY ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        h[ i ].a = w1[ h[ i ].a ] ; h[ i ].c = w1[ h[ i ].c ] ;
        h[ i ].b = w2[ h[ i ].b ] ; h[ i ].d = w2[ h[ i ].d ] ;
    }
}

void solve ( ) {
    root = new outer_tree ( 1 , maxvalX ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        update_outer ( root , h[ i ].c , h[ i ].d , i ) ;
    }
    sort_all ( root ) ;
    queue < int > q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dist[ i ] = prv[ i ] = -1 ;
    }
    dist[ n ] = 0 ;
    q.push ( n ) ;
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        nw.clear ( ) ;
        query_outer ( root , h[ x ].a , h[ x ].b ) ;
        for ( auto y : nw ) {
            dist[ y ] = dist[ x ] + 1 ;
            prv[ y ] = x ;
            q.push ( y ) ;
        }
    }
    int mn = MAXN ;
    int id = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( init[ i ] == true && dist[ i ] != -1 ) {
            if ( mn > dist[ i ] ) {
                mn = dist[ i ] ;
                id = i ;
            }
        }
    }
    if ( mn == MAXN ) {
        printf ( "-1\n" ) ;
        return ;
    }
    printf ( "%d\n" , mn + 1 ) ;
    while ( id != n ) {
        printf ( "%d " , id ) ;
        id = prv[ id ] ;
    }
    printf ( "%d\n" , n ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}