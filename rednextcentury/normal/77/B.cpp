# include<iostream>
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long double a,b;
        cin>>a>>b;
        long double ans=2*b*a-2*b*b;
        if (b-a/4 >0 && 4*b-a>0)
            ans+=(b-a/4)*(4*b-a)/2;
        if (a>0 && b>0)
            ans/=2*a*b;
        if (b==0)
            ans=1.0;
        else if (a==0)
            ans=0.5;
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
}