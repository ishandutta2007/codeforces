#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;
const int MOD = 1e9 + 7;

vector<int> v[N];
bool bad[N][N];
bool use[N];
vector<int> vv;
int g=0;

void dfs(int l)
{
    use[l]=1;
    vv.pb(l);
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j]); else
        if (use[v[l][j]]==2) g=1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        bad[l][r]=1;
        bad[r][l]=1;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        g=0;
        vv.clear();
        dfs(i);
        for (int j=0; j<vv.size(); j++)
        for (int t=0; t<vv.size(); t++)
        if (bad[vv[j]][vv[t]]) g=1;
        if (g==0) ans=max(ans,(int)vv.size());
    }
    cout<<ans<<endl;
}