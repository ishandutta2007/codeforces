#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a,b,tmp,a_,b_;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        if(tmp==1) a = i;
        if(tmp==n) b = i;
    }
    a_ = min(a,b);
    b_ = max(a,b);
    cout<<max(n-a_,b_-1)<<endl;
    return 0;
}