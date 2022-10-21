#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , mod ;
bool fl[ MAXN ] ;

int cnt[ MAXN ] ;
int dp[ MAXN ] ;
int nxt[ MAXN ] ;

vector < int > divs ;
vector < int > v[ MAXN ] ;

int tpsz ;
int ans[ MAXN ] ;
int phi[ MAXN ] ;

long long fastpow ( long long x , long long pw , long long md ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw % 2 ) == 0 ) {
            x = ( x * x ) % md ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % md ;
            -- pw ;
        }
    }
    return ret ;
}

void proc_divs ( ) {
    int aux = mod ;
    for ( int i = 2 ; i * i <= aux ; ++ i ) {
        if ( ( aux % i ) == 0 ) {
            divs.push_back ( i ) ;
            while ( ( aux % i ) == 0 ) {
                aux /= i ;
            }
        }
    }
    if ( aux > 1 ) {
        divs.push_back ( aux ) ;
    }
}


void init_phi ( ) {
    for ( int i = 1 ; i <= mod ; ++ i ) {
        phi[ i ] = i ;
    }
    for ( int i = 2 ; i <= mod ; ++ i ) {
        if ( phi[ i ] != i ) { continue ; }
        for ( int j = i ; j <= mod ; j += i ) {
            phi[ j ] = ( phi[ j ] / i ) * ( i - 1 ) ;
        }
    }
}

int calc ( int st , int en ) {
    int coef1 = __gcd ( mod , st ) ;
    int coef2 = __gcd ( mod , en ) ;
    int md1 = ( mod / coef1 ) ;
    int md2 = ( mod / coef2 ) ;
    if ( coef1 == coef2 ) {
        return ( 1LL * fastpow ( st / coef1 , phi[ md2 ] - 1 , md2 ) * ( en / coef2 ) ) % mod ;
    }
    else {
        return ( 1LL * fastpow ( st / coef1 , phi[ md2 ] - 1 , md2 ) * ( en / coef1 ) ) % mod ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &mod ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        fl[ x ] = true ;
    }
}

void solve ( ) {
    proc_divs ( ) ;
    init_phi ( ) ;
    for ( int i = 1 ; i < mod ; ++ i ) {
        if ( fl[ i ] == true ) { continue ; }
        ++ cnt[ __gcd ( i , mod ) ] ;
        v[ __gcd ( i , mod ) ].push_back ( i ) ;
    }
    int sz = divs.size ( ) ;
    for ( int i = mod - 1 ; i >= 1 ; -- i ) {
        if ( ( mod % i ) != 0 ) { continue ; }
        dp[ i ] = cnt[ i ] ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            if ( i * divs[ j ] <= mod ) {
                if ( dp[ i ] < cnt[ i ] + dp[ i * divs[ j ] ] ) {
                    dp[ i ] = cnt[ i ] + dp[ i * divs[ j ] ] ;
                    nxt[ i ] = divs[ j ] ;
                }
            }
        }
    }
    int hh = 1 ;
    int lst = 1 ;
    while ( hh < mod ) {
        for ( int i = 0 ; i < cnt[ hh ] ; ++ i ) {
            ans[ tpsz ++ ] = calc ( lst , v[ hh ][ i ] ) ;
            lst = v[ hh ][ i ] ;
        }
        if ( nxt[ hh ] == 0 ) { break ; }
        hh *= nxt[ hh ] ;
    }
    if ( fl[ 0 ] == false ) {
        ans[ tpsz ++ ] = 0 ;
    }
    printf ( "%d\n" , tpsz ) ;
    for ( int i = 0 ; i < tpsz ; ++ i ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}