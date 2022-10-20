#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

string a ;




void input ( ) ;
void solve ( ) ;


bool f ( int x , int y )
    {
    return x > y ;
    }

int main()
    {
    input ( ) ;
    solve ( ) ;




/**
vector<int> v;
v.push_back(1);
v.push_back(6);
v.push_back(8);
v.push_back(9);
do
    {
    int x = v[3] + 10*v[2] + 100*v[1] + 1000*v[0];
    printf("%d %d\n", x, x % 7);
    } while(next_permutation(v.begin(), v.end()));
**/
    return 0;
    }


void input ( )
    {
    cin >> a ;
    }

void solve ( )
    {
    vector < int > v ;
    v.clear ( ) ;
    int i ;
    int br1 = 0 ;
    int br6 = 0 ;
    int br8 = 0 ;
    int br9 = 0 ;
    for ( i = 0 ; i < a.size ( ) ; i ++ )
        {
        if ( a[ i ] == '1' )
            {
            if ( br1 == 0 ) br1 = 1 ;
            else v.push_back ( 1 ) ;
            }
        else if ( a[ i ] == '6' )
            {
            if ( br6 == 0 ) br6 = 1 ;
            else v.push_back ( 6 ) ;
            }
        else if ( a[ i ] == '8' )
            {
            if ( br8 == 0 ) br8 = 1 ;
            else v.push_back ( 8 ) ;
            }
        else if ( a[ i ] == '9' )
            {
            if ( br9 == 0 ) br9 = 1 ;
            else v.push_back ( 9 ) ;
            }
        else v.push_back ( ( a[ i ] - '0' ) ) ;
        }
    if ( v.size ( ) == 0 )
        {
        printf ( "1869\n" ) ;
        return ;
        }
    int p = 0 ;
    sort ( v.begin ( ) , v.end ( ) , f ) ;
    if ( v[ 0 ] != 0 )
        {
        v.push_back ( 0 ) ;
        v.push_back ( 0 ) ;
        v.push_back ( 0 ) ;
        v.push_back ( 0 ) ;

        for ( i = 0 ; i < v.size ( ) ; i ++ )
            {
            if ( i + 4 < v.size ( ) ) printf ( "%d" , v[ i ] ) ;
            p = p * 10 + v[ i ] ;
            p %= 7 ;
            }
        if ( p == 0 ) printf ( "1869\n" ) ;
        if ( p == 6 ) printf ( "1968\n" ) ;
        if ( p == 5 ) printf ( "1689\n" ) ;
        if ( p == 4 ) printf ( "6891\n" ) ;
        if ( p == 3 ) printf ( "8691\n" ) ;
        if ( p == 2 ) printf ( "9168\n" ) ;
        if ( p == 1 ) printf ( "1896\n" ) ;
        }

    else
        {
        printf ( "1869" ) ;
        for ( i = 0 ; i < v.size ( ) ; i ++ ) printf ( "0" ) ;
        printf ( "\n" ) ;
        }
    }