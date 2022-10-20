#include<bits/stdc++.h>
using namespace std ;

int q ;

unordered_map < long long , set < pair < int , int > > > w ;

map < pair < int , int > , int > cnt ;
map < pair < int , int > , int > line ;

pair < int , int > f ( pair < int , int > x , pair < int , int > y ) {
    pair < int , int > ret = { x.first + y.first , x.second + y.second } ;
    int aux = __gcd ( ret.first , ret.second ) ;
    ret.first /= aux ;
    ret.second /= aux ;
    return ret ;
}

void add ( int x , int y , int coef ) {
    long long dist = 1LL * x * x + 1LL * y * y ;
    if ( coef < 0 ) {
        w[ dist ].erase ( { x , y } ) ;
    }
    set < pair < int , int > > :: iterator it = w[ dist ].begin ( ) ;
    while ( it != w[ dist ].end ( ) ) {
        cnt[ f ( { x , y } , (*it) ) ] += coef ;
        ++ it ;
    }
    if ( coef > 0 ) {
        w[ dist ].insert ( { x , y } ) ;
    }
}

void input ( ) {
    cin >> q ;
}

void solve ( ) {
    int type , x , y ;
    int h = 0 ;
    while ( q -- ) {
        cin >> type >> x >> y ;
        if ( type == 1 ) {
            ++ h ;
            add ( x , y , 1 ) ;
            int aux = __gcd ( x , y ) ;
            x /= aux ;
            y /= aux ;
            ++ line[ { x , y } ] ;
        }
        else if ( type == 2 ) {
            -- h ;
            add ( x , y , -1 ) ;
            int aux = __gcd ( x , y ) ;
            x /= aux ;
            y /= aux ;
            -- line[ { x , y } ] ;
        }
        else {
            int aux = __gcd ( x , y ) ;
            x /= aux ;
            y /= aux ;
            cout << h - 2 * cnt[ { x , y } ] - line[ { x , y } ] << "\n" ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}