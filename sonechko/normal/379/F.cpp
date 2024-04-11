#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

vector<int> v[N];
int a[N];
int d[20][N],tin[N],tout[N],timee,sz[N];
int gl[N],num[N],nn;
int deep[N];
int n;

void dfs(int l, int pr)
{
    d[0][l]=pr;
    deep[l]=deep[pr]+1;
    timee++;
    sz[l]=1;
    tin[l]=timee;
    for (int j=1; j<19; j++)
        d[j][l]=d[j-1][d[j-1][l]];
    for (int j=0; j<v[l].size(); j++)
    {
        dfs(v[l][j],l);
        sz[l]+=sz[v[l][j]];
    }
    tout[l]=timee;
}

inline bool pred(int l, int r)
{
    if (tin[l]<=tin[r]&&tout[r]<=tout[l]) return 1;
    return 0;
}

inline int lca(int l, int r)
{
    if (pred(l,r)) return l;
    if (pred(r,l)) return r;
    for (int j=19; j>=0; j--)
        if (d[j][l]!=0&&(!pred(d[j][l],r))) l=d[j][l];
    return d[0][l];
}

inline int dist(int l, int r)
{
    int p=lca(l,r);
    return deep[l]+deep[r]-deep[p]*2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    v[1].pb(2);
    v[1].pb(3);
    v[1].pb(4);
    n=4;
    for (int i=1; i<=q; i++)
    {
        int l;
        cin>>l;
        a[i]=l;
        v[l].pb(n+1);
        v[l].pb(n+2);
        n+=2;
    }
    dfs(1,0);
    n=4;
    int x=2,y=3;
    for (int i=1; i<=q; i++)
    {
        n++;
        //cout<<dist(x,y)<<" "<<dist(x,n)<<" "<<dist(y,n)<<endl;
        if (dist(x,n)>dist(x,y)) y=n;
        if (dist(y,n)>dist(x,y)) x=n;
        n++;
        //cout<<dist(x,y)<<" "<<dist(x,n)<<" "<<dist(y,n)<<endl;
        if (dist(x,n)>dist(x,y)) y=n;
        if (dist(n,y)>dist(x,y)) x=n;
        cout<<dist(x,y)<<"\n";
    }
}