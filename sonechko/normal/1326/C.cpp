#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;
const ll MOD = 998244353;

ll a[N];
int pos[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    ll ans=0;
    vector<int> v;
    for (int i=n-k+1; i<=n; i++)
    {
        v.pb(pos[i]);
        ans+=1ll*i;
    }
    sort(v.begin(),v.end());
    ll res=1;
    for (int i=1; i<v.size(); i++)
    {
        ll kol=v[i]-v[i-1];
        res=(res*1ll*kol)%MOD;
    }
    cout<<ans<<" "<<res;
}