#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define s second
#define ll long long
#define f first
#define mp make_pair
#define pb push_back
vector<ll> v[N];
ll a[N],ans[N],sum[N],use[N],res;
void dfs(ll l)
{
    use[l]=1;
    sum[l]=a[l];
    ans[l]=-INT_MAX;
    int p=0,pref=0;
    for (ll i=0; i<v[l].size(); i++)
    if (use[v[l][i]]==0)
    {
        dfs(v[l][i]);
        p++;
        ll to=v[l][i];
        sum[l]+=sum[to];
        ans[l]=max(ans[l],ans[to]);
    } else pref=v[l][i];
    if (p>1)
    {
        ll ans1,ans2;
        ans1=-LONG_LONG_MAX;
        ans2=-LONG_LONG_MAX;
        for (int i=0; i<v[l].size(); i++)
        if (v[l][i]!=pref)
        {
            if (ans[v[l][i]]>ans1)
            {
                ans2=ans1;
                ans1=ans[v[l][i]];
            } else
            ans2=max(ans2,ans[v[l][i]]);
        }
        res=max(res,ans1+ans2);
    }
    ans[l]=max(ans[l],sum[l]);
}
int main()
{
    sync;
    #ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #else
    #endif
    ll n;
    cin>>n;
    for (ll i=1; i<=n; i++)
        cin>>a[i];
    for (ll i=1; i<n; i++)
    {
        ll l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    res=-LONG_LONG_MAX;
    dfs(1);
    if (res==-LONG_LONG_MAX)
        cout<<"Impossible"<<endl;
    else cout<<res<<endl;
}