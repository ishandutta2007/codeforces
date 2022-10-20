#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef __int128_t ull ;

#define MAXN 600007

int n ;
string a ;
int vals[ MAXN ] ;

int st[ MAXN ] , tp ;

vector < int > v[ MAXN ] ;
int dep[ MAXN ] ;
int lstdiff[ MAXN ] ;

ull ans = 0 ;
class Tree {
public :
    ll tr[ 4 * MAXN ] ;
    int cnt[ 4 * MAXN ] , mx[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == -1 ) { return ; }
        tr[ where ] = 1LL * cnt[ where ] * lazy[ where ] ;
        mx[ where ] = lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] = lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = -1 ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = mx[ where ] = cnt[ where ] = 0 ;
        lazy[ where ] = -1 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void unite ( int where ) {
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        cnt[ where ] = cnt[ 2 * where ] + cnt[ 2 * where + 1 ] ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
    }
    void update_point ( int where , int IL , int IR , int pos , int coef ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            if ( coef == 1 ) {
                tr[ where ] = mx[ where ] = vals[ pos - 1 ] ;
                cnt[ where ] = 1 ;
            }
            else {
                tr[ where ] = mx[ where ] = 0 ;
                cnt[ where ] = 0 ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_point ( 2 * where , IL , mid , pos , coef ) ;
        update_point ( 2 * where + 1 , mid + 1 , IR , pos , coef ) ;
        unite ( where ) ;
    }
    void update_range ( int where , int IL , int IR , int CURL , int CURR , int nw ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = nw ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update_range ( 2 * where , IL , mid , CURL , CURR , nw ) ;
        update_range ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , nw ) ;
        unite ( where ) ;
    }
    int get_fst ( int where , int IL , int IR , int sr ) {
        push_lazy ( where , IL , IR ) ;
        if ( mx[ where ] < sr ) { return IR + 1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_fst ( 2 * where , IL , mid , sr ) ;
        if ( ret != mid + 1 ) { return ret ; }
        return get_fst ( 2 * where + 1 , mid + 1 , IR , sr ) ;
    }
    ll query ( ) {
        push_lazy ( 1 , 1 , n ) ;
        return tr[ 1 ] ;
    }
};
Tree w ;


int matched_len ;
bool seen[ MAXN ] ;
int PI[ MAXN ] ;

int get_mn ( int pos ) {
    int l , r , mid ;
    l = 0 , r = tp - 1 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( st[ mid ] < pos ) { l = mid ; }
        else { r = mid ; }
    }
    while ( st[ l ] < pos ) { ++ l ; }
    return vals[ st[ l ] ] ;
}

void append_letter ( int wh ) {
    while ( tp > 0 && vals[ st[ tp - 1 ] ] > vals[ wh ] ) {
        tp -- ;
    }
    st[ tp ++ ] = wh ;
    ans += vals[ st[ 0 ] ] ;
    if ( wh > 0 ) {
        if ( a[ wh ] != a[ PI[ wh ] ] ) {
            lstdiff[ wh ] = PI[ wh ] ;
        }
        else {
            lstdiff[ wh ] = lstdiff[ PI[ wh ] ] ;
        }
        while ( matched_len > 0 && a[ matched_len ] != a[ wh ] ) {
            matched_len = PI[ matched_len ] ;
        }
        if ( a[ matched_len ] == a[ wh ] ) {
            ++ matched_len ;
        }
        if ( seen[ matched_len ] == false ) {
            dep[ matched_len ] = dep[ PI[ matched_len ] ] + 1 ;
            seen[ matched_len ] = true ;
        }
    }
    PI[ wh + 1 ] = matched_len ;
    if ( wh == 0 ) { return ; }
    int aux = PI[ wh ] ;
    while ( aux > 0 ) {
        if ( a[ aux ] == a[ wh ] ) {
            aux = lstdiff[ aux ] ;
        }
        else {
            w.update_point ( 1 , 1 , n , wh - aux + 1 , -1 ) ;
            aux = PI[ aux ] ;
        }
    }
    int st = w.get_fst ( 1 , 1 , n , vals[ wh ] ) ;
    w.update_range ( 1 , 1 , n , st , n , vals[ wh ] ) ;
    if ( a[ wh ] == a[ 0 ] ) {
        w.update_point ( 1 , 1 , n , wh + 1 , 1 ) ;
    }
    ans += w.query ( ) ;
}

void input ( ) {
    cin >> n ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    seen[ 0 ] = true ;
    const ll MASK = ( 1 << 30 ) - 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        char c ; int x ;
        cin >> c >> x ;
        int hh = ( ( c - 'a' ) + ( ans % 26 ) ) % 26 ;
        c = char ( hh + 'a' ) ;
        x = x ^ ( MASK & ans ) ;
        vals[ i ] = x ;
        a += c ;
        append_letter ( i ) ;
        auto format = [ & ] ( ull hh ) {
            if ( hh == 0 ) {
                cout << "0\n" ;
                return ;
            }
            string out ;
            while ( hh > 0 ) {
                out += char ( '0' + ( hh % 10 ) ) ;
                hh /= 10 ;
            }
            reverse ( out.begin ( ) , out.end ( ) ) ;
            cout << out << "\n" ;
        };
        format ( ans ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}