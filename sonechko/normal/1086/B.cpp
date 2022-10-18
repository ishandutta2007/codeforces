#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 11;

vector<int> v[N];
int dp[N],ans;

void dfs(int l, int pr)
{
    //cout<<"?"<<l<<" "<<pr<<endl;
    dp[l]=-1;
    int k=1;
    if (pr!=0) k=2;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs(v[l][j],l);
        //cout<<dp[v[l][j]]<<"+"<<v[l].size()<<"-"<<k<<">"<<dp[l]<<endl;
        if (dp[v[l][j]]+(int)v[l].size()-k>dp[l])
        {
            dp[l]=dp[v[l][j]]+(int)v[l].size()-k;
        }
    }
    //cout<<l<<" - "<<dp[l]<<endl;
    if (dp[l]==-1)
    {
        dp[l]=0;
    }
}

void dfs2(int l, int pr)
{
    int res1=-1,res2=-1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs2(v[l][j],l);
        if (dp[v[l][j]]>res1)
        {
            res2=res1;
            res1=dp[v[l][j]];
        } else
        if (dp[v[l][j]]>res2) res2=dp[v[l][j]];
    }
    if (res2!=-1) ans=max(ans,res1+res2+(int)v[l].size()-2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ld m;
    cin>>n>>m;
    cout.precision(10);
    cout<<fixed;
    for (int i=1; i<n; i++)
    {
        int l,r;

        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int p=0;
    for (int i=1; i<=n; i++)
        if ((int)v[i].size()==1) p++;
    ld ans=m/(ld)p;
    cout<<ans*(ld)2<<endl;
}