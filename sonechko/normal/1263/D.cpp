#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const int N = 2e5 + 11;

int d[N][27];
vector<int> v[27];
int cs[27];
int use[N];

void dfs(int l)
{
    use[l]=1;
    for (int p=0; p<27; p++)
        if (d[l][p]&&cs[p]==0)
    {
        cs[p]=1;
        for (int j=0; j<v[p].size(); j++)
            if (use[v[p][j]]==0) dfs(v[p][j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<s.size(); j++)
            if (d[i][s[j]-'a']==0) {d[i][s[j]-'a']=1; v[s[j]-'a'].pb(i);}
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0) {dfs(i); ans++;}
    cout<<ans;
}