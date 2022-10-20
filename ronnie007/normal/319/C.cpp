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

#define MAXN 100007
#define inf 1000000007


int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

long long dp[ MAXN ] ;

class CHT {
    public :
    struct line {
        long long a , b ;
        double x_start ;
        bool fl ;
        line ( ) { a = b = x_start = fl = 0 ; }
        line ( long long _a , long long _b ) {
            a = _a ;
            b = _b ;
            x_start = 0 ;
            fl = false ;
        }
        bool operator < ( const line other ) const {
            if ( ( fl | other.fl ) == true ) { return ( x_start < other.x_start ) ; }
            return ( a > other.a ) ;
        }
        long long value ( long long x ) const {
            return ( a * x + b ) ;
        }
    };

    double intersect ( line p1 , line p2 ) {
        if ( p1.a == p2.a ) { return inf ; }
        return ( ((double)( p2.b - p1.b )) / ( p1.a - p2.a ) ) ;
    }
    set < line > s ;

    bool has_prv ( set < line > :: iterator it ) {
        if ( s.empty ( ) == true ) { return false ; }
        if ( it == s.begin ( ) ) { return false ; }
        return true ;
    }
    bool has_nxt ( set < line > :: iterator it ) {
        if ( s.empty ( ) == true ) { return false ; }
        if ( it == s.end ( ) ) { return false ; }
        if ((++it) == s.end ( ) ) { return false ; }
        return true ;
    }
    bool needless ( line p1 , line p2 , line p3 ) {
        double ret1 = intersect ( p1 , p2 ) ;
        double ret2 = intersect ( p2 , p3 ) ;
        if ( ret1 < ret2 ) { return false ; }
        return true ;
    }
    bool needless ( set < line > :: iterator it ) {
        if ( it == s.end ( ) ) { return false ; }
        if ( has_prv ( it ) == false ) { return false ; }
        if ( has_nxt ( it ) == false ) { return false ; }
        return needless ( (*prev(it)) , (*it) , (*next(it)) ) ;
    }
    set < line > :: iterator recalc ( set < line > :: iterator it ) {
        double val ;
        if ( has_nxt ( it ) == false ) {
            val = inf ;
        }
        else {
            val = intersect ( (*it) , (*next(it)) ) ;
        }
        line aux = (*it) ;
        it = s.erase ( it ) ;
        aux.x_start = val ;
        it = s.insert ( it , aux ) ;
        return it ;
    }
    void add_line ( long long a , long long b ) {
        line aux = line ( a , b ) ;
        if ( s.empty ( ) == true ) { aux.x_start = inf ; s.insert ( aux ) ; return ; }
        set < line > :: iterator it = s.lower_bound ( aux ) ;
        if ( it!=s.end ( ) && it->a == aux.a ) {
            if ( it->b < aux.b ) { it = s.erase ( it ) ; }
            else { return ; }
        }
        it = s.insert ( it , aux ) ;
        if ( needless ( it ) == true ) { s.erase ( it ) ; return ; }
        while ( has_nxt ( it ) == true && needless ( next ( it ) ) == true ) { s.erase ( next ( it ) ) ; }
        while ( has_prv ( it ) == true && needless ( prev ( it ) ) == true ) { s.erase ( prev ( it ) ) ; }
        it = recalc ( it ) ;
        if ( has_nxt ( it ) == true ) { recalc ( next ( it ) ) ; }
        if ( has_prv ( it ) == true ) { recalc ( prev ( it ) ) ; }
        return ;
    }
    long long get_ans ( long long x ) {
        line aux ;
        aux.fl = true ;
        aux.x_start = x ;
        set < line > :: iterator it = s.lower_bound ( aux ) ;
        if ( it == s.end ( ) ) { return inf ; }
        return ( it->value ( x ) ) ;
    }
};
CHT w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    w.add_line ( b[ 1 ] , 0 ) ;
    dp[ 1 ] = 0 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        dp[ i ] = w.get_ans ( a[ i ] ) ;
        w.add_line ( b[ i ] , dp[ i ] ) ;
    }
    printf ( "%I64d\n" , dp[ n ] ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}