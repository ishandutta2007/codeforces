#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

vector<int> v1[N],v2[N],vv1[N],vv2[N];
int x1[N],y1[N],x2[N],y2[N];
int ans[N];
int v[N*4];

int mini(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return 2e9;
    int mid=(l+r)/2;
    return min(mini(i+i,l,mid,tl,tr),mini(i+i+1,mid+1,r,tl,tr));
}

void build(int i, int l, int r)
{
    if (l==r) {v[i]=0; return;}
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v[i]=0;
}

void update(int i, int l, int r, int x, int t)
{
    if (l==r) {v[i]=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    v[i]=min(v[i+i],v[i+i+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        v1[l].pb(r);
        v2[r].pb(l);
    }
    for (int i=1; i<=q; i++)
    {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        vv1[x2[i]].pb(i);
        vv2[y2[i]].pb(i);
    }
    build(1,1,m);
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<v1[i].size(); j++)
            update(1,1,m,v1[i][j],i);
        for (int j=0; j<vv1[i].size(); j++)
        {
            int num=vv1[i][j];
            if (mini(1,1,m,y1[num],y2[num])>=x1[num])
                ans[num]=1;
        }
    }
    build(1,1,n);
    for (int i=1; i<=m; i++)
    {
        for (int j=0; j<v2[i].size(); j++)
            update(1,1,n,v2[i][j],i);
        for (int j=0; j<vv2[i].size(); j++)
        {
            int num=vv2[i][j];
            if (mini(1,1,n,x1[num],x2[num])>=y1[num]) ans[num]=1;
        }
    }
    for (int i=1; i<=q; i++)
        if (ans[i]) cout<<"YES\n"; else cout<<"NO\n";
}