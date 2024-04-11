#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 +  11;
const int MOD = 1e9 + 7;

ll tt,kol[N];
int use[N];
vector<int> v[N];
ll st[N];

void dfs(int l)
{
    use[l]=tt;
    kol[tt]++;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    for (int i=1; i<n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if (k==0)
        {
            v[l].pb(r);
            v[r].pb(l);
        }
    }
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        tt++;
        dfs(i);
    }
    ll ans=0;
    st[0]=1;
    for (int i=1; i<=k; i++)
        st[i]=(st[i-1]*1ll*n)%MOD;
    for (int i=1; i<=tt; i++)
    {
        ll c=1;
        for (ll t=1; t<k; t++)
        {
            c=(c*1ll*kol[i])%MOD;
            ll p=c;
            p=(p*1ll*(n-kol[i]))%MOD;
            p=(p*1ll*st[k-t-1])%MOD;
            ans=(ans+p)%MOD;
        }
    }
    cout<<ans<<endl;
}