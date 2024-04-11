#include <bits/stdc++.h>
using namespace std;
long long V[1000000];
long long mod = 1000000007;
long long sum[1000000][2];
long long num[1000000][2];
long long cur[1000000][2];
vector<int> adj[1000000];
long long ret=0;
void dfs(int v,int p)
{
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (u==p)continue;
        dfs(u,v);
        cur[v][0]+=sum[u][0];
        cur[v][1]+=sum[u][1];
        cur[v][0]%=mod;
        cur[v][1]%=mod;
        sum[v][0]+=(sum[u][1]-(num[u][1]*V[v])%mod+mod+mod)%mod;
        sum[v][0]%=mod;
        num[v][0]+=num[u][0];
        num[v][1]+=num[u][1];
        sum[v][1]+=(sum[u][0]+(num[u][0]*V[v])%mod)%mod;
        sum[v][1]%=mod;
    }
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (u==p)continue;
        for (int j=0;j<2;j++){
            if (j==0)
                V[v]=-V[v];
            ret+=((-V[v]*((num[u][j]*(num[v][j]-num[u][j]))%mod)+mod)%mod);
            ret%=mod;
            ret+=(num[u][j]*((cur[v][j]-sum[u][j]+mod)%mod))%mod;
            ret%=mod;
            ret+=((num[v][j]-num[u][j])%mod)*(sum[u][j])%mod;
            ret%=mod;

            if (j==0)
                V[v]=-V[v];
        }
    }
    swap(num[v][0],num[v][1]);
    num[v][1]++;
    ret+=(sum[v][1]*2)%mod;
    sum[v][1]+=V[v]+mod;
    sum[v][1]%=mod;
    ret%=mod;
    ret+=(V[v]+mod);
    ret%=mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>V[i],V[i]+=mod,V[i]%=mod;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ret<<endl;
}