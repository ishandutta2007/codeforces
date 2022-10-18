#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

ll step(ll x, ll y)
{
    x%=MOD;
    if (y==0) return 1;
    if (y%2==1) return (x*step(x,y-1))%MOD;
    ll p=step(x,y/2);
    return (p*p)%MOD;
}

ll get(ll x, ll n)
{
    ll y=1;
    ll res=1;
    while (y<=n)
    {
        ll k=n/y;
        ///(n>=y*x)
        ///n/x>=y
        if (n/x+1>=y) k-=n/(y*x);
        res=(res*step(y,k))%MOD;
        if (n/x+1<y) break;
        y*=x;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x,n;
    cin>>x>>n;
    vector<int> p;
    for (int d=2; d*d<=x; d++)
    {
        if (x%d==0) p.pb(d);
        while (x%d==0)
            x/=d;
    }
    if (x>1) p.pb(x);
    ll ans=1;
    for (int j=0; j<p.size(); j++)
        ans=(ans*get(p[j],n))%MOD;
    cout<<ans;
}
/**
2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
0 1 0 2 0 1 0 3 0 1  0  2  0  1  0  4

**/