#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 2e5 + 11;

vector<pair<int,int> > v[N];
map<int, ll> mt[N];
set<pair<ll,pair<int,int> > > st;
int k;
ll mx;

void up(int l, int r, ll w)
{
    if (l>r) swap(l,r);
    if (l==r) return;
    if (mt[l][r]==0||mt[l][r]>w)
    {
        st.erase(mp(mt[l][r],mp(l,r)));
        mt[l][r]=w;
        st.insert(mp(mt[l][r],mp(l,r)));
    }
    while (st.size()>k)
    {
        pair<ll,pair<int,int> > p=*st.rbegin();
        st.erase(p);
    }
    if ((int)st.size()==k) mx=(*st.rbegin()).ff;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mx=2e18;
    int n,m;
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        int l,r,w;
        cin>>l>>r>>w;
        v[l].pb(mp(r,w));
        v[r].pb(mp(l,w));
        up(l,r,w);
    }
    while (k>0)
    {
        pair<ll,pair<int,int> > p=*st.begin();
        st.erase(p);
        k--;
        ///cout<<p.ff<<" "<<p.ss.ff<<" "<<p.ss.ss<<endl;
        if (k==0) return cout<<p.ff, 0;
        int l=p.ss.ff;
        int r=p.ss.ss;
        ll w=p.ff;
        if (l>r) swap(l,r);
        for (int j=0; j<v[l].size(); j++)
            if (v[l][j].ss*1ll+w<mx) up(v[l][j].ff,r,v[l][j].ss*1ll+w);
        for (int j=0; j<v[r].size(); j++)
            if (v[r][j].ss*1ll+w<mx) up(v[r][j].ff,l,v[r][j].ss*1ll+w);
    }
}