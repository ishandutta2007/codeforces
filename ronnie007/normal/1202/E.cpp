#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

string text ;
int n ;
string a[ MAXN ] ;

long long st[ MAXN ] ;
long long en[ MAXN ] ;

class aho {
public :
    struct node {
        int to[ 26 ] ;
        int link ;
        int cnt ;
        node ( ) {
            for ( int i = 0 ; i < 26 ; ++ i ) {
                to[ i ] = 0 ;
            }
            link = cnt = 0 ;
        }
    };
    vector < node > v ;
    int tpsz ;
    void init ( ) {
        v.resize ( 1 ) ;
        tpsz = 0 ;
    }
    void add_word ( string s ) {
        int sz = s.size ( ) ;
        int aux = 0 ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( v[ aux ].to[ s[ i ] - 'a' ] == 0 ) {
                v.push_back ( node ( ) ) ;
                v[ aux ].to[ s[ i ] - 'a' ] = ++ tpsz ;
            }
            aux = v[ aux ].to[ s[ i ] - 'a' ] ;
        }
        ++ v[ aux ].cnt ;
    }
    void push_links ( ) {
        queue < int > q ;
        q.push ( 0 ) ;
        while ( q.empty ( ) == false ) {
            int x = q.front ( ) ;
            q.pop ( ) ;
            for ( int i = 0 ; i < 26 ; ++ i ) {
                if ( v[ x ].to[ i ] == 0 ) { continue ; }
                if ( x == 0 ) {
                    v[ v[ x ].to[ i ] ].link = 0 ;
                    v[ v[ x ].to[ i ] ].cnt += v[ x ].cnt ;
                    q.push ( v[ x ].to[ i ] ) ;
                    continue ; 
                }
                int aux = v[ x ].link ;
                while ( aux > 0 && v[ aux ].to[ i ] == 0 ) {
                    aux = v[ aux ].link ;
                }
                if ( v[ aux ].to[ i ] > 0 ) {
                    aux = v[ aux ].to[ i ] ;
                }
                v[ v[ x ].to[ i ] ].link = aux ;
                v[ v[ x ].to[ i ] ].cnt += v[ aux ].cnt ;
                q.push ( v[ x ].to[ i ] ) ;
            }
        }
    }
    void advance ( int &state , int val ) {
        while ( state > 0 && v[ state ].to[ val ] == 0 ) {
            state = v[ state ].link ;
        }
        if ( v[ state ].to[ val ] > 0 ) {
            state = v[ state ].to[ val ] ;
        }
    }
    int obtain ( int state ) {
        return v[ state ].cnt ;
    }
};

aho fw , rv ;

void input ( ) {
    cin >> text ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    fw.init ( ) ;
    rv.init ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fw.add_word ( a[ i ] ) ;
        string aux = "" ;
        int sz = a[ i ].size ( ) ;
        for ( int j = sz - 1 ; j >= 0 ; -- j ) {
            aux += a[ i ][ j ] ;
        }
        rv.add_word ( aux ) ;
    }
    fw.push_links ( ) ;
    rv.push_links ( ) ;
    int state = 0 ;
    int len = text.size ( ) ;
    for ( int i = 0 ; i < len ; ++ i ) {
        fw.advance ( state , text[ i ] - 'a' ) ;
        en[ i ] = fw.obtain ( state ) ;
    }
    state = 0 ;
    for ( int i = len - 1 ; i >= 0 ; -- i ) {
        rv.advance ( state , text[ i ] - 'a' ) ;
        st[ i ] = rv.obtain ( state ) ;
    }
    long long ans = 0 ;
    for ( int i = 1 ; i < len ; ++ i ) {
        ans += en[ i - 1 ] * st[ i ] ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}