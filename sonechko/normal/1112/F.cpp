#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 3e5 + 11;

int cost[N];
map<int,int> mt;
vector<int> vs[N];
vector<int> v[N];
int kol[N],prr[N];
ll dp[N][2];
bool use[N];



void dfs(int l, int pr)
{
    vector<int> vv;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) {dfs(v[l][j],l); vv.pb(v[l][j]);}
    if (vv.size()==0)
    {
        dp[l][0]=cost[l];
        dp[l][1]=0;
        return;
    }
    ll s1=0,s2=0;
    for (int j=0; j<vv.size(); j++)
        s1+=dp[vv[j]][0];
    s2=s1;
    for (int j=0; j<vv.size(); j++)
        s2=min(s2,s1-dp[vv[j]][0]+dp[vv[j]][1]);
    dp[l][0]=min(s1,s2+cost[l]);
    dp[l][1]=s2;
}


void dfss(int l, int pr, int k0, int k1)
{
    vector<int> vv,v0,v1;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) {vv.pb(v[l][j]); v0.pb(0); v1.pb(0);}
    ll s1=0,s2=0;
    for (int j=0; j<vv.size(); j++)
        s1+=dp[vv[j]][0];
    if (vv.size()==0)
    {
        if (k0==1) use[l]=1;
        return;
    }
    if (k0==1)
    {
        if (s1==dp[l][0])
        {
            for (int j=0; j<vv.size(); j++)
                v0[j]=1;
        }
        int t=0;
        for (int j=0; j<vv.size(); j++)
            if (s1-dp[vv[j]][0]+dp[vv[j]][1]+cost[l]==dp[l][0])
        {
            use[l]=1;
            v1[j]=1;
            t++;
            if (t<=3)
            {
                for (int jj=0; jj<vv.size(); jj++)
                    if (jj!=j) v0[jj]=1;
            }
        }
    }
    if (k1==1)
    {
        int t=0;
        for (int j=0; j<vv.size(); j++)
        if (s1-dp[vv[j]][0]+dp[vv[j]][1]==dp[l][1])
        {
            v1[j]=1;
            t++;
            if (t<=3)
            {
                for (int jj=0; jj<vv.size(); jj++)
                    if (jj!=j) v0[jj]=1;
            }
        }
    }
    for(int j=0; j<vv.size(); j++)
        dfss(vv[j],l,v0[j],v1[j]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int> vv;
    for (int i=1; i<=n; i++)
    {
        cin>>cost[i];
    }
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    dfss(1,0,1,0);
    vector<int> ans;
    ///for (int i=1; i<=n; i++)
    ///    cout<<i<<" - "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    for (int i=1; i<=n; i++)
        if (use[i]==1) ans.pb(i);
    cout<<dp[1][0]<<" "<<ans.size()<<endl;
    for (int j=0; j<ans.size(); j++)
        cout<<ans[j]<<" ";
    cout<<endl;
}
/**
6
2 3 1 2 3 4
1 2
2 3
2 4
2 5
2 6
**/