#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k[3000];
ll c[3000];
pair<ll,pair<int,int> > E[6000000];
vector<pair<int,int> > ret;
int par[1000000];
int sz[1000000];
int get(int v) {
    if (par[v]==v)return v;
    return par[v]=get(par[v]);
}
ll ans=0;
void Merge(ll c,int u,int v){
    int U=u,V=v;
    u = get(u);
    v = get(v);
    if (u==v)return;
    ans+=c;
    ret.push_back({U,V});
    if (sz[u]<sz[v]) {
        sz[v]+=sz[u];
        par[u]=v;
    } else {
        sz[u]+=sz[v];
        par[v]=u;
    }
}
ll x[10000],y[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++)
        cin>>c[i];
    for (int i=1;i<=n;i++)
        cin>>k[i];
    for (int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    int tot=0;
    for (int i=1;i<=n;i++){
        E[tot++]={c[i],{0,i}};
        for (int j=i+1;j<=n;j++) {
            ll cost = (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            E[tot++]={cost,{i,j}};
        }
    }
    sort(E,E+tot);
    for (int i=0;i<tot;i++){
        Merge(E[i].first,E[i].second.first,E[i].second.second);
    }
    vector<int> chosen;
    vector<pair<int,int> > edges;
    for (auto e:ret) {
        if (e.first>e.second)swap(e.first,e.second);
        if (e.first == 0) chosen.push_back(e.second);
        else edges.push_back(e);
    }
    cout<<ans<<endl;
    cout<<chosen.size()<<endl;
    for (auto x:chosen)cout<<x<<' ';
    cout<<endl;
    cout<<edges.size()<<endl;
    for (auto e:edges){
        cout<<e.first<<' '<<e.second<<'\n';
    }
}