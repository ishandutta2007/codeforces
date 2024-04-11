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

#define MAXN 1100007
#define PI acos ( -1 )


int n , x ;
int vals[ MAXN ] ;
int pref[ MAXN ] ;

vector < int64_t > v1 , v2 , v3 ;

class complex {
public :
    double x , y ;
    complex ( ) { x = y = 0 ; }
    complex ( double _x , double _y ) {
        x = _x , y = _y ;
    }
    friend complex operator + ( const complex &p1 , const complex p2 ) {
        return complex ( p1.x + p2.x , p1.y + p2.y ) ;
    }
    friend complex operator - ( const complex &p1 , const complex &p2 ) {
        return complex ( p1.x - p2.x , p1.y - p2.y ) ;
    }
    friend complex operator * ( const complex &p1 , const complex &p2 ) {
        return complex ( p1.x * p2.x - p1.y * p2.y , p1.x * p2.y + p1.y * p2.x ) ;
    }
    friend void operator /= ( complex &p1 , const double &aux ) {
        p1.x /= aux ;
        p1.y /= aux ;
    }
};

complex ret1[ MAXN ] ;
complex ret2[ MAXN ] ;
complex ret3[ MAXN ] ;

complex root[ MAXN ] ;
complex h[ MAXN ] ;


void fft ( complex *a , int lg , int div ) {
    int len = (1<<lg) ;
    for ( int i = 0 ; i < len ; ++ i ) {
        double ang = ( 2.00 * PI * i / len ) ;
        if ( div > 0 ) { ang = -ang ; }
        root[ i ] = complex ( cos ( ang ) , sin ( ang ) ) ;
    }
    for ( int aux = 1 ; aux <= lg ; ++ aux ) {
        for ( int i = 0 ; i < len ; ++ i ) {
            h[ i ] = a[ i ] ;
        }
        int step = (1<<aux) ;
        for ( int i = 0 ; i < len ; i += step ) {
            for ( int j = 0 ; j < step ; ++ j ) {
                int id = j ;
                if ( id >= ( step / 2 ) ) { id -= step / 2 ; }
                a[ i + j ] = h[ i + id ] + root[ ( len / step ) * j ] * h[ i + ( step / 2 ) + id ] ;
            }
        }
    }
    if ( div > 0 ) {
        for ( int i = 0 ; i < len ; ++ i ) {
            a[ i ] /= div ;
        }
    }
}

complex hh[ MAXN ] ;

void mangle ( complex *a , int l , int r ) {
    if ( l == r ) { return ; }
    for ( int i = l ; i <= r ; ++ i ) {
        hh[ i ] = a[ i ] ;
    }
    int pos = l ;
    for ( int i = l ; i <= r ; i += 2 ) {
        a[ pos ++ ] = hh[ i ] ;
    }
    for ( int i = l + 1 ; i <= r ; i += 2 ) {
        a[ pos ++ ] = hh[ i ] ;
    }
    int mid = ( l + r ) / 2 ;
    mangle ( a , l , mid ) ;
    mangle ( a , mid + 1 , r ) ;
}

vector < int64_t > mult ( vector < int64_t > a , vector < int64_t > b ) {
    int lg = 0 ;
    int sr = a.size ( ) + b.size ( ) ;
    while ( (1<<lg) < sr ) { ++ lg ; }
    int len = (1<<lg) ;
    for ( int i = 0 ; i < len ; ++ i ) {
        if ( i < a.size ( ) ) {
            ret1[ i ] = complex ( a[ i ] , 0 ) ;
        }
        else {
            ret1[ i ] = complex ( 0 , 0 ) ;
        }
    }
    for ( int i = 0 ; i < len ; ++ i ) {
        if ( i < b.size ( ) ) {
            ret2[ i ] = complex ( b[ i ] , 0 ) ;
        }
        else {
            ret2[ i ] = complex ( 0 , 0 ) ;
        }
    }
    mangle ( ret1 , 0 , len - 1 ) ;
    mangle ( ret2 , 0 , len - 1 ) ;
    fft ( ret1 , lg , 0 ) ;
    fft ( ret2 , lg , 0 ) ;
    for ( int i = 0 ; i < len ; ++ i ) {
        ret3[ i ] = ret1[ i ] * ret2[ i ] ;
    }
    mangle ( ret3 , 0 , len - 1 ) ;
    fft ( ret3 , lg , len ) ;
    vector < int64_t > ans ;
    ans.resize ( sr ) ;
    for ( int i = 0 ; i < sr ; ++ i ) {
        ans[ i ] = (int64_t)( ret3[ i ].x + 0.5 ) ;
    }
    return ans ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &x ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &vals[ i ] ) ;
        if ( vals[ i ] < x ) { vals[ i ] = 1 ; }
        else { vals[ i ] = 0 ; }
        pref[ i ] = ( pref[ i - 1 ] + vals[ i ] ) ;
    }
}

void solve ( ) {
    v1.resize ( n + 1 ) ;
    v2.resize ( n + 1 ) ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        v1[ i ] = v2[ i ] = 0 ;
    }
    for ( int i = 0 ; i <= n ; ++ i ) {
        ++ v1[ pref[ i ] ] ;
        ++ v2[ n - pref[ i ] ] ;
    }
    v3 = mult ( v1 , v2 ) ;
    long long aux = 0 ;
    long long cnt = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( pref[ i ] == pref[ i - 1 ] ) { aux += cnt ++ ; }
        else { cnt = 1 ; }
    }
    printf ( "%lld" , aux ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( " %lld" , v3[ n + i ] ) ;
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