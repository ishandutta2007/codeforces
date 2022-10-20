#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int a,b,r;
    cin>>a>>b>>r;
    if(2*r>b || 2*r>a)cout<<"Second\n";
    else cout<<"First\n";
    return 0;
    }