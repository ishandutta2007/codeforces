# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
using namespace std;
int main()
{
    int n,m;
    int ans=0;
    cin>>n>>m;
    if (n>m)
        swap(n,m);
    if (n>2)
    {
        cout<<(n*m+1)/2<<endl;;
    }
    else if (n==2)
    {
        cout<<2*(2*(m/4)+min(2,m%4))<<endl;
    }
    else
    {
        cout<<m<<endl;
    }
}