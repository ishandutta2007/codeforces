#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAXLEN 3000007
#define MOD 1000000007

int n , q ;
string sss[ 23 ] ;
string ttt ;
int lim = 21 ;

int pw[ MAXN ] ;
int PI[ MAXLEN ] ;

int pref[ MAXN ][ 27 ] ;

int coef[ 27 ] ;

void input ( ) {
    cin >> n >> q ;
    cin >> sss[ 0 ] ;
    cin >> ttt ;
    lim = min ( lim , n ) ;
    for ( int i = 1 ; i <= lim ; ++ i ) {
        sss[ i ] = sss[ i - 1 ] + ttt[ i - 1 ] + sss[ i - 1 ] ;
        if ( sss[ i ].size ( ) >= 1000000 ) { lim = i ; break ; }
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) ;
        if ( pw[ i ] >= MOD ) { pw[ i ] -= MOD ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            pref[ i ][ j ] = pref[ i - 1 ][ j ] * 2 ;
            if ( pref[ i ][ j ] >= MOD ) { pref[ i ][ j ] -= MOD ; }
        }
        int val = ttt[ i - 1 ] - 'a' ;
        ++ pref[ i ][ val ] ;
        if ( pref[ i ][ val ] >= MOD ) { pref[ i ][ val ] -= MOD ; }
    }
}


 
int BASE[ 2 ] = { 231 , 3257 } ;
int modulos[ 2 ] = { 998244355LL , 1000000007LL } ;

struct hsh {
    int h[ 2 ] ;
    hsh ( ) { h[ 0 ] = h[ 1 ] = 0 ; }
    void advance ( int x ) {
        for ( auto i : { 0 , 1 } ) {
            h[ i ] = ( 1LL * h[ i ] * BASE[ i ] + x ) % modulos[ i ] ;
        }        
    }
    void add_to ( int x , int coef0 , int coef1 ) {
        h[ 0 ] += ( 1LL * x * coef0 ) % modulos[ 0 ] ;
        if ( h[ 0 ] >= modulos[ 0 ] ) { h[ 0 ] -= modulos[ 0 ] ; }
        h[ 1 ] += ( 1LL * x * coef1 ) % modulos[ 1 ] ;
        if ( h[ 1 ] >= modulos[ 1 ] ) { h[ 1 ] -= modulos[ 1 ] ; }
    }
};

bool l_ok[ MAXLEN ] ;
bool r_ok[ MAXLEN ] ;

void calc_coef ( string &a , int id ) {
    for ( int i = 0 ; i < 26 ; ++ i ) {
        coef[ i ] = 0 ;
    }
    int sz = a.size ( ) ;
    for ( int i = 0 ; i <= sz ; ++ i ) {
        l_ok[ i ] = r_ok[ i ] = false ;
    }
    l_ok[ 0 ] = true ; r_ok[ sz - 1 ] = true ;
    int help[ 2 ] = { 1 , 1 } ;
    hsh aux , pat ;
    aux = pat = hsh ( ) ;
    int cmp_sz = sss[ id ].size ( ) ;
    for ( int i = 1 ; i < sz ; ++ i ) {
        aux.advance ( a[ i - 1 ] - 'a' ) ;
        pat.add_to ( sss[ id ][ cmp_sz - i ] - 'a' , help[ 0 ] , help[ 1 ] ) ;
        
        if ( aux.h[ 0 ] == pat.h[ 0 ] && aux.h[ 1 ] == pat.h[ 1 ] ) {
            l_ok[ i ] = true ;
        }

        help[ 0 ] = ( 1LL * BASE[ 0 ] * help[ 0 ] ) % modulos[ 0 ] ;
        help[ 1 ] = ( 1LL * BASE[ 1 ] * help[ 1 ] ) % modulos[ 1 ] ;
    }
    aux = pat = hsh ( ) ;
    help[ 0 ] = 1 ; help[ 1 ] = 1 ;

    for ( int i = sz - 2 ; i >= 0 ; -- i ) {
        aux.add_to ( a[ i + 1 ] - 'a' , help[ 0 ] , help[ 1 ] ) ;
        pat.advance ( sss[ id ][ ( sz - i - 2 ) ] - 'a' ) ;

        if ( aux.h[ 0 ] == pat.h[ 0 ] && aux.h[ 1 ] == pat.h[ 1 ] ) {
            r_ok[ i ] = true ;
        }

        help[ 0 ] = ( 1LL * BASE[ 0 ] * help[ 0 ] ) % modulos[ 0 ] ;
        help[ 1 ] = ( 1LL * BASE[ 1 ] * help[ 1 ] ) % modulos[ 1 ] ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( l_ok[ i ] == true && r_ok[ i ] == true ) {
            ++ coef[ ( a[ i ] - 'a' ) ] ;
        }
    }
}

long long act[ 27 ] ;

void solve ( ) {
    while ( q -- ) {
        int pos ;
        string a ;
        cin >> pos >> a ;
        if ( pos <= lim && sss[ pos ].size ( ) < a.size ( ) ) {
            cout << "0\n" ;
            continue ;
        }
        int id = 0 ;
        for ( int i = 0 ; i <= lim ; ++ i ) {
            id = i ;
            if ( sss[ i ].size ( ) >= a.size ( ) ) { break ; }
        }
        int sz = a.size ( ) ;
        PI[ 0 ] = PI[ 1 ] = 0 ;
        int len = 0 ;
        for ( int i = 2 ; i <= sz ; ++ i ) {
            while ( len > 0 && a[ i - 1 ] != a[ len ] ) {
                len = PI[ len ] ;
            }
            if ( a[ i - 1 ] == a[ len ] ) { ++ len ; }
            PI[ i ] = len ;
        }
        len = 0 ;
        long long ans = 0 ;
        for ( auto c : sss[ id ] ) {
            while ( len > 0 && c != a[ len ] ) {
                len = PI[ len ] ;
            }
            if ( c == a[ len ] ) { ++ len ; }
            if ( len == sz ) { ++ ans ; }
        }
        ans = ( ans * pw[ pos - id ] ) % MOD ;
        calc_coef ( a , id ) ;
        for ( int j = 0 ; j < 26 ; ++ j ) {
            act[ j ] = pref[ pos ][ j ] ;
        }
        for ( int i = 1 ; i <= id ; ++ i ) {
            int ch = ( ttt[ i - 1 ] - 'a' ) ;
            act[ ch ] = ( act[ ch ] + MOD - pw[ pos - i ] ) % MOD ;
        }
        for ( int j = 0 ; j < 26 ; ++ j ) {
            ans += ( 1LL * act[ j ] * coef[ j ] ) % MOD ;
            if ( ans >= MOD ) { ans -= MOD ; }
        }
        cout << ans << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}