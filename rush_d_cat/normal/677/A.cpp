#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int a[2000];
int main()
{
    int n,h,res=0;cin>>n>>h;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>h) res+=2;
        else res+=1;
    }
    cout<<res<<endl;
    return 0;
}