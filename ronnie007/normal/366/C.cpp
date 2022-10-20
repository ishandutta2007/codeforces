#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

int n , k ;

struct tuhla
    {
    int x , y , z ;
    };

struct tuhla a[ 107 ] ;

#define OFFSET 99900
#define LOWER -99900
#define UPPER 9900

int used[ 220017 ] ;

bool f ( struct tuhla p1 , struct tuhla p2 )
    {
    if ( p1.x > p2.x ) return true ;
    return false ;
    }

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
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ].x ) ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ].y ) ;
        a[ i ].y = a[ i ].y * k ;
        a[ i ].z = a[ i ].x - a[ i ].y ;
        }
    ///sort ( a , a + n , f ) ;
    }

void solve ( )
    {
    int i, j;
    int st , en , inc ;

    for(i = LOWER ; i <= UPPER ; i++)
        {
        used [ i + OFFSET ] = -1;
        }
    used [ 0 + OFFSET ] = 0 ;

    for ( i = 0 ; i < n ; i ++ )
        {
        if ( a[ i ].z >= 0 )
            {
            st = UPPER;
            en = LOWER;
            inc = -1;
            }
         else
            {
            st = LOWER;
            en = UPPER;
            inc = 1;
            }

        for(j = st; j != en; j += inc)
            {
            if ( j - a[ i ].z >= LOWER && j - a[ i ].z <= UPPER )
            if ( used[ j - a[ i ].z + OFFSET] != -1)
            if ( used[ j - a[ i ].z + OFFSET] + a[ i ].x >= used[ j + OFFSET ] )
            used[ j + OFFSET ] = used [ j - a[ i ].z + OFFSET ] + a[ i ].x;
            }
        }

    if ( used[ 0 + OFFSET ] != 0 )
        {
        printf ( "%d\n", used[ 0 + OFFSET ] ) ;
        }
    else printf ( "-1\n" ) ;
    }