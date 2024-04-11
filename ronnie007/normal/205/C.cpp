#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;


unsigned long long f(unsigned long long x)
    {
    if(x<10)return x;

    unsigned long long  k=x/10;
    int e=x%10;
    int lst;
    while(x!=0)
        {
        lst=x%10;
        x=x/10;
        }
    if(lst<=e)return k+9;
    return k+8;
    }

int main()
    {
    unsigned long long a,b;
    unsigned long long ans;
    cin>>a>>b;
    ans=f(b)-f(a-1);
    cout<<ans<<"\n";
    return 0;
    }