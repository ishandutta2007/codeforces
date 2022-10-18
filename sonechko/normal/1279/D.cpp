#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 998244353;

vector<int> v[N];
int kol[N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*1ll*step(x,y-1))%MOD;
    ll p=step(x,y/2);
    return (p*1ll*p)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        for (int j=1; j<=k; j++)
        {
            int x;
            cin>>x;
            v[i].pb(x);
            kol[x]++;
        }
    }
    ll ans=0;
    ll x=step(n,MOD-2);
    for (int i=1; i<=n; i++)
    {
        ll y=step(v[i].size(),MOD-2);
        for (int j=0; j<v[i].size(); j++)
        {
            ll t=kol[v[i][j]];
            ans=(ans+(t*1ll*y)%MOD)%MOD;
        }
    }
    ans=(ans*x)%MOD;
    ans=(ans*x)%MOD;
    cout<<ans<<"\n";
}