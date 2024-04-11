#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MAXN 307

int n ;
string s[ MAXN ] ;

struct tuhla {
    long long len ;
    string s ;
    int st[ 17 ] ;
    int en[ 17 ] ;
    int br[ 5007 ] ;
    int aux[ 5007 ] ;
    int mxnull ;
};

tuhla a[ MAXN ] ;

void process ( int id ) {
    int h = min ( 11LL , a[ id ].len ) ;
    int i , j , t ;
    for ( i = 0 ; i < 11 ; i ++ ) {
        a[ id ].st[ i ] = a[ id ].en[ i ] = 0 ;
    }
    for ( i = 0 ; i < h ; i ++ ) {
        a[ id ].st[ i ] = ( a[ id ].s[ i ] - '0' ) ;
    }
    int sz = a[ id ].len ;
    for ( i = 0 ; i < h ; i ++ ) {
        a[ id ].en[ i ] = ( a[ id ].s[ sz - i - 1 ] - '0' ) ;
    }
    int lim = (1<<11) ;
    int w = 0 ;
    for ( i = 0 ; i < lim ; i ++ ) {
        if ( i == 0 ) { w ++ ; }
        else if ( (i&(i-1)) == 0 && i != 1 ) {
            w ++ ;
        }
        for ( j = sz - 1 ; j >= w - 1 ; j -- ) {
            int h = i ;
            for ( t = 0 ; t < w ; t ++ ) {
                int val = ( h % 2 ) ;
                h /= 2 ;
                if ( val != ( a[ id ].s[ j - t ] - '0' ) ) { break ; }
            }
            if ( t == w ) {
                a[ id ].br[ i ] = 1 ;
                break ;
            }
        }
    }
    w = 0 ;
    for ( i = 0 ; i < lim ; i ++ ) {
        if ( i == 0 ) { w ++ ; }
        else if ( (i&(i-1)) == 0 && i != 1 ) {
            w ++ ;
        }
        for ( j = sz - 1 ; j >= w - 1 ; j -- ) {
            int h = i ;
            for ( t = 0 ; t < w ; t ++ ) {
                int val = ( h % 2 ) ;
                h /= 2 ;
                if ( val == ( a[ id ].s[ j - t ] - '0' ) ) { break ; }
            }
            if ( t == w ) {
                a[ id ].aux[ i ] = 1 ;
                break ;
            }
        }
    }
}

void combine ( int x , int y , int id ) {
    int i , j , t ;
    int lim = (1<<11) ;
    a[ id ].mxnull = max ( a[ x ].mxnull , a[ y ].mxnull ) ;
    for ( i = 0 ; i < lim ; i ++ ) {
        if ( a[ x ].br[ i ] != 0 || a[ y ].br[ i ] != 0 ) {
            a[ id ].br[ i ] = 1 ;
        }
        if ( a[ x ].aux[ i ] != 0 || a[ y ].aux[ i ] != 0 ) {
            a[ id ].aux[ i ] = 1 ;
        }
    }
    int h = min ( 11LL , a[ x ].len ) ;
    for ( i = 0 ; i < 11 ; i ++ ) {
        a[ id ].st[ i ] = a[ id ].en[ i ] = 0 ;
    }
    for ( i = 0 ; i < h ; i ++ ) {
        a[ id ].st[ i ] = a[ x ].st[ i ] ;
    }
    int pos = 0 ;
    while ( h < 11 ) {
        a[ id ].st[ h ] = a[ y ].st[ pos ] ;
        pos ++ ;
        h ++ ;
    }

    h = min ( 11LL , a[ y ].len ) ;
    for ( i = 0 ; i < h ; i ++ ) {
        a[ id ].en[ i ] = a[ y ].en[ i ] ;
    }
    pos = 0 ;
    while ( h < 11 ) {
        a[ id ].en[ h ] = a[ x ].en[ pos ] ;
        pos ++ ;
        h ++ ;
    }
    string comb ;
    h = min ( 11LL , a[ x ].len ) ;
    for ( i = h - 1 ; i >= 0 ; i -- ) {
        comb += (char( a[ x ].en[ i ] + '0' )) ;
    }
    h = min ( 11LL , a[ y ].len ) ;
    for ( i = 0 ; i < h ; i ++ ) {
        comb += (char(a[ y ].st[ i ] + '0' )) ;
    }
    int w = 0 ;
    int sz = comb.size ( ) ;
    for ( i = 0 ; i < lim ; i ++ ) {
        if ( i == 0 ) { w ++ ; }
        else if ( (i&(i-1)) == 0 && i != 1 ) {
            w ++ ;
        }
        for ( j = sz - 1 ; j >= w - 1 ; j -- ) {
            int h = i ;
            for ( t = 0 ; t < w ; t ++ ) {
                int val = ( h % 2 ) ;
                h /= 2 ;
                if ( val != ( comb[ j - t ] - '0' ) ) { break ; }
            }
            if ( t == w ) {
                a[ id ].br[ i ] = 1 ;
                break ;
            }
        }
    }

    w = 0 ;
    for ( i = 0 ; i < lim ; i ++ ) {
        if ( i == 0 ) { w ++ ; }
        else if ( (i&(i-1)) == 0 && i != 1 ) {
            w ++ ;
        }
        for ( j = sz - 1 ; j >= w - 1 ; j -- ) {
            int h = i ;
            for ( t = 0 ; t < w ; t ++ ) {
                int val = ( h % 2 ) ;
                h /= 2 ;
                if ( val == ( comb[ j - t ] - '0' ) ) { break ; }
            }
            if ( t == w ) {
                a[ id ].aux[ i ] = 1 ;
                break ;
            }
        }
    }
}

int getans ( int id ) {
    int i ;
    int w = 0 ;
    int lim = (1<<11) ;
    for ( i = 0 ; i < lim ; i ++ ) {
        if ( i == 0 ) { w ++ ; }
        else if ( (i&(i-1)) == 0 && i != 1 ) {
            w ++ ;
        }
        if ( a[ id ].br[ i ] == 0 || a[ id ].aux[ i ] == 0 ) { break ; }
    }
    w -- ;
    if ( i == lim ) { w = 11 ; }
    return w ;
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> s[ i ] ;
        a[ i ].s = s[ i ] ;
        a[ i ].len = s[ i ].size ( ) ;
        process ( i ) ;
    }
}

void solve ( ) {
    int q ;
    cin >> q ;
    int nw = n ;
    while ( q != 0 ) {
        q -- ;
        int x , y ;
        cin >> x >> y ;
        nw ++ ;
        a[ nw ].len = a[ x ].len + a[ y ].len ;
        if ( a[ nw ].len > 100 ) { a[ nw ].len = 100 ; }
        combine ( x , y , nw ) ;
        cout << getans ( nw ) << "\n" ;
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}