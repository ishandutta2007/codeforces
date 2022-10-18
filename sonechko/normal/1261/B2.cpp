#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;

int a[N];
vector<pair<int,int> > v[N];
int ans[N];
int w[N*4];

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {w[i]+=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    w[i]=w[i+i]+w[i+i+1];
}

int get(int i, int l, int r, int x)
{
    if (w[i]<x) return -1;
    if (l==r) return l;
    int mid=(l+r)/2;
    int c=get(i+i,l,mid,x);
    if (c!=-1) return c;
    return get(i+i+1,mid+1,r,x-w[i+i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv.pb(mp(-a[i],i));
    }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int k,pos;
        cin>>k>>pos;
        v[k].pb(mp(pos,i));
    }
    sort(vv.begin(),vv.end());
    for (int i=1; i<=n; i++)
    {
        update(1,1,n,vv[i-1].ss,1);
        for (int j=0; j<v[i].size(); j++)
        {
            ans[v[i][j].ss]=a[get(1,1,n,v[i][j].ff)];
        }
    }
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<"\n";
}
/**
x*y*z
**/