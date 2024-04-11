#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long a,b,c;
    long long d;
    long long i=1;
    cin>>a>>b>>c;
    d=a*b*c;
    while(i*i<d)i++;
    long long e,f,g;
    e=i/a;
    f=i/b;
    g=i/c;
    cout<<4*(e+f+g)<<"\n";
    return 0;
    }