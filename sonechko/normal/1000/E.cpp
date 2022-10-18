#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;
const ll MOD = 1e18;
#define mod %MOD

int use[N],most[N];
vector<pair<int,int> > v[N];
vector<int> vv[N];
int tin[N],fup[N],tn;
int a[N],b[N],num[N];
int kol;
int kor,dist;

void dfs(int l, int pr)
{
    use[l]=1;
    tn++;
    tin[l]=tn;
    fup[l]=tn;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j].ff==pr) {} else
        if (use[v[l][j].ff]==0)
        {
            dfs(v[l][j].ff,l);
            fup[l]=min(fup[l],fup[v[l][j].ff]);
            if (fup[v[l][j].ff]>tin[l]) most[v[l][j].ss]=1;
        } else fup[l]=min(fup[l],tin[v[l][j].ff]);
}

void dfs(int l)
{
    num[l]=kol;
    use[l]=2;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j].ff]==1&&most[v[l][j].ss]==0) dfs(v[l][j].ff);
}

void dfs1(int l, int d)
{
    if (d>dist)
    {
        kor=l;
        dist=d;
    }
    use[l]=3;
    for (int j=0; j<vv[l].size(); j++)
        if (use[vv[l][j]]==2) dfs1(vv[l][j],d+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(mp(r,i));
        v[r].pb(mp(l,i));
        a[i]=l;
        b[i]=r;
    }
    dfs(1,0);
    for (int i=1; i<=n; i++)
        if (use[i]==1) {kol++; dfs(i);}
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            if (most[v[i][j].ss]==1)
            {
                vv[num[i]].pb(num[v[i][j].ff]);
            }
    }
    kor=1;
    dist=0;
    dfs1(1,0);
    int p=kor;
    kor=1;
    dist=0;
    for (int i=1; i<=n; i++)
        use[i]=2;
    dfs1(p,0);
    cout<<dist<<endl;
}