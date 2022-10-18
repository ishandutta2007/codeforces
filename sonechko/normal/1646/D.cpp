#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 11;

vector<int> v[N];
int dp[N][2],c[N][2];
int res[N];

void dfs(int x, int l)
{
    for (int i=0; i<v[x].size(); i++)
        if (v[x][i]!=l) dfs(v[x][i],x);
    dp[x][0]=1;
    c[x][0]=0;
    for (int i=0; i<v[x].size(); i++)
        if (v[x][i]!=l)
    {
        int to=v[x][i];
        if (c[to][0]>c[to][1] || (c[to][0]==c[to][1]&&dp[to][0]<dp[to][1]+1))
            {
                dp[x][0]+=dp[to][0];
                c[x][0]+=c[to][0];
            } else
            {
                dp[x][0]+=dp[to][1]+1;
                c[x][0]+=c[to][1];
            }
    }
    dp[x][1]=0;
    c[x][1]=1;
    for (int i=0; i<v[x].size(); i++)
        if (v[x][i]!=l)
    {
        int to=v[x][i];
        dp[x][1]+=dp[to][0]+1;
        c[x][1]+=c[to][0];
    }
}

void rec(int x, int tp, int l)
{
    if (tp==1) res[x]=v[x].size(); else res[x]=1;
    for (int i=0; i<v[x].size(); i++)
        if (v[x][i]!=l)
    {
        int to=v[x][i];
        if (tp==1) rec(to,0,x);
        if (tp==0)
        {
            if (c[to][0]>c[to][1] || (c[to][0]==c[to][1]&&dp[to][0]<dp[to][1]+1))
                rec(to,0,x);
            else rec(to,1,x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    if (n==2)
    {
        cout<<2<<" "<<2<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    dfs(1,0);
    int ans=max(c[1][0],c[1][1]);
    int d=0;
    if (c[1][0]>c[1][1] || (c[1][0]==c[1][1]&&dp[1][0]<dp[1][1])) d=0; else d=1;
    cout<<c[1][d]<<" "<<dp[1][d]<<endl;
    rec(1,d,0);
    for (int i=1; i<=n; i++)
        cout<<res[i]<<" ";
    cout<<endl;
}