#include<bits/stdc++.h>
using namespace std;


#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 11;
int v[N*4],w[N*4];
void push(int i, int l, int r, int mid)
{
    if (w[i]==0) return;
    w[i*2]^=1;
    v[i*2]=(mid-l+1)-v[i*2];
    w[i*2+1]^=1;
    v[i*2+1]=(r-mid)-v[i*2+1];
    w[i]=0;
}
void update(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr)
    {
        w[i]^=1;
        v[i]=(r-l+1)-v[i];
        return;
    }
    if (l>tr||r<tl) return;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    update(i*2,l,mid,tl,tr);
    update(i*2+1,mid+1,r,tl,tr);
    v[i]=v[i*2]+v[i*2+1];
}
int sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (l>tr||r<tl) return 0;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    return sum(i*2,l,mid,tl,tr)+sum(i*2+1,mid+1,r,tl,tr);
}

vector<int> vv[N];
vector<int> g;
int tt[N];
int tin[N],tout[N];
void dfs(int l)
{
    tin[l]=g.size();
    g.pb(l);
    for (int i=0; i<vv[l].size(); i++)
        dfs(vv[l][i]);
    tout[l]=g.size()-1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    g.pb(0);
    for (int i=2; i<=n; i++)
    {
        int l;
        cin>>l;
        vv[l].pb(i);
    }
    dfs(1);
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        if (x==1) update(1,1,n,tin[i],tin[i]);
    }
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        string s;
        int l;
        cin>>s>>l;
        if (s=="get") cout<<sum(1,1,n,tin[l],tout[l])<<"\n";
        else update(1,1,n,tin[l],tout[l]);
    }
}