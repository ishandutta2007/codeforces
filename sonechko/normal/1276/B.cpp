#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

vector<int> v[N];
int u[2][N];

void dfs(int l, int nott, int k)
{
    u[k][l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (u[k][v[l][j]]==0&&v[l][j]!=nott) dfs(v[l][j],nott,k);
}

void up()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for (int i=1; i<=n; i++)
    {
        v[i].clear();
        u[0][i]=0;
        u[1][i]=0;
    }
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(x,y,0);
    dfs(y,x,1);
    ll k1=0,k2=0;
    for (int i=1; i<=n; i++)
        if (u[0][i]==1&&u[1][i]==0&&i!=x&&i!=y) k1++; else
        if (u[1][i]==1&&u[0][i]==0&&i!=x&&i!=y) k2++;
    cout<<k1*k2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}