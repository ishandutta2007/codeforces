#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back


const int N = 1e6 + 11;

ll a[N];
vector<pair<int,ll> > v[N];
pair<ll,int> dp1[N],dp2[N];
ll ans=0;

void dfs1(int l, int pr)
{
    dp1[l]=mp(0,l);
    dp2[l]=mp(0,l);
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j].ff!=pr)
    {
        int to=v[l][j].ff;
        ll p=v[l][j].ss;
        dfs1(to,l);
        if (dp1[to].ff-p>dp1[l].ff) {dp2[l]=dp1[l]; dp1[l]=mp(dp1[to].ff-p,to);} else
        if (dp1[to].ff-p>dp2[l].ff) dp2[l]=mp(dp1[to].ff-p,to);
    }
    dp1[l].ff+=a[l];
    dp2[l].ff+=a[l];
}


void dfs2(int l, int pr, ll maxx)
{
    ans=max(ans,maxx);
    //cout<<l<<" - "<<maxx<<endl;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j].ff!=pr)
    {
        int to=v[l][j].ff;
        ll p=v[l][j].ss;
        ll max2=maxx;
        if (to==dp1[l].ss) max2=max(max2,dp2[l].ff); else
        max2=max(max2,dp1[l].ff);
        max2-=p;
        if (max2<0) max2=a[to]; else max2+=a[to];
        dfs2(to,l,max2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        v[l].pb(mp(r,k));
        v[r].pb(mp(l,k));
    }
    dfs1(1,0);
    dfs2(1,0,a[1]);
    cout<<ans<<endl;
}