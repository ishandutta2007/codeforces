#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

string a ;
string ans ;


void input ( ) ;
void solve ( ) ;

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    cin >> a ;
    }

void solve ( )
    {
    int i ;
    ans.resize ( a.size ( ) ) ;
    int sz = 0 ;
    int br = 1 ;
    ans[ 0 ] = a[ 0 ] ;
    int n = a.size ( ) ;
    sz = 1 ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] == a[ i - 1 ] )
            {
            br ++ ;
            if ( br < 3 )
                {
                ans[ sz ] = a[ i ] ;
                sz ++ ;
                }
            }
        else { br = 1 ; ans[ sz ] = a[ i ] ; sz ++ ; }
        }
    for ( i = 3 ; i < sz ; i ++ )
        {
        if ( ans[ i ] == ans[ i - 1 ] && ans[ i - 2 ] == ans[ i - 3 ] )
            {
            ans[ i ] = '/';
            }
        }
    for ( i = 0 ; i < sz ; i ++ )
        {
        if ( ans[ i ] != '/' ) cout << ans[ i ] ;
        }
    cout << "\n" ;
    }