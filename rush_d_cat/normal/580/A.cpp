#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[100000+10];
int main()
{
    int n,res=1;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=1;
    for(int i=1;i<=n-1;i++)
    {
        if(a[i]<=a[i+1]) ans++;
        else ans=1;
        res = max(ans,res);
    }
    cout<<res<<endl;
}