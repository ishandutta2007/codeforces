#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

bool steps(ll x)
{
    while (x%2==0)
        x/=2;
    if (x==1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        ll x;
        cin>>x;
        if (steps(x+1))
        {
            ll ans=1;
            for (int j=2; j<=(int)sqrt(x); j++)
                if (x%j==0) {ans=x/j; break;}
            cout<<ans<<"\n";
        } else
        {
            int ans=0;
            for (int p=26; p>=1; p--)
                if (1ll<<(p-1)<=x) {ans=(1ll<<p)-1; break;}
            cout<<ans<<"\n";
        }
    }
}
/**
111101

1 -      
0 -     

xor - 1   
and - 1   

t
a^b=ct
a&b=dt

**/