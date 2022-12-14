#include<bits/stdc++.h>
using namespace std;
long long a[5001];
long long dp[5001][5001];
deque<int> q;
int cur = -1;
void init()
{
    cur++;
    while(!q.empty())q.clear();
    q.push_back(0);
}
void add(int i)
{
    while(!q.empty() && dp[cur][q.back()]<dp[cur][i])q.pop_back();
    q.push_back(i);
}
    int n,k,x;
long long get(int i)
{
    int mn = i-k;
    while(!q.empty() && q.front()<mn)q.pop_front();
    if (!q.empty())return dp[cur][q.front()];
    return -1e15;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>x;
    for (int i=1;i<=n;i++)
        cin>>a[i],dp[0][i]=-1e15,dp[i][0]=-1e15;
    dp[0][0]=0;
    long long ret=-1;
    for (int i=1;i<=x;i++)
    {
        init();
        for (int j=1;j<=n;j++)
        {
            add(j-1);
            dp[i][j]=get(j)+a[j];
            if (i==x && n-j<k)ret=max(ret,dp[i][j]);
        }
    }
    cout<<ret<<endl;
}