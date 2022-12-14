#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > add[100005];
vector<pair<int,int> > rem[100005];
multiset<pair<int,int> > s;
pair<int,int> best[100001];
long long dp[100005][201];
int n,m,k;
long long sol(int i,int j)
{
    if (j>m)return 1e16;
    if (i>n)return 0;
    if (dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=min(best[i].first+sol(best[i].second,j),sol(i+1,j+1));
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for (int i=0;i<k;i++)
    {
        int s,t,d,w;
        cin>>s>>t>>d>>w;
        add[s].push_back({w,d});
        rem[t+1].push_back({w,d});
    }
    for (int i=1;i<=n;i++)
    {
        for (auto x:add[i])s.insert(x);
        for (auto x:rem[i])s.erase(s.find(x));
        if (s.empty())best[i]={0,i+1};
        else
        {
            pair<int,int> b = *s.rbegin();
            best[i]={b.first,b.second+1};
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            dp[i][j]=-1;
    cout<<sol(1,0)<<endl;
}