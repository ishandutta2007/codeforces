#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;

vector<int> v[N];
int d[20][N];
int deep[N],dp[N];
int ans[N];
int tin[N],tout[N],timee;
int sz[N];

void dfs(int l, int pr)
{
    timee++;
    sz[l]=1;
    tin[l]=timee;
    deep[l]=deep[pr]+1;
    d[0][l]=pr;
    for (int j=1; j<20; j++)
        d[j][l]=d[j-1][d[j-1][l]];
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) {dfs(v[l][j],l); sz[l]+=sz[v[l][j]];}
    tout[l]=timee;
}

bool pred(int l, int r)
{
    return (tin[l]<=tin[r]&&tout[r]<=tout[l]);
}

int lca(int l, int r)
{
    if (pred(l,r)) return l;
    if (pred(r,l)) return r;
    for (int j=19; j>=0; j--)
        if (d[j][l]!=0&&(!pred(d[j][l],r))) l=d[j][l];
    return d[0][l];
}

int predd(int l, int p)
{
    for (int i=19; i>=0; i--)
        if (p&(1<<i)) l=d[i][l];
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        int k=lca(l,r);
        if (l==r) cout<<n<<"\n"; else
        if (deep[l]==deep[r])
        {
            int p1=predd(l,deep[l]-deep[k]-1),p2=predd(r,deep[l]-deep[k]-1);
            cout<<n-sz[p1]-sz[p2]<<"\n";
        } else
        {
            if (deep[l]>deep[r]) swap(l,r);
            int p=deep[r]+deep[l]-2*deep[k];
            if (p%2==1) cout<<0<<"\n"; else
            {
                p/=2;
                int c1=predd(r,p);
                int c2=predd(r,p-1);
                cout<<sz[c1]-sz[c2]<<"\n";
            }
        }
    }
}
/**
15
1 2
1 3
1 4
2 5
2 6
2 7
5 8
6 9
9 14
14 15
7 10
4 13
3 11
3 12
1
8 4
**/