#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n ;
int ans = 0 ;
int x ;
int cur ;


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
    cur = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &x ) ;
        if ( x != -1 ) cur += x ;
        else {
            if ( cur != 0 ) cur -- ;
            else ans ++ ;
        }
    }
}

void solve ( ) {
    printf ( "%d\n" , ans ) ;
}