#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;

struct tuhla
    {
    string name ;
    int car ;
    int pizza ;
    int girl ;
    };

struct tuhla a[ 127 ] ;

int main ( )
    {
    cin >> n ;
    int i , j , m ;
    string h ;
    for ( i = 0 ; i < n ; i ++ )
        {
        cin >> m ;
        cin >> a[ i ].name ;
        a[ i ].pizza = 0 ;
        a[ i ].car = 0 ;
        a[ i ].girl = 0 ;
        for ( j = 0 ; j < m ; j ++ )
            {
            cin >> h ;
            if ( h[ 0 ] == h[ 1 ] && h[ 1 ] == h[ 3 ] && h[ 3 ] == h[ 4 ] && h[ 4 ] == h[ 6 ] && h[ 6 ] == h[ 7 ] )
                {
                a[ i ].car ++ ;
                }
            else if ( h[ 0 ] > h[ 1 ] && h[ 1 ] > h[ 3 ] && h[ 3 ] > h[ 4 ] && h[ 4 ] > h[ 6 ] && h[ 6 ] > h[ 7 ] )
                {
                a[ i ].pizza ++ ;
                }
            else a[ i ].girl ++ ;
            }
        }
    bool f = false ;
    int mx = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( mx < a[ i ].car ) mx = a[ i ].car ;
        }
    cout << "If you want to call a taxi, you should call:" ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( mx == a[ i ].car )
            {
            if ( f == true ) printf ( "," ) ;
            f = true ;
            cout << " " << a[ i ].name ;
            }
        }
    cout << ".\n" ;

    f = false ;
    mx = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( mx < a[ i ].pizza ) mx = a[ i ].pizza ;
        }
    cout << "If you want to order a pizza, you should call:" ;
    for ( i = 0 ; i < n ; i ++ )
        {

        if ( mx == a[ i ].pizza )
            {
            if ( f == true ) printf ( "," ) ;
            f = true ;
            cout << " " << a[ i ].name ;
            }
        }
    cout << ".\n" ;

    f = false ;
    mx = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( mx < a[ i ].girl ) mx = a[ i ].girl ;
        }
    cout << "If you want to go to a cafe with a wonderful girl, you should call:" ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( mx == a[ i ].girl )
            {
            if ( f == true ) printf ( "," ) ;
            f = true ;
            cout << " " << a[ i ].name ;
            }
        }
    cout << ".\n" ;
    return 0 ;
    }