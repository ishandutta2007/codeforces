#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second
const ll N = 1e6 + 11;

int dd[N][26],use[N],res;
string s;
vector<int> v[N];

void dfs(int l)
{
    use[l]=1;
    dd[l][s[l]-'a']=1;
    for (int i=0; i<v[l].size(); i++)
        if (use[v[l][i]]==1)
    {
        cout<<"-1"<<endl;
        exit(0);
    } else
    if (use[v[l][i]]==0)
    {
        dfs(v[l][i]);
        for (int p=0; p<26; p++)
            dd[l][p]=max(dd[l][p],
                dd[v[l][i]][p]+(s[l]-'a'==p));
    } else
    {
        for (int p=0; p<26; p++)
            dd[l][p]=max(dd[l][p],
                dd[v[l][i]][p]+(s[l]-'a'==p));
    }
    for (int p=0; p<26; p++)
        res=max(res,dd[l][p]);
    use[l]=2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>s;
    s="."+s;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
    }
    for (int i=1; i<=n; i++)
    if (use[i]==0) dfs(i);
    cout<<res<<endl;
}