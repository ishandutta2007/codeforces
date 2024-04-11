#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;

int n , m ;

string a , b ;

int br[ 200007 ] ;

string rev ( string x ) {
    int i , sz ;
    sz = x.size ( ) ;
    string ret ;
    ret.clear ( ) ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        ret += x[ i ] ;
    }
    return ret ;
}

vector < int > w ( vector  < int > x ) {
    int i ;
    int sz = x.size ( ) ;
    vector < int > ret ;
    ret.clear ( ) ;
    for ( i = sz - 1 ; i >= 0 ; i -- ) {
        ret.push_back ( x[ i ] ) ;
    }
    return ret ;
}

void input ( ) ;
void solve ( ) ;

int main ( ) {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> a >> b ;
    a = rev ( a ) ;
    b = rev ( b ) ;
}

void solve ( ) {
    n = a.size ( ) ;
    m = b.size ( ) ;
    int i ;
    stack < int > s1 ;
    vector < int > v1 ;
    stack < int > s2 ;
    vector < int > v2 ;

    int x , y ;

    for ( i = n - 1 ; i >= -1 ; i -- ) {
        while ( 1 ) {
            if ( s1.empty ( ) == true ) break ;
            x = s1.top ( ) ;
            s1.pop ( ) ;
            if ( s1.empty ( ) == true ) {
                s1.push ( x ) ;
                break ;
            }
            y = s1.top ( ) ;
            s1.pop ( ) ;
            if ( y == x + 1 ) {
                s1.push ( y + 1 ) ;
            }
            else {
                s1.push ( y ) ;
                s1.push ( x ) ;
                break ;
            }
        }
        if ( i != -1 && a[ i ] == '1' ) s1.push ( i ) ;
    }
    while ( s1.empty ( ) == false ) {
        x = s1.top ( ) ;
        v1.push_back ( x ) ;
        s1.pop ( ) ;
    }
    v1 = w ( v1 ) ;
    for ( i = m - 1 ; i >= -1 ; i -- ) {
        while ( 1 ) {
            if ( s2.empty ( ) == true ) break ;
            x = s2.top ( ) ;
            s2.pop ( ) ;
            if ( s2.empty ( ) == true ) {
                s2.push ( x ) ;
                break ;
            }
            y = s2.top ( ) ;
            s2.pop ( ) ;
            if ( y == x + 1 ) {
                s2.push ( y + 1 ) ;
            }
            else {
                s2.push ( y ) ;
                s2.push ( x ) ;
                break ;
            }
        }
        if ( i != -1 && b[ i ] == '1' ) s2.push ( i ) ;
    }
    while ( s2.empty ( ) == false ) {
        x = s2.top ( ) ;
        v2.push_back ( x ) ;
        s2.pop ( ) ;
    }
    v2 = w ( v2 ) ;
    int mn ;
    mn = v1.size ( ) ;
    if ( v2.size ( ) < mn ) mn = v2.size ( ) ;
    for ( i = 0 ; i < mn ; i ++ ) {
        if ( v1[ i ] < v2[ i ] ) {
            cout << "<\n" ;
            return ;
        }
        if ( v1[ i ] > v2[ i ] ) {
            cout << ">\n" ;
            return ;
        }
    }
    if ( v1.size ( ) == v2.size ( ) ) {
        cout << "=\n" ;
        return ;
    }
    if ( mn == v1.size ( ) ) {
        cout << "<\n" ;
        return ;
    }
    else {
        cout << ">\n" ;
        return ;
    }

}