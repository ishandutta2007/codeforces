#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        while (n>0)
        {
            if (n%k==0) {ans++; n/=k;} else
            {
                ll t=n%k;
                ans+=t;
                n-=t;
            }
        }
        cout<<ans<<"\n";
    }
}