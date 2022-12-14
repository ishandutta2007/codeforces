#include<bits/stdc++.h>
using namespace std;
#define ll long long
int comp[1000000];
ll tot;
ll L[1000000];
ll R[1000000];
ll comps;
vector<int> G[1000000];
void add(int u,int v){
    for (auto x:G[u]){
        G[v].push_back(x);
        comp[x]=v;
    }

    tot -= (R[v]-L[v]+1);
    tot -= (R[u]-L[u]+1);
    L[v]=min(L[v],L[u]);
    R[v]=max(R[v],R[u]);
    G[u].clear();
    comps--;
    tot+=(R[v]-L[v]+1);
}
void dsu(int u,int v){
    u = comp[u], v= comp[v];
    if (u==v)return;
    if (G[u].size()<G[v].size())add(u,v);
    else add(v,u);
}
ll a[1000000];
pair<ll,ll > Q[1000000];
ll ans[1000000];
vector<pair<ll,pair<int,int> > > E;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        G[i].push_back(i);
        comp[i]=i;
        L[i]=a[i];
        R[i]=a[i];
        tot++;
    }
    for (int i=2;i<=n;i++){
        E.push_back({a[i]-a[i-1], {i,i-1}});
    }
    sort(E.begin(),E.end());
    reverse(E.begin(),E.end());
    comps=n;
    int q;
    cin>>q;
    for (int i=1;i<=q;i++){
        ll l,r;
        cin>>l>>r;
        Q[i] = {r-l, i};
    }
    sort(Q+1,Q+q+1);
    for (int i=1;i<=q;i++) {
        ll len = Q[i].first;
        ll id = Q[i].second;
        while(E.size() && E.back().first<=len)dsu(E.back().second.first,E.back().second.second),E.pop_back();
        ans[id]=tot+len*comps;
    }
    for (int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
}