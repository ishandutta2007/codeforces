#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long n,k;
    cin>>n>>k;
    long long x=n/2;
    if(n%2==1)x++;
    if(k<=x)
        {
        cout<<1+(k-1)*2<<"\n";
        }
    else
        {
        cout<<(k-x)*2<<"\n";
        }
    return 0;
    }