#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

string a ;
int n ;
string ans ;

void input ( ) ;
void solve ( ) ;

bool check ( string x )
    {
    int i ;
    for ( i = 0 ; i < a.size ( ) ; i ++ )
        {
        if ( a[ i ] != x[ i ] ) return false ;
        }
    return true ;
    }




int main ( )
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
    cin >> n ;
    int i ;
    string b ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> b ;
        if ( check ( b ) == true )
            {
            if ( ans > b || ans.size ( ) == 0 ) ans = b ;
            }
        }
    if ( ans.size ( ) == 0 ) ans = a ;
    cout << ans << "\n" ;
    }