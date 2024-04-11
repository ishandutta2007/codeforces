#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

vector<int> v[N][3];
int use[N][3];

void dfs(int l, int r)
{
    use[l][r]=1;
    for (int j=0; j<v[l][r].size(); j++)
        if (use[v[l][r][j]][3-r]==0) dfs(v[l][r][j],3-r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1; i<=q; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l][1].pb(r);
        v[r][2].pb(l);
    }
    int ans=-1;
    for (int i=1; i<=n; i++)
        if (use[i][1]==0) {ans++; dfs(i,1);}
    for (int j=1; j<=m; j++)
        if (use[j][2]==0) {ans++; dfs(j,2);}
    cout<<ans<<endl;
}