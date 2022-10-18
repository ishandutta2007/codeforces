#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 998244353;

vector<int> v[N];
int kol[N];
ll fac[N];
ll sz[N];

void dfs(int l, int pr)
{
    sz[l]=1;
    for (int i=0; i<v[l].size(); i++)
        if (v[l][i]!=pr)
    {
        dfs(v[l][i],l);
        sz[l]+=sz[v[l][i]];
        kol[l]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    fac[0]=1;
    for (int i=1; i<=n; i++)
        fac[i]=(fac[i-1]*1ll*i)%MOD;
    dfs(1,0);
    ll ans=(n*1ll*fac[kol[1]])%MOD;
    for (int i=2; i<=n; i++)
    {
        ans=(ans*1ll*fac[kol[i]+1])%MOD;
    }
    cout<<ans<<endl;
}