#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
struct edge {
    int to , len , id ;
    edge ( ) { to = len = id = 0 ; }
    edge ( int _to , int _len , int _id ) {
        to = _to ;
        len = _len ;
        id = _id ;
    }
};

vector < edge > v[ MAXN ] ;

int lst[ MAXN ] ;
int lvl[ MAXN ] ;
bool used_v[ MAXN ] ;
bool used_e[ MAXN ] ;

pair < int , int > edge_list[ MAXN ] ;
int edge_len[ MAXN ] ;
vector < int > cycle ;
int cycle_size ;
bool ban[ MAXN ] ;

long long pref[ MAXN ] ;
long long suff[ MAXN ] ;

long long pref_path[ MAXN ] ;
long long suff_path[ MAXN ] ;

long long dist[ MAXN ] ;
long long max_diam ;


void init ( int vertex ) {
    used_v[ vertex ] = true ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].to ;
        int edge_id = v[ vertex ][ i ].id ;
        if ( used_v[ h ] == false ) {
            used_e[ edge_id ] = true ;
            lst[ h ] = edge_id ;
            lvl[ h ] = lvl[ vertex ] + 1 ;
            init ( h ) ;
        }
    }
}
int other ( int x , int edge_id ) {
    if( x == edge_list[ edge_id ].first ) {
        return edge_list[ edge_id ].second ;
    }
    else {
        return edge_list[ edge_id ].first ;
    }
}
void upd ( int &x ) {
    ban[ lst[ x ] ] = true ;
    x = other ( x , lst[ x ] ) ;
}

void mark ( int x , int y ) {
    int aux1 = x , aux2 = y ;
    while ( lvl[ x ] > lvl[ y ] ) {
        upd ( x ) ;
    }
    while ( lvl[ y ] > lvl[ x ] ) {
        upd ( y ) ;
    }
    while ( x != y ) {
        upd ( x ) ;
        upd ( y ) ;
    }
    int lca = x ;
    while ( aux1 != lca ) {
        cycle.push_back ( lst[ aux1 ] ) ;
        aux1 = other ( aux1 , lst[ aux1 ] ) ;
    }
    vector < int > h ;
    h.clear ( ) ;
    while ( aux2 != lca ) {
        h.push_back ( lst[ aux2 ] ) ;
        aux2 = other ( aux2 , lst[ aux2 ] ) ;
    }
    int sz = h.size ( ) ;
    for ( int i = sz - 1 ; i >= 0 ; -- i ) {
        cycle.push_back ( h[ i ] ) ;
    }
}

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    long long mx1 ;
    int rem ;
    mx1 = rem = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].to ;
        int c = v[ vertex ][ i ].len ;
        int edge_id = v[ vertex ][ i ].id ;
        if ( ban[ edge_id ] == true || h == prv ) { continue ; }
        dfs ( h , vertex ) ;
        dist[ vertex ] = max ( dist[ vertex ] , dist[ h ] + c ) ;
        if ( mx1 < dist[ h ] + c ) {
            mx1 = dist[ h ] + c ;
            rem = h ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].to ;
        int c = v[ vertex ][ i ].len ;
        int edge_id = v[ vertex ][ i ].id ;
        if ( ban[ edge_id ] == true || h == prv ) { continue ; }
        if ( h != rem ) {
            max_diam = max ( max_diam , mx1 + dist[ h ] + c ) ;
        }
    }
    max_diam = max ( max_diam , dist[ vertex ] ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        edge_list[ i ] = { x , y } ;
        edge_len[ i ] = z ;
        v[ x ].push_back ( edge ( y , z , i ) ) ;
        v[ y ].push_back ( edge ( x , z , i ) ) ;
    }
}

void solve ( ) {
    init ( 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used_e[ i ] == false ) {
            ban[ i ] = true ;
            cycle.push_back ( i ) ;
            mark ( edge_list[ i ].first , edge_list[ i ].second ) ;
        }
    }
    cycle_size = cycle.size ( ) ;
    if ( edge_list[ cycle[ 0 ] ].second != edge_list[ cycle[ 1 ] ].first
         && edge_list[ cycle[ 0 ] ].second != edge_list[ cycle[ 1 ] ].second ) {
            swap ( edge_list[ cycle[ 0 ] ].first , edge_list[ cycle[ 0 ] ].second ) ;        
    }
    for ( int i = 1 ; i < cycle_size ; ++ i ) {
        if ( edge_list[ cycle[ i ] ].first != edge_list[ cycle[ i - 1 ] ].second ) {
            swap ( edge_list[ cycle[ i ] ].first , edge_list[ cycle[ i ] ].second ) ;
        }
    }
    for ( int i = 0 ; i < cycle_size ; ++ i ) {
        dfs ( edge_list[ cycle[ i ] ].first , -1 ) ;
    }
    long long mx = 0 ;
    long long sm = 0 ;
    
    for ( int i = 0 ; i < cycle_size ; ++ i ) {
        pref_path[ i ] = sm + dist[ edge_list[ cycle[ i ] ].first ] ;
        if ( i > 0 ) {
            pref_path[ i ] = max ( pref_path[ i ] , pref_path[ i - 1 ] ) ;
        }
        else { pref_path[ i ] = 0 ; }        
        sm += edge_len[ cycle[ i ] ] ;
    }
    sm = 0 ;
    for ( int i = cycle_size - 1 ; i >= 0 ; -- i ) {
        suff_path[ i ] = sm + dist[ edge_list[ cycle[ i ] ].second ] ;
        if ( i < cycle_size - 1 ) {
            suff_path[ i ] = max ( suff_path[ i ] , suff_path[ i + 1 ] ) ;
        }
        else { suff_path[ i ] = 0 ; }
        sm += edge_len[ cycle[ i ] ] ;
    }

    mx = 0 ;
    for ( int i = 0 ; i < cycle_size ; ++ i ) {
        pref[ i ] = dist[ edge_list[ cycle[ i ] ].first ] + mx ;
        if ( i > 0 ) {
            pref[ i ] = max ( pref[ i ] , pref[ i - 1 ] ) ;
        }
        mx = max ( mx , dist[ edge_list[ cycle[ i ] ].first ] ) ;
        mx += edge_len[ cycle[ i ] ] ;
    }
    mx = 0 ;
    for ( int i = cycle_size - 1 ; i >= 0 ; -- i ) {
        suff[ i ] = dist[ edge_list[ cycle[ i ] ].second ] + mx ;
        if ( i < cycle_size - 1 ) {
            suff[ i ] = max ( suff[ i ] , suff[ i + 1 ] ) ;
        }
        mx = max ( mx , dist[ edge_list[ cycle[ i ] ].second ] ) ;
        mx += edge_len[ cycle[ i ] ] ;
    }
    long long ans = -1 ;
    for ( int i = 0 ; i < cycle_size ; ++ i ) {
        long long aux = max_diam ;
        aux = max ( aux , pref[ i ] ) ;
        aux = max ( aux , suff[ i ] ) ;
        aux = max ( aux , pref_path[ i ] + suff_path[ i ] ) ;
        if ( ans < 0 || ans > aux ) { ans = aux ; }
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}