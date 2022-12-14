#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std ;
int main ()
{
    ll n,q;
    cin>>n>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if ((x+y)%2==0)
        {
            ll num=((x-1)/2)*n;
            if ((x-1)%2)
                num+=n/2+n%2;
            num+=(y-1)/2;
            cout<<num+1<<endl;
        }
        else
        {
            ll num=((x-1)/2)*n;
            if ((x-1)%2)
                num+=n/2;
            num+=(y-1)/2;
            cout<<n*n/2+num+1+n%2<<endl;
        }
    }
}