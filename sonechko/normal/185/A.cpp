#include<bits/stdc++.h>

#define ll long long
const int MOD = 1e9 + 7;
#define mod % MOD

using namespace std;

ll step(ll l, ll r)
{
    ll ans=1,k=l;
    while (r>0)
    {
        if (r%2==0)
        {
            k=(k*k) mod;
            r=r/2;
        } else
        {
            ans=(ans*k)mod;
            r=r-1;
        }
    }
    return ans;
}

int main()
{
     ll n,l,r;
     cin>>n;
     l = step(2,n);
     r = ((l*(l+1))mod*step(2,MOD-2))mod;
     cout<<r;
}