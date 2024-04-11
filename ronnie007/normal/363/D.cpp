#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int n , m , a ;
int b[ 100007 ] ;
int p[ 100007 ] ;
long long cost ;

bool check ( int x )
    {
    long long  sum=0,sum2=0;
    for ( int l = 0 , r = x - 1 ; l < x && r >= 0 ; l ++ , r -- )
        {
        sum += max ( p[ r ] - b[ l ] , 0 ) ;
        sum2 += min ( p[ r ] , b[ l ] ) ;
        }
    if ( sum <= (long long)a )
        {
        cost = max ( 0LL , sum2 + sum - a ) ;
        return true;
        }
    return false;
    }

void input();
void solve();



int main()
    {
    input();
    solve() ;
    return 0;
    }
bool f ( int x , int y )
    {
    return x > y ;
    }

void input()
    {
    scanf ( "%d%d%d" , &n , &m , &a ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &b[ i ] ) ;
        }
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d" , &p[ i ] ) ;
        }
    sort ( b , b + n , f ) ;
    sort ( p , p + m ) ;
    }



void solve ( )
    {
    int l = 0 ;
    int r  = min ( n , m )  ;
    int mid ;
    while ( r - l > 1 )
        {
        mid = ( r + l ) / 2 ;
        if ( check ( mid ) == true ) l = mid ;
        else r = mid ;
        }
    if ( check ( l + 1 ) == true ) l ++ ;
    printf ( "%d %d\n" , l , cost ) ;
    }