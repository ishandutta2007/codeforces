#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD

vector<int> v[N];

bool good[N];
int use[N];

void up(int l)
{
    good[l]=1;
    for (int j=0; j<v[l].size(); j++)
        if (good[v[l][j]]==0) up(v[l][j]);
}
int dfs(int l, int ps)
{
    int c=0;
    if (good[l]==0) c++;
    use[l]=ps;
    for (int j=0; j<v[l].size(); j++)
        if (use[v[l][j]]<ps) c+=dfs(v[l][j],ps);
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
    }
    up(t);
    int pp=1;
    vector<pair<int,int> > vv;
    for (int i=1; i<=n; i++)
        if (good[i]==0)
    {
        pp++;
        vv.pb(mp(dfs(i,pp),i));
    }
    int ans=0;
    sort(vv.begin(),vv.end());
    for (int j=vv.size()-1; j>=0; j--)
    if (good[vv[j].ss]==0) {ans++; up(vv[j].ss);}
    cout<<ans<<endl;

}