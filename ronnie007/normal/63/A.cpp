#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int n;
    string name[107];
    string st[107];
    cin>>n;
    int i;
    for(i = 0 ; i < n ; i ++)
        {
        cin >> name[ i ] >> st[ i ];
        }
    for(i = 0 ; i < n ; i ++)
        {
        if(st[ i ] == "rat")cout << name[ i ] << "\n";
        }
    for(i = 0 ; i < n ; i ++)
        {
        if(st[ i ] == "woman" || st[ i ] == "child")cout << name[ i ] << "\n";
        }
    for(i = 0 ; i < n ; i ++)
        {
        if(st[ i ] == "man")cout << name[ i ] << "\n";
        }
    for(i = 0 ; i < n ; i ++)
        {
        if(st[ i ] == "captain")cout << name[ i ] << "\n";
        }
    return 0;
    }