#include<bits/stdc++.h>
using namespace std ;

#define MAXN 6007

int n ;
string a[ MAXN ] ;
string b[ MAXN ] ;

int PI[ MAXN ] ;

string from , to ;

vector < pair < int , int > > pref_add ;
vector < pair < int , int > > suff_add ;

void proc ( string p1 , string p2 ) {
    int sz = p1.size ( ) ;
    int fst = -1 ;
    int lst = -1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( p1[ i ] != p2[ i ] ) {
            lst = i ;
            if ( fst == -1 ) { fst = i ; }
        }
    }
    for ( int i = fst ; i <= lst ; ++ i ) {
        from += p1[ i ] ;
        to += p2[ i ] ;
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    int id = 1 ;
    while ( id <= n && a[ id ] == b[ id ] ) { ++ id ; }
    if ( id > n ) {
        cout << "YES\na\na" ;
        return ;
    }
    proc ( a[ id ] , b[ id ] ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != b[ i ] ) {
            int sz = a[ i ].size ( ) ;
            int fst = -1 ;
            int lst = -1 ;
            for ( int j = 0 ; j < sz ; ++ j ) {
                if ( a[ i ][ j ] != b[ i ][ j ] ) {
                    lst = j ;
                    if ( fst == -1 ) { fst = j ; }
                }
            }
            if ( lst - fst + 1 != from.size ( ) ) {
                cout << "NO\n" ;
                return ;
            }
            sz = from.size ( ) ;
            for ( int j = 0 ; j < sz ; ++ j ) {
                if ( a[ i ][ fst + j ] != from[ j ] || b[ i ][ fst + j ] != to[ j ] ) {
                    cout << "NO\n" ;
                    return ;
                }
            }
            pref_add.push_back ( { i , fst } ) ;
            suff_add.push_back ( { i , lst } ) ;
        }
    }
    string rv_pref , pref , suff ;
    rv_pref.clear ( ) ;
    pref.clear ( ) ;
    suff.clear ( ) ;
    int aux_sz = pref_add.size ( ) ;
    for ( int i = 1 ; i <= 3000 ; ++ i ) {
        int j ;
        for ( j = 0 ; j < aux_sz ; ++ j ) {
            if ( pref_add[ j ].second - i < 0 ) { break ; }
        }
        if ( j < aux_sz ) { break ; }
        char sr = a[ pref_add[ 0 ].first ][ pref_add[ 0 ].second - i ] ;
        for ( j = 0 ; j < aux_sz ; ++ j ) {
            if ( a[ pref_add[ j ].first ][ pref_add[ j ].second - i ] != sr ) { break ; }
            if ( b[ pref_add[ j ].first ][ pref_add[ j ].second - i ] != sr ) { break ; }
        }
        if ( j < aux_sz ) { break ; }
        rv_pref += sr ; 
    }

    aux_sz = rv_pref.size ( ) ;
    for ( int i = aux_sz - 1 ; i >= 0 ; -- i ) {
        pref += rv_pref[ i ] ;
    }
    aux_sz = suff_add.size ( ) ;
    for ( int i = 1 ; i <= 3000 ; ++ i ) {
        int j ;
        for ( j = 0 ; j < aux_sz ; ++ j ) {
            if ( suff_add[ j ].second + i >= a[ suff_add[ j ].first ].size ( ) ) { break ; }
        }
        if ( j < aux_sz ) { break ; }
        char sr = a[ suff_add[ 0 ].first ][ suff_add[ 0 ].second + i ] ;
        for ( j = 0 ; j < aux_sz ; ++ j ) {
            if ( a[ suff_add[ j ].first ][ suff_add[ j ].second + i ] != sr ) { break ; }
            if ( b[ suff_add[ j ].first ][ suff_add[ j ].second + i ] != sr ) { break ; }
        }
        if ( j < aux_sz ) { break ; }
        suff += sr ;
    }
    from = pref + from + suff ;
    to = pref + to + suff ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int lst = -1 ;
        int len = a[ i ].size ( ) ;
        for ( int j = 0 ; j < len ; ++ j ) {
            if ( a[ i ][ j ] != b[ i ][ j ] ) {
                lst = j ;
            }
        }
        lst += suff.size ( ) ;
        string hh = from + "#" + a[ i ] ;
        int sr = from.size ( ) ;
        int sz = hh.size ( ) ;
        PI[ 0 ] = PI[ 1 ] = 0 ;
        int l = 0 ;
        for ( int j = 2 ; j <= sz ; ++ j ) {
            while ( l > 0 && hh[ j - 1 ] != hh[ l ] ) {
                l = PI[ l ] ;
            }
            if ( hh[ j - 1 ] == hh[ l ] ) { ++ l ; }
            PI[ j ] = l ;
            if ( l == sr ) {
                if ( lst == -1 || j - sr - 2 != lst ) {
                    cout << "NO\n" ;
                    return ;
                }
                break ;
            }
        }
    }
    cout << "YES\n" ;
    cout << from << "\n" << to << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}