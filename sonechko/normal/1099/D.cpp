#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int p[N];
vector<int> v[N];
ll s[N],a[N];

void dfs(int l, int r)
{
    if (r==1)
    {
        a[l]=s[l]-s[p[l]];
    } else
    {
        ll t=2e18;
        for (int j=0; j<v[l].size(); j++)
            t=min(t,s[v[l][j]]);
        if (v[l].size()==0) a[l]=0;
        else
        if (t<s[p[l]]) {cout<<-1<<endl; exit(0);}
        else a[l]=t-s[p[l]];
        s[l]=s[p[l]]+a[l];
    }
    //cout<<l<<" - "<<a[l]<<endl;
    for (int j=0; j<v[l].size(); j++)
        dfs(v[l][j],1-r);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        v[l].pb(i);
        p[i]=l;
    }
    for (int i=1; i<=n; i++)
        cin>>s[i];
    dfs(1,1);
    ll ans=0;
    for (int i=1; i<=n; i++)
        ans+=a[i];
    cout<<ans<<endl;
}