#include<iostream>
#include<math.h>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int n,a[100+5],b[100+5];
int main()
{
    cin>>n;int pos=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) b[++pos]=i;
    }
    ll res=1;

    if(pos==0)
    {
        res=0;
    }
    else
    if(pos==1)
    {
        res=1;
    }
    else
    {
        for(int i=2;i<=pos;i++)
            res *= (b[i]-b[i-1]);
    }
    cout<<res<<endl;
    return 0;
}