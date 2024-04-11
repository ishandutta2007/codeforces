#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

ll a[N],b[N];
ll ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll x,y;
    cin>>n>>x>>y;
    vector<pair<ll,int> > v;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        v.pb(mp(a[i],-i));
        v.pb(mp(b[i],i));
        ans=(ans+(b[i]-a[i])*y)%MOD;
    }
    sort(v.begin(),v.end());
    multiset<ll> st;
    for (int j=0; j<v.size(); j++)
    if (v[j].ss<0)
    {
        ll l=v[j].ff;
        if ((int)st.size()==0) ans=(ans+x)%MOD; else
        {
            ll p=*st.rbegin();
            if (x<y*(l-p)) ans=(ans+x)%MOD; else
            {
                ans=(ans+y*(l-p))%MOD;
                st.erase(st.find(p));
            }
        }
    } else
    {
        st.insert(v[j].ff);
    }
    cout<<ans<<endl;
}
/**
1 2
2 4
4 10
5 9
10 11
**/