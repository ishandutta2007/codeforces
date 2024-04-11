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

int n ;
int a[ 100007 ] ;
int k[ 100007 ] ;

int pos[ 100007 ] ;

vector < int > v ;
vector < pair < int , int > > ans ;


void input ( ) ;
void solve ( ) ;



int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        pos[ a[ i ] ] = i ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 2 ; i <= n + 1  ; i ++ ) {
        if ( k[ i ] == 0 ) {
            v.push_back ( i ) ;
            for ( j = i ; j <= n + 1 ; j += i ) {
                k[ j ] = 1 ;
            }
        }
    }
    int tmp ;
    int l , r , mid ;
    int lft ;
    int ind ;
    int q , w ;
    for ( i = n ; i >= 1 ; i -- ) {
        ///printf ( "---%d\n" , i ) ;
        while ( pos[ i ] != i ) {
            lft = i - pos[ i ] + 1 ;
            l = 0 ;
            r = v.size ( ) - 1 ;

            while ( r - l > 2 ) {
                mid = ( r + l ) / 2 ;
                if ( v[ mid ] <= lft ) l = mid ;
                else r = mid ;
            }

            while ( v[ r ] > lft ) r -- ;

            ind = pos[ i ] + v[ r ] - 1 ;
            ans.push_back ( make_pair ( pos[ i ] , ind ) ) ;
            q = a[ pos[ i ] ] ;
            ///printf ( "%d\n" , q ) ;
            w = a[ ind ] ;
            swap ( a[ pos[ i ] ] , a[ ind ] ) ;
            swap ( pos[ i ] , pos[ w ] ) ;

            /**
            tmp = pos[ i ] ;
            pos[ a[ tmp ] ] = tmp ;
            pos[ a[ tmp + v[ r ] - 1 ] ] = tmp + v[ r ] - 1 ;
            **/

        }
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}