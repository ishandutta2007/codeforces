#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD

vector<int> v[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        a[i]=l;
        v[l%m].pb(i);
    }
    int cc=n/m;
    ll ans=0;
    vector<pair<int,int> > vv;
    for (int d=0; d<=m-1; d++)
    {
        //cout<<d<<" "<<v[d].size()<<endl;
        while (v[d].size()>cc)
        {
            int l=v[d].back();
            v[d].pop_back();
            vv.pb(mp(l,d));
        }
        while (v[d].size()<cc&&vv.size()>0)
        {
            pair<int,int> p=vv.back();
            int g=(d-p.ss+m)%m;
            ans+=g;
            a[p.ff]+=g;
            //cout<<p.ff<<"+="<<g<<endl;
            v[d].pb(p.ff);
            vv.pop_back();
        }
        //cout<<d<<" "<<v[d].size()<<endl;
    }
    for (int d=0; d<=m-1; d++)
    {
        //cout<<d<<" "<<v[d].size()<<endl;
        while (v[d].size()>cc)
        {
            int l=v[d].back();
            v[d].pop_back();
            vv.pb(mp(l,d));
        }
        while (v[d].size()<cc&&vv.size()>0)
        {
            pair<int,int> p=vv.back();
            int g=(d-p.ss+m)%m;
            ans+=g;
            a[p.ff]+=g;
            //cout<<p.ff<<"+="<<g<<endl;
            v[d].pb(p.ff);
            vv.pop_back();
        }
        //cout<<d<<" "<<v[d].size()<<endl;
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}