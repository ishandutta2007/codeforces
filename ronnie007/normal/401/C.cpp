#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<map>
using namespace std;

int n , m ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}



void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
    int i ;
    if ( n == 1 ) {
        if ( m > 4 ) { printf ( "-1" ) ; return ; }
        else {
            if ( m == 1 ) printf ( "01\n" ) ;
            if ( m == 2 ) printf ( "101\n" ) ;
            if ( m == 3 ) printf ( "1101\n" ) ;
            if ( m == 4 ) printf ( "11011\n" ) ;
            return ;
        }
    }
    int x = n - 1 ;
    if ( m >= x && 2 * x >= m ) {
        while ( x > 0 ) {
            printf ( "0" ) ;
            x -- ;
            ///if ( x == 0 ) break ;
            printf ( "1" ) ;
            m -- ;
            if ( m > x ) {
                printf ( "1" ) ;
                m -- ;
            }
        }
        printf ( "0" ) ;
        printf ( "\n" ) ;
        return ;
    }
    x = n - 1 ;
    if ( m >= x + 1 && 2 * ( x + 1 ) >= m ) {
        //printf ( "here\n" ) ;
        printf ( "1" ) ;
        m -- ;
        if ( m > x ) {
            printf ( "1" ) ;
            m -- ;
        }
        //if ( x == 0 ) printf ( "0" ) ;
        while ( x > 0 ) {
            printf ( "0" ) ;
            x -- ;
            printf ( "1" ) ;
            m -- ;
            if ( m > x ) {
                printf ( "1" ) ;
                m -- ;
            }
        }
        printf ( "0" ) ;
        printf ( "\n" ) ;
        return ;
    }
    x = n - 1 ;
    if ( m >= ( x + 2 )  && 2 * ( x + 2 ) >= m ) {
        printf ( "1" ) ;
        m -- ;
        if ( m > x ) {
            printf ( "1" ) ;
            m -- ;
        }
        while ( x > 0 ) {
            printf ( "0" ) ;
            x -- ;
            printf ( "1" ) ;
            m -- ;
            if ( m > x ) {
                printf ( "1" ) ;
                m -- ;
            }
        }
        printf ( "0" ) ;
        //printf ( "\n" ) ;
        while ( m > 0 ) { printf ( "1" ) ; m -- ; }
        printf ( "\n" ) ;
        return ;
    }
    printf ( "-1\n" ) ;
}