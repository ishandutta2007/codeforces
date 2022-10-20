#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;

#define MOD 1000000007

int n , k , d ;
int dp[ 177 ][ 177 ] ;

void input ( ) ;
void solve ( ) ;

long long f ( int lft , int mx ) {
    int i ;
    ///cout << lft << " " << mx << "\n" ;
    long long ret = 0 ;
    if ( lft == 0 ) {
        if ( mx >= d ) {
            dp[ lft ][ mx ] = 1 ;
            return 1 ;
        }
        dp[ lft ][ mx ] = 0 ;
        return 0 ;
    }
    if ( dp[ lft ][ mx ] != -1 ) return dp[ lft ][ mx ] ;
    int arg1 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        if ( i > lft ) break ;
        arg1 = mx ;
        if ( i > mx ) arg1 = i ;
        ret = ( ret + f ( lft - i , arg1 ) ) % MOD ;
    }
    dp[ lft ][ mx ] = ret ;
    return ret ;
}

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    cin >> n >> k >> d ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i <= 105 ; i ++ ) {
        for ( j = 0 ; j <= 105 ; j ++ ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    long long ans = f ( n , 0 ) ;
    cout << ans << "\n" ;
}