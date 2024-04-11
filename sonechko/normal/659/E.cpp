#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e5 + 11;

int kol_ver,kol_reb;
int use[N];
vector<int> v[N];

void dfs(int l, int x)
{
    kol_ver++;
    use[l]=x;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==x) kol_reb++; else
    if (use[v[l][j]]==0) {kol_reb++; dfs(v[l][j],x);}
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
        v[l].pb(r);
        v[r].pb(l);
    }
    int ans=0,x=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
            {
                kol_ver=0;
                kol_reb=0;
                x++;
                dfs(i,x);
                if (kol_reb==(kol_ver-1)*2) ans++;
            }
    cout<<ans<<endl;
}