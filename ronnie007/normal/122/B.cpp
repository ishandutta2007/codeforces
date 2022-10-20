#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    string a;
    int br4 = 0;
    int br7 = 0;
    int i;
    int n;
    cin>>a;
    n = a.size();
    for ( i = 0 ;i < n ; i ++ )
        {
        if(a[ i ] == '4') br4++;
        if(a[ i ] == '7') br7++;
        }
    if( br4 == 0 & br7 == 0 )
        {
        printf( "-1\n" );
        return 0;
        }
    if ( br4 >= br7 ) printf("4\n");
    else printf("7\n");
    return 0;
    }