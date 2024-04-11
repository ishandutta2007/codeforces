#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 1e6 + 11;

ll kk[N];
vector<ll> v[N];
pair<int,int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        kk[l]++;
        a[i]=mp(l,r);
    }
    ll ans=1e18;
    for (int ii=1; ii<=n; ii++)
    {
        for (int i=1; i<=m; i++)
        {
            v[i].clear();
            kk[i]=0;
        }
        for (int i=1; i<=n; i++)
        {
            v[a[i].ff].pb(a[i].ss);
            kk[a[i].ff]++;
        }
        for (int i=2; i<=m; i++)
        {
            sort(v[i].begin(),v[i].end());
            reverse(v[i].begin(),v[i].end());
        }
        ll res=0;
        for (int i=2; i<=m; i++)
        {
            while (kk[i]>=ii)
            {
                kk[i]--;
                kk[1]++;
                res+=v[i].back();
                v[i].pop_back();
            }
        }
        vector<int> vv;
        for (int i=2; i<=m; i++)
        {
            for (int j=0; j<v[i].size(); j++)
                vv.pb(v[i][j]);
        }
        sort(vv.begin(),vv.end());
        reverse(vv.begin(),vv.end());
        while (kk[1]<ii)
        {
            res+=vv.back();
            vv.pop_back();
            kk[1]++;
        }
        if (kk[1]==ii) ans=min(ans,res);
    }
    cout<<ans<<endl;
}