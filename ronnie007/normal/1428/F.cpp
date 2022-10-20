#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n ;
string a ;
int len[ MAXN ] ;
long long ans ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    long long sm = 0 ;
    stack < pair < pair < int , int > , long long > > st ;
    long long cons = 0 ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        if ( a[ i ] == '0' ) {
            ans += sm ;
            cons = 0 ;
        }
        else {
            ++ cons ;
            while ( st.empty ( ) == false && cons >= st.top ( ).first.first ) {
                st.pop ( ) ;
            }
            if ( st.empty ( ) == false ) {
                sm = st.top ( ).second + cons * ( st.top ( ).first.second - i ) ;
            }
            else {
                sm = cons * ( cons + 1 ) / 2 + ( n - i - cons ) * cons ;
            }
            st.push ( { { cons , i } , sm } ) ;
            ans += sm ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}