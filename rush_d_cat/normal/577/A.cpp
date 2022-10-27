#include<iostream>
using namespace std;
typedef __int64 ll;
int main()
{
    ll n,x,l,r;cin>>n>>x;
    int cnt=0;
    for(ll i=1;i<=n;i++)
    {
        l=i;
        r=n*i;
        if(l<=x&&r>=x&&x%i==0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}