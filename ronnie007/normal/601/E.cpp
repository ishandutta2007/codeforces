#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007
#define MAXQ 30007
#define MAXVAL 1007

long long coef = 1e7 + 19 ;
long long MOD = 1e9 + 7 ;

struct item {
    int value , mass ;
    item ( ) { value = mass = 0 ; }
    item ( int _value , int _mass ) {
        value = _value ;
        mass = _mass ;
    }
};

vector < item > item_list ;
vector < int > st ;
vector < int > en ;
int n , lim ;


vector < int > tr[ 4 * MAXQ ] ;
void update ( int where , int IL , int IR , int CURL , int CURR , int id ) {
    if ( IL > IR || CURL > CURR ) { return ; }
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
        tr[ where ].push_back ( id ) ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , id ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , id ) ;
}

long long ans[ MAXQ ] ;

struct tuhla {
    int dp[ MAXVAL ] ;
    tuhla ( ) {
        for ( int i = 0 ; i <= lim ; ++ i ) {
            dp[ i ] = 0 ;
        }
    }
    void advance ( int v , int w ) {
        for ( int i = lim - w ; i >= 0 ; -- i ) {
            dp[ i + w ] = max ( dp[ i + w ] , dp[ i ] + v ) ;
        }
    }
};

vector < tuhla > hist ;

void proc ( int id ) {
    ans[ id ] = 0 ;
    int mx = 0 ;
    long long hh = 1 ;
    for ( int i = 1 ; i <= lim ; ++ i ) {
        mx = max ( mx , ( hist.back ( ) ).dp[ i ] ) ;
        ans[ id ] = ( ans[ id ] + hh * mx ) % MOD ;
        hh = ( hh * coef ) % MOD ;
    }
}

void calc ( int where , int IL , int IR ) {
    for ( auto x : tr[ where ] ) {
        hist.push_back ( hist.back ( ) ) ;
        ( hist.back ( ) ).advance ( item_list[ x ].value , item_list[ x ].mass ) ;
    }
    if ( IL == IR ) { proc ( IL ) ; }
    else { 
        int mid = ( IL + IR ) / 2 ;
        calc ( 2 * where , IL , mid ) ;
        calc ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    for ( auto x : tr[ where ] ) {
        hist.pop_back ( ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &lim ) ;
    item_list.resize ( n ) ;
    st.resize ( n ) ;
    en.resize ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &item_list[ i ].value , &item_list[ i ].mass ) ;
        st[ i ] = 0 ;
        en[ i ] = -1 ;
    }
    int tot ;
    n = 0 ;
    scanf ( "%d" , &tot ) ;
    for ( int i = 1 ; i <= tot ; ++ i ) {
        int type ;
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            int x , y ;
            scanf ( "%d%d" , &x , &y ) ;
            item_list.push_back ( item ( x , y ) ) ;
            st.push_back ( n ) ;
            en.push_back ( -1 ) ;
        }
        else if ( type == 2 ) {
            int id ;
            scanf ( "%d" , &id ) ;
            en[ -- id ] = n ;
        }
        else {
            ++ n ;
        }
    }
}

void solve ( ) {
    int sz = item_list.size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( en[ i ] == -1 ) { en[ i ] = n ; }
        update ( 1 , 1 , n , st[ i ] + 1 , en[ i ] , i ) ;
    }
    hist.push_back ( tuhla ( ) ) ;
    calc ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%lld\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}