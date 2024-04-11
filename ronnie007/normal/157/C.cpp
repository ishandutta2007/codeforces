#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

string a ;
string b ;


void input ( ) ;
void solve ( ) ;

int main()
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


int f ( int pos )
    {
    int i , j ;
    int ans = 0 ;
    for( i = pos , j = 0; j < (int)b.size ( ) && i < pos +  (int)b.size( ) && i < (int)a.size(); i ++ , j ++ )
        {
        if ( 0 <= i && a[ i ] == b[ j ] )
            {
            ans ++ ;
            }
        }
    ///cout << ans << "\n" ;
    return ans ;
    }

void input ( )
    {
    cin >> a >> b ;
    }

void solve ( )
    {
    int i ;
    int mx = -1 ;
    for ( i = 1 - (int)b.size ( ) ; i < (int)a.size ( ) ; i ++ )
        {
        mx = max( mx ,f( i ) ) ;
        }
    ///cout << mx << "\n" ;
    printf ( "%d\n" , b.size( ) - mx ) ;
    }