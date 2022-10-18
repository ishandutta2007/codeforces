#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long

const int N = 1e5 + 11;

int a[N];
vector<pair<int,int> > v[N];
int d[N*4];
vector<int> vv[N*4];
int ans[N*3];

inline void build(int i, int l, int r)
{
    if (l==r)
    {
        vv[i].pb(a[l]);
        d[i]=2e9;
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    vv[i].resize(vv[i+i].size()+vv[i+i+1].size());
    merge(vv[i+i].begin(),vv[i+i].end(),vv[i+i+1].begin(),vv[i+i+1].end(),vv[i].begin());
    d[i]=2e9;
}

inline int get(int i, int x)
{
    int l=0,r=vv[i].size()-1;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (vv[i][mid]<x) l=mid; else r=mid;
    }
    return min(abs(vv[i][l]-x),abs(vv[i][r]-x));
}

inline int up(int i, int l, int r, int tl, int tr, int x, int mini)
{
    if (get(i,x)>=mini) return mini;
    if (tl>r||l>tr) return mini;
    if (l==r)
    {
        d[i]=min(d[i],abs(a[l]-x));
        return min(mini,d[i]);
    }
    int mid=(l+r)/2;
    int c=up(i+i+1,mid+1,r,tl,tr,x,mini);
    int cc=up(i+i,l,mid,tl,tr,x,min(mini,c));
    d[i]=min(d[i+i],d[i+i+1]);
    return min(mini,min(c,cc));
}

inline int mini(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return d[i];
    if (tl>r||l>tr) return 2e9;
    int mid=(l+r)/2;
    return min(mini(i+i,l,mid,tl,tr),mini(i+i+1,mid+1,r,tl,tr));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[r].pb(mp(l,i));
    }
    build(1,1,n);
    for (int i=1; i<=n; i++)
    {
        int d=up(1,1,n,1,i-1,a[i],2e9);
        for (int j=0; j<v[i].size(); j++)
            ans[v[i][j].ss]=mini(1,1,n,v[i][j].ff,i);
    }
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<"\n";
}