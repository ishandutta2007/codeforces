#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin>>n;
    for (ll i=0; i<n; i++)
    {
        ll m;
        cin>>m;
        ll l=m*(m+1)>>1;
        ll k=1;
        while (k<=m)
        {
            l-=k*2;
            k=k*2;
        }
        cout<<l<<endl;

    }
}