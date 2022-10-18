#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int tin[N],tout[N],timee;
int pred[N],num[N];
int ans[N];
vector<pair<int,int> > v[N];

void dfs(int l, int pr)
{
    pred[l]=pr;
    timee++;
    tin[l]=timee;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j].ff!=pr)
    {
        int to=v[l][j].ff;
        dfs(to,l);
        num[to]=v[l][j].ss;
    }
    tout[l]=timee;
}

bool predok(int l, int r)
{
    if (tin[l]<=tin[r]&&tout[r]<=tout[l]) return 1;
    return 0;
}

void rec(int l, int r, int x)
{
    int u=0;
    while (predok(l,r)==0)
    {
        if (ans[num[l]]==x) u=1; else
        if (ans[num[l]]==0) {ans[num[l]]=x; u=1;}
        l=pred[l];
    }
    while (r!=l)
    {
        if (ans[num[r]]==x) u=1; else
        if (ans[num[r]]==0) {ans[num[r]]=x; u=1;}
        r=pred[r];
    }
    if (u==0)
    {
        cout<<-1;
        exit(0);
    }
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
        v[l].pb(mp(r,i));
        v[r].pb(mp(l,i));
    }
    dfs(1,0);
    vector<pair<int,pair<int,int> > > vv;
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        vv.pb(mp(k,mp(l,r)));
    }
    sort(vv.begin(),vv.end());
    for (int j=vv.size()-1; j>=0; j--)
    {
        int l=vv[j].ss.ff,r=vv[j].ss.ss,x=vv[j].ff;
        rec(l,r,x);
    }
    for (int i=1; i<n; i++)
        if (ans[i]==0) cout<<1<<" "; else cout<<ans[i]<<" ";
}