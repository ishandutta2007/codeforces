#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;
int n ; 
string a[ 107 ] ;
int used[ 107 ][ 107 ] ;

void input ( ) ;
void solve ( ) ;

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a[ i ] ; 
    }
}
void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < n - 2 ; i ++ ) {
        for ( j = 1 ; j < n - 1 ; j ++ ) {
            if ( a[ i ][ j ] == '#' ) {
                if ( a[ i + 1 ][ j ] == '#' && a[ i + 2 ][ j ] == '#' && a[ i + 1 ][ j - 1 ] == '#' && a[ i + 1 ][ j + 1 ] == '#' ) {
                    if ( used[ i + 1 ][ j ] == 0 && used[ i + 2 ][ j ] == 0 && used[ i + 1 ][ j - 1 ] == 0 && used[ i + 1 ][ j + 1 ] == 0&& used[ i ][ j ] == 0 ) {
                        used[ i ][ j ] = 1 ;
                        used[ i + 1 ][ j ] = 1 ;
                        used[ i + 1 ][ j + 1 ] = 1 ;
                        used[ i + 1 ][ j - 1 ] = 1 ;
                        used[ i + 2 ][ j ] = 1 ;
                        
                    }
                    
                }
            }
        }
    } 
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j < n ; j ++ ) {
            if ( a[ i ][ j ] == '#' && used[ i ][ j ] == 0 ) {
                printf ( "NO\n" ) ;
                return ;
            }
        }
    }
    printf ( "YES\n" ) ;
}