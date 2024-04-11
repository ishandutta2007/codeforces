#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1000000];
long long fact[1000000];
long long mod = 998244353;
long long ret[1000000];
long long ans=1;
long long P(long long a,long long b) {
    if (b==0)return 1;
    long long x = P(a,b/2);
    x = (x*x)%mod;
    if(b%2)x = (x*a)%mod;
    return x;
}
long long inv(long long x) {
    return P(x,mod-2);
}
void dfs(int v,int pa=-1) {
    int num = adj[v].size();
    if (pa!=-1)num--;
    if (pa!=-1)
        ret[v]=(fact[num] * (num+1LL))%mod;
    else
        ret[v]=fact[num];
    ans = (ans*ret[v])%mod;
    for (auto u:adj[v])
    {
        if (u==pa)continue;
        dfs(u,v);
    }
}
void dfs2(int v,int pa,int lev) {

    int num = adj[v].size();
    if (pa!=-1)num--;
    if (pa!=-1)
        ret[v]=(fact[num] * (num+1LL))%mod;
    else
        ret[v]=fact[num];
    if (lev==1)
        return;

    for (auto u:adj[v])
    {
        if (u==pa)continue;
        dfs2(u,v,lev+1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fact[0]=1;
    for (int i=1;i<=n;i++) {
        fact[i]=(fact[i-1]*i)%mod;
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    long long cur = ans;
    for (int i=2;i<=n;i++) {
        cur = (cur*inv(ret[i])) %mod;
        for (auto v:adj[i])
            cur = (cur*inv(ret[v]))%mod;
        dfs2(i,-1,0);
        cur = (cur*(ret[i])) %mod;
        for (auto v:adj[i])
            cur = (cur*(ret[v]))%mod;
        ans = (ans+cur)%mod;
    }
    cout<<ans<<endl;
}