#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n , m ;
int ans = 0 ;

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
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x ;
    int br = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &x ) ;
        br += x ;
        if ( br > m ) { br = x ; ans ++ ; }
    }
}

void solve ( ) {
    printf ( "%d\n" , ans + 1 ) ;
}