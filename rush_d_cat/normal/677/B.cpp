#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;
typedef __int64 ll;
ll a[100000+10];
int main()
{
    ll n,h,k,res=0;cin>>n>>h>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll tmp=0;
    for(int i=1;i<=n;i++)
    {
        if(tmp+a[i]<=h)
        {
            tmp+=a[i];
        }else{
            res += (tmp-h+a[i]+k-1)/k;
            tmp -= k*((tmp-h+a[i]+k-1)/k);
            if(tmp<0) tmp=0;
            tmp += a[i];
        }
    }
    res += (tmp+k-1)/k;
    cout<<res<<endl;
    return 0;
}