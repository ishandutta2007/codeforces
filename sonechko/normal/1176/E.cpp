#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int gl[N];
vector<int> v[N];
int kol[N],use[N];
vector<int> v1,v2,ans;

int gla(int l)
{
    if (l==gl[l]) return l;
    return gl[l]=gla(gl[l]);
}

void dfs(int l, int p)
{
    use[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j],1-p);
    if (p==0) v1.pb(l); else v2.pb(l);
}

void up()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        v[i].clear();
        kol[i]=0;
        use[i]=0;
    }
    ans.clear();
    v1.clear();
    v2.clear();
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    if (v1.size()<v2.size()) ans=v1; else ans=v2;

    cout<<ans.size()<<"\n";
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}