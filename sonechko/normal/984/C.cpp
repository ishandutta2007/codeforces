#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define ll long long

const int N = 100 + 11;

ll mult(ll a, ll b, ll mod) {
    ll q = (ld) a * b / mod;
    ll r = a * b - q * mod;
    return (r + 8 * mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        l%=r;
        k%=r;
        ll x=l;
        int gg=0;
        for (int j=0; j<64; j++)
        {
            x=mult(x,k,r);
            if (!x) gg=1;
        }
        if (gg==0) cout<<"Infinite\n"; else cout<<"Finite"<<"\n";
    }
}