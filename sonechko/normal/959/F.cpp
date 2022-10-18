#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 3e6 + 11;

int a[N];
vector<pair<int,int> > que[N];
bool mt[N];
int res[N];
vector<int> vv;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=q; i++)
    {
        int l,x;
        cin>>l>>x;
        que[l].pb(mp(x,i));
    }
    mt[0]=1;
    vv.pb(0);
    ll ans=1;
    for (int i=1; i<=n; i++)
    {
        if (mt[a[i]]==1) ans=(ans*2ll)mod; else
        {
            int d=vv.size();
            for (int j=0; j<d; j++)
            {
                mt[(vv[j]^a[i])]=1;
                vv.pb((vv[j]^a[i]));
            }
        }
        for (int j=0; j<que[i].size(); j++)
            if (mt[que[i][j].ff]!=0) res[que[i][j].ss]=ans;
    }
    for (int i=1; i<=q; i++)
        cout<<res[i]<<"\n";
}