#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    vector<pair<ll,ll> > vv;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        vv.pb(mp(b[i],i));
    }
    sort(vv.begin(),vv.end());
    int pos=0;
    for (int jj=1; jj<=m; jj++)
    {
        ll t,d;
        cin>>t>>d;
        ll ans=0;
        ll p=min(a[t],d);
        a[t]-=p;
        ans+=p*1ll*b[t];
        d-=p;
        while (d>0)
        {
            while (pos<vv.size()&&a[vv[pos].ss]==0)
                pos++;
            if (pos==(int)vv.size()) {ans=0; break;}
            t=vv[pos].ss;
            p=min(a[t],d);
            a[t]-=p;
            ans+=p*1ll*b[t];
            d-=p;
        }
        cout<<ans<<"\n";
    }
}