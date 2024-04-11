#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;
const ll MOD = 1e18;
#define mod %MOD

ll n,k;
int ans=0;
vector<ll> vv;

bool good(ll c)
{
    while (c>0)
    {
        if (c%10==4||c%10==7) {} else return false;
        c/=10;
    }
    return true;
}

void dfs(ll l)
{
    if (l>n) return;
    if (l>=1)
    {
        if (l<n-15ll) {//cout<<l<<" - good"<<endl;
         ans++;} else
        {
            ll pos=l-max(1ll,(n-15));
            //cout<<l<<" - "<<pos<<" - "<<vv[pos]<<endl;
            if (good(vv[pos])) ans++;
        }
    }
    dfs(l*10ll+4ll);
    dfs(l*10ll+7ll);
}

ll kol_perm(ll x)
{
    ll k=1;
    for (ll i=1; i<=x; i++)
        k*=i;
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if (n<=15&&kol_perm(n)<k) {cout<<"-1"<<endl; return 0;}
    vector<ll> v,dd;
    for (int i=max(1ll,n-15ll); i<=n; i++)
        v.pb(i);
    int t=min(16ll,n);
    for (int i=1; i<=t; i++)
    {
        int c=0;
        for (ll j=0; j<v.size(); j++)
        if (kol_perm(t-i)*(j+1)>=k) {vv.pb(v[j]); c=j; k-=kol_perm(t-i)*j; break;}
        dd.clear();
        for (int j=0; j<c; j++)
            dd.pb(v[j]);
        for (int j=c+1; j<v.size(); j++)
            dd.pb(v[j]);
        v=dd;
    }
    //for (int j=0; j<vv.size(); j++)
    //    cout<<vv[j]<<" ";
    //cout<<endl;
    dfs(0);
    cout<<ans<<endl;
}