#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

int a[N],d[N],sz[N];


int get(int l)
{
    if (l==d[l]) return l;
    return d[l]=get(d[l]);
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    for (int i=1; i<=n; i++)
    {
        d[i]=0;
        sz[i]=0;
    }
    ll ans=0;
    for (int i=0; i<v.size(); i++)
    {
        int pos=v[i].ss;
        if (d[pos-1]==0&&d[pos+1]==0)
        {
            d[pos]=pos;
            sz[pos]=1;
            ans+=v[i].ff*1ll;
        } else
        if (d[pos-1]==0)
        {
            int c=get(pos+1);
            d[pos]=c;
            sz[c]++;
            ans+=sz[c]*1ll*v[i].ff;
        } else
        if (d[pos+1]==0)
        {
            int c=get(pos-1);
            d[pos]=c;
            sz[c]++;
            ans+=sz[c]*1ll*v[i].ff;
        } else
        {
            int c1=get(pos-1);
            int c2=get(pos+1);
            ans+=(sz[c1]+1)*1ll*(sz[c2]+1)*1ll*v[i].ff;
            d[c1]=pos;
            d[c2]=pos;
            d[pos]=pos;
            sz[pos]=sz[c1]+sz[c2]+1;
        }
    }

    reverse(v.begin(),v.end());
    for (int i=1; i<=n; i++)
    {
        d[i]=0;
        sz[i]=0;
    }
    for (int i=0; i<v.size(); i++)
    {
        int pos=v[i].ss;
        if (d[pos-1]==0&&d[pos+1]==0)
        {
            d[pos]=pos;
            sz[pos]=1;
            ans-=v[i].ff*1ll;
        } else
        if (d[pos-1]==0)
        {
            int c=get(pos+1);
            d[pos]=c;
            sz[c]++;
            ans-=sz[c]*1ll*v[i].ff;
        } else
        if (d[pos+1]==0)
        {
            int c=get(pos-1);
            d[pos]=c;
            sz[c]++;
            ans-=sz[c]*1ll*v[i].ff;
        } else
        {
            int c1=get(pos-1);
            int c2=get(pos+1);
            ans-=(sz[c1]+1)*1ll*(sz[c2]+1)*1ll*v[i].ff;
            d[c1]=pos;
            d[c2]=pos;
            d[pos]=pos;
            sz[pos]=sz[c1]+sz[c2]+1;
        }
    }
    cout<<ans;
}