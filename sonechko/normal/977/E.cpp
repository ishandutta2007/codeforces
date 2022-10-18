#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ull unsigned long long

const int N = 2e6 + 11;

bool use[N];
vector<int> v[N];
int pp,gg;
vector<int> vv;

void dfs(int l)
{
    use[l]=1;
    vv.pb(l);
    if (v[l].size()!=2) pp=0;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]==0) dfs(v[l][j]);
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
    int ans=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
    {
        gg=i;
        pp=1;
        vv.clear();
        dfs(i);
        if (pp==1)
        {
            if (v[vv[0]][1]!=vv.back()&&v[vv[0]][0]!=vv.back()) pp=0;
            for (int j=1; j<vv.size()-1; j++)
            {
                if (v[vv[j]][0]!=vv[j-1]&&v[vv[j]][1]!=vv[j-1]) pp=0;
                if (v[vv[j]][0]!=vv[j+1]&&v[vv[j]][1]!=vv[j+1]) pp=0;
            }
        }
        if (pp==1) ans++;
    }
    cout<<ans<<endl;
}