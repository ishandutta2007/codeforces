#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define zero first
#define one second
int p[1000000];
vector<int> adj[1000000];

int mod = 1000000007;
pair<ll,ll> ret[1000000];
pair<ll,ll> Merge(pair<ll,ll> P,pair<ll,ll> S){
    if (P.zero==-1)return S;
    if (S.zero==-1)return P;
    pair<ll,ll> ans;
    ans.one = (((P.one+P.zero)%mod)*((S.zero+S.one)%mod) + P.one*S.zero)%mod;
    ans.zero = (P.zero*S.zero)%mod;
    return ans;
}
vector<pair<ll,ll> > pre[1000000];
vector<pair<ll,ll> > suf[1000000];
void dfs(int v){
    pre[v].resize(adj[v].size()+1);
    suf[v].resize(adj[v].size()+1);
    pre[v][0]={1,0};
    for (int i=0;i<adj[v].size();i++){
        int u=adj[v][i];
        dfs(u);
        pre[v][i+1]=Merge(pre[v][i], pre[u][adj[u].size()]);
    }
    suf[v][adj[v].size()]={1,0};
    for (int i=(int)adj[v].size()-1;i>=0;i--){
        int u = adj[v][i];
        suf[v][i]=Merge(suf[v][i+1],pre[u][adj[u].size()]);
    }
}
void RocketTransition(int v, pair<ll,ll> rocket){
    ret[v] = Merge(pre[v][adj[v].size()], rocket);
    for (int i=0;i<adj[v].size();i++){
        int u=adj[v][i];
        pair<ll,ll> newRocket = pre[v][i];
        newRocket.zero = (newRocket.zero*suf[v][i+1].zero)%mod;
        newRocket.one = (newRocket.one*(suf[v][i+1].one+suf[v][i+1].zero)+newRocket.zero*suf[v][i+1].one)%mod;
        RocketTransition(u, Merge(newRocket, rocket));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)cin>>p[i],adj[p[i]].push_back(i);
    dfs(1);
    RocketTransition(1, {-1,-1});
    for (int i=1;i<=n;i++){
        ll cur = ret[i].first+ret[i].second;
        cur%=mod;
        cout<<cur<<' ';
    }
}