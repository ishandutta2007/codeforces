#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int m ;
int n ;
string a ;

int main ( )
    {
    int i ;
    int j ;
    int ind1 = 0 ;
    int ind2 = 0 ;
    cin >> m ;
    char c ;
    cin.get ( c ) ;
    for ( i = 0 ; i < m ; i ++ )
        {
        getline ( cin , a ) ;
        n = a.size ( ) ;
        if ( a.size ( ) <= 4 )
            {
            cout << "OMG>.< I don't know!\n" ;
            continue ;
            }
        ind1 = 0 ;
        ind2 = 0 ;
        if ( a[ 0 ] == 'm' && a[ 1 ] == 'i' && a[ 2 ] == 'a' && a[ 3 ] == 'o' && a[ 4 ] == '.' )
            {
            ind1 = 1 ;
            }
        if ( a[ n - 5 ] == 'l' && a[ n - 4 ] == 'a' && a[ n - 3 ] == 'l' && a[ n - 2  ] == 'a' && a[ n - 1 ] == '.' )
            {
            ind2 = 1 ;
            }
        if ( ind1 + ind2 != 1 )
            {
            cout << "OMG>.< I don't know!\n" ;
            continue ;
            }
        else
            {
            if ( ind1 == 1 ) cout << "Rainbow's\n" ;
            else cout << "Freda's\n" ;
            }
        }
    return 0 ;
    }