#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

int c1[N],c2[N];
int v[N*4],w[N*4];
vector<pair<int,int> > vv[N];

void build(int i, int l, int r)
{
    w[i]=0;
    if (l==r)
    {
        v[i]=-c2[l];
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=max(v[i+i],v[i+i+1]);
}

void push(int i)
{
    v[i+i]+=w[i];
    v[i+i+1]+=w[i];
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int x)
{
    if (tl<=l&&r<=tr)
    {
        w[i]+=x;
        v[i]+=x;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,x);
    update(i+i+1,mid+1,r,tl,tr,x);
    v[i]=max(v[i+i],v[i+i+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,p;
    cin>>n>>m>>p;
    for (int i=1; i<=1000000; i++)
    {
        c1[i]=2e9;
        c2[i]=2e9;
    }
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        c1[l]=min(c1[l],r);
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        c2[l]=min(c2[l],r);
    }
    build(1,1,1000000);
    for (int i=1; i<=p; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        vv[x].pb(mp(y,z));
    }
    int ans=-2e9;
    for (int i=1; i<=1000000; i++)
    {
        if (c1[i]!=2e9)
        {
            ///cout<<i<<": "<<v[1]<<"-"<<c1[i]<<endl;
            ans=max(ans,v[1]-c1[i]);
        }
        for (int j=0; j<vv[i].size(); j++)
            update(1,1,1000000,vv[i][j].ff+1,1000000,vv[i][j].ss);
    }
    cout<<ans;
}